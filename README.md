# cuda-toolkit2 - <SUMMARY>

`cuda-toolkit2` is a <SUMMARY-OF-FUNCTIONALITY>.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`cuda-toolkit2` in your `build2`-based project, then instead see the accompanying
package [`README.md`](<PACKAGE>/README.md) file.

The development setup for `cuda-toolkit2` uses the standard `bdep`-based workflow.
For example:

```
git clone .../cuda-toolkit2.git
cd cuda-toolkit2

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
