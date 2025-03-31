# NVIDIA® CUDA® Toolkit Development Environment

The NVIDIA® CUDA® Toolkit provides a development environment for creating high-performance,
GPU-accelerated applications. With it, you can develop, optimize, and deploy your applications
on GPU-accelerated embedded systems, desktop workstations, enterprise data centers,
cloud-based platforms, and supercomputers. The toolkit includes GPU-accelerated libraries,
debugging and optimization tools, a C/C++ compiler, and a runtime library.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`nvidia-cuda-toolkit` in your `build2`-based project, then instead see the accompanying
package(s) corresponding [`README.md`](libcudart/README.md) file.

The development setup for `nvidia-cuda-toolkit` uses the standard `bdep`-based workflow.
For example:

```
git clone https://github.com/build2-packaging/nvidia-cuda-toolkit
cd nvidia-cuda-toolkit
git submodule update --init

bdep init -C @msvc c config.c=cl.exe
bdep update
bdep test
```
