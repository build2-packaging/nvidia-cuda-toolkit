# NVIDIA® CUDA® Toolkit Development Environment

> **NOTE:**  
These packages are not open source and do not contain any source code. Instead,
in order to "build" the exported target(s) they download (potentially large)
pre-built binaries provided by NVIDIA for the target platform.
>
> CI for these packages are disabled due to the above.  
Supported platforms/compilers are Windows/MSVC. Linux binaries exist but are
currently not available through these packages.

This is a `build2` package repository for [NVIDIA® CUDA® Toolkit](https://developer.nvidia.com/cuda-toolkit).
Note that it currently does not contain all of the packages.

The NVIDIA® CUDA® Toolkit provides a development environment for creating
high-performance, GPU-accelerated applications. With it, you can develop,
optimize, and deploy your applications on GPU-accelerated embedded systems,
desktop workstations, enterprise data centers, cloud-based platforms, and
supercomputers. The toolkit includes GPU-accelerated libraries, debugging
and optimization tools, a C/C++ compiler, and a runtime library.

This file contains setup instructions and other details that are more
appropriate for package development rather than consumption. If you want to use
`nvidia-cuda-toolkit` in your `build2`-based project, then instead see the accompanying
package(s) corresponding [`README.md`](cuda-cudart/README.md) file.

The development setup for `nvidia-cuda-toolkit` uses the standard `bdep`-based workflow.
For example:

```
git clone https://github.com/build2-packaging/nvidia-cuda-toolkit
cd nvidia-cuda-toolkit

bdep init -C @msvc c config.c=cl.exe
bdep update
bdep test
```
