# Maintaining these packages

All seven packages are the same package with different data. The buildfile
comments carry the details at the point of use.

## What a package is

Per package:

    <pkg>/manifest.json   which NVIDIA component to fetch, per platform
    <pkg>/package.json    which extracted files become which targets
    <pkg>/buildfile       the loop that turns package.json into targets
    build/root.build      the cache configuration variable

`redist.build` at the root holds the fetch and extract machinery, symlinked
into every package and sourced by its buildfile. Nothing is compiled:

    json{<name>-manifest}   fetch redistrib_X.Y.Z.json from redistUrl
    archive{...}            download the platform tarball into the cache
    extract{...}            untar into $out_base, discovering the files
    lib{} exe{} file{}      stamp those files as targets

`manifest.json`: `redistUrl`, `includeDirs` (the public include roots), and
per platform `component`, `platform` and `version`.

`package.json`: per platform a `libs` and an `exes` object. Per library,

    linkage     shared, static or binless, see below
    linked      a DLL together with its link-time file
    shared      a shared object linked directly
    archives    static archives, this library's own one first
    runtime     loaded at run time, never linked
    resources   data files installed verbatim where upstream expects them
    depends     another library in this same package

and per executable `path` and `depends`. Both platform sections are always
declared and gated with `include =`, so the build graph is the same in every
configuration.

## Add a new package

1. Copy an existing package directory and rename throughout. For the canonical
   component name see the `redistrib_X.Y.Z.json` files
   [here](https://developer.download.nvidia.com/compute/cuda/redist/). Check
   the `name = $string.replace($project, ...)` line: `cuda-*` packages strip
   `cuda-`, `lib*` packages strip `lib`.
2. Write `manifest.json` and `package.json` for the component.
3. `bdep init`, then `bdep update`. A version mismatch means the `version` in
   `manifest.json` disagrees with the remote entry. Fix it there, then set
   `upstream-version` in `manifest` to match.
4. Check that every extracted file under `out_base` that should ship is named
   in `package.json`.

## Cache directory

Tarballs land in `$out_root` by default. Only a symlink to the tarball is a
target, so `b clean` leaves the cache alone. Set `config.<pkg>.cache` for one
package or `config.cuda.cache` for all, the per-package value wins. The
variable name comes from the package name, so `cuda-nvcc` uses
`config.cuda_nvcc.cache`.

    b "config.cuda_nvcc.cache=/path/to/cache"

`config.cuda.cache` is read at configure time into each per-package value, so
changing it afterwards needs a reconfigure.

## Library linkage

`linkage` says what the binary installed under that library's name actually
is, and picks the aggregate target `libs{}`, `liba{}` or `lib{}`. It is not
derivable from the file name: NVIDIA ships both real import libraries and
static archives of loader shims as `lib/<name>.lib`. Look inside:

    lib /list <file>.lib

`.dll` members mean `shared`, `.obj` members mean `static`, even when the
archive only `LoadLibrary`s a DLL. build2 applies the same test to the
installed file (`cc/msvc.cxx`, `library_type()`), so the two have to agree. As
of 13.3.1 only `cudart`, `cudadevrt` and `cuda` are static.

Disagree and consuming an installed prefix fails with `dependency cycle
detected`, far from the cause. A DLL whose link-time file is a shim archive
still belongs in `linked`. A stray `*-unused.*.pc` is inert and expected.

## Testing

Two scripts at the repository root, each documented in its own header:

    bx test-install.bx <scratch-dir>   all packages into one prefix
    bx test-dist.bx <scratch-dir>      each package from its own distribution

Run both on every target platform before publishing.
