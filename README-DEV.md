# Add new package
1. Copy-paste one of the existing package directories and
   update names accordingly. For canonical names see the
   corresponding `redistrib_X.Y.Z.json` [here](https://developer.download.nvidia.com/compute/cuda/redist/).
2. Initialize package (`bdep init`) and build (`bdep update`).
   If `redist.build` complains about version-mismatch (local
   vs remote), update `upstream-version` in `manifest`.
3. Verify that the extracted targets in `out_base` are all
   accounted for (eg. all executables & libraries).
