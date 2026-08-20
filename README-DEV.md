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
