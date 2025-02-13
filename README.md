# nvidia-cuda-toolkit - <SUMMARY>

`nvidia-cuda-toolkit` is a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`nvidia-cuda-toolkit` in your `build2`-based project, then instead see the accompanying
package [`README.md`](<PACKAGE>/README.md) file.

The development setup for `nvidia-cuda-toolkit` uses the standard `bdep`-based workflow.
For example:

```
git clone .../nvidia-cuda-toolkit.git
cd nvidia-cuda-toolkit

bdep init -C @msvc c config.c=cl.exe
bdep update
bdep test
```
