# Add new package
1. Copy-paste one of the existing package directories and
   update names accordingly. For canonical names see the
   corresponding `redistrib_X.Y.Z.json` [here](https://developer.download.nvidia.com/compute/cuda/redist/).
2. Initialize package (`bdep init`) and build (`bdep update`).
   If `redist.build` complains about version-mismatch (local
   vs remote), update `upstream-version` in `manifest`.
3. Verify that the extracted targets in `out_base` are all
   accounted for (eg. all executables & libraries).

## Cache directory

Downloaded archives are placed in `$out_root` by default. They are not
registered as build2 targets, so `bdep clean` leaves them untouched. Set
one of the two `dir_path` variables below to redirect them to a different
location (for example, a directory shared across multiple build configurations):

  Variable                        Scope
  --------                        -----
  config.cuda.cache               global: applies to all packages when set
  config.<pkg>.cache              per-package: overrides the global value

Resolution order (evaluated in `root.build` for each package):

  1. `config.<pkg>.cache` if explicitly set, otherwise
  2. `config.cuda.cache` if explicitly set, otherwise
  3. `$out_root` (the package output directory)

The per-package variable uses the package name with hyphens replaced by
underscores. For example, `cuda-nvcc` uses `config.cuda_nvcc.cache`.

Set the global variable once to share a cache across all packages:

  bdep init -C @gcc cc config.c=gcc \
    "config.cuda.cache=/path/to/cache-dir"

Or override a single package:

  b "config.cuda_nvcc.cache=/path/to/nvcc-cache-dir"

## Library linkage in `package.json`

Every library in `package.json` declares a `"linkage"`: `shared`, `static`, or
`binless` for a package that ships no binaries. It selects the aggregate
target (`libs{}`, `liba{}` or `lib{}`), and it has to describe the binary that
is actually installed under that library's name.

This is not derivable from the file names. NVIDIA ships both real import
libraries and static archives of loader shims as `lib/<name>.lib`. Classify by
looking inside:

    lib /list <file>.lib

`.dll` members mean a real import library, so `"linkage": "shared"`. `.obj`
members mean a static archive, so `"linkage": "static"`, even when a DLL is
loaded at run time and the archive is only a stub that `LoadLibrary`s it. As
of 13.3.1, `cudart.lib`, `cudadevrt.lib` and `cuda.lib` are static archives
while `nvrtc.lib`, `cublas.lib`, `cublasLt.lib`, `nvblas.lib` and `nvvm.lib`
are import libraries.

Get it wrong and the failure is remote from the cause. build2 performs the
same classification on the installed file (`cc/msvc.cxx`, `library_type()`),
and if its answer differs from the variant declared here it manufactures a
binless placeholder for the variant it cannot find. That switches off the
positional self `-l` skip when the generated `pc` file is loaded, so the
library resolves its own `-l` back to itself and the consumer fails with
`dependency cycle detected`. Nothing is wrong when building against a `bpkg`
configuration, only when consuming an installed prefix. If build2 cannot
classify the archive at all it warns about a hybrid or empty one, and the same
failure returns.

Note that a DLL whose link-time file is a static shim archive still belongs in
`linked`, paired with that archive. `linked` says which file goes on the link
line for a DLL, which is exactly what the shim archive is for. Moving it to
`archives` and the DLL to `runtime` leaves the DLL with no link-time file, and
it is then written into the generated `pc` file as an unresolvable
`-l<dll name>`.

Two further constraints:

- A library's own archive has to be first in `archives`. build2 identifies the
  library's own entry in the generated `pc` file by position, the first `-l` in
  `Libs`, so a different entry first would be swallowed instead. The `linked`
  and `shared` loops prepend, so this only binds a library that has neither,
  and the buildfiles assert it.
- Linux `lib/stubs/libcuda.so` is listed under `archives` although it is a
  shared object. That is deliberate: it is a link-time stub whose real driver
  is loaded from the system, and it must not reach consumers as a shared
  library. It is an exported member rather than an aggregate, so it does not
  affect which `pc` file is generated.

### The variant that does not match

An importer picks which member of the `lib{}` group it links against from its
own `config.bin.lib`, which defaults to `both` and prefers shared. So the
variant that does not match the installed binary still gets built, and
installed, by anyone who depends on the package. Its `pc` file would then sit
next to the right one in a shared prefix and bring the self-reference back,
which is what happens when `libcublas` is installed alongside `cuda-cudart`.

The buildfiles therefore give that member a `bin.lib.suffix`, so it installs
as `libcudart-unused.shared.pc`, a name no probe looks for. For a binless
member the suffix feeds nothing but the `pc` file name, since there is no
binary of its own, so the library stays fully installable and linkable. A
stray `*-unused.*.pc` in a prefix is inert and expected.

Do not suppress the member with `install = false` instead. It keeps the prefix
correct, but a consumer that installs its dependencies as a side effect then
gets no cuda libraries at all, because the suppressed member is exactly the
one its `bin.lib` selects.
