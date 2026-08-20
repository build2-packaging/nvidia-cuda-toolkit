# cuda-cudart - A C library

> **NOTE:**  
> This package is not open source and does not contain any source code. Instead,
> in order to "build" the exported target(s) it downloads (potentially large)
> pre-built binaries provided by Intel for the target platform.
>
> CI for this package is disabled due to the above.
> Supported platforms/compilers are Windows/MSVC and Linux.

The CUDA Runtime Library (cudart) provides a high-level API for CUDA
programming, simplifying memory management, kernel launches, and GPU
operations. It abstracts the complexities of the CUDA Driver API,
offering an easier interface for developers to write CUDA applications
in both C and C++. The cudart library is essential for leveraging
NVIDIA GPUs for general-purpose computing, enabling efficient
execution of parallel algorithms.

## Usage

To start using `cuda-cudart` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: cuda-cudart ^13.0.1
```

Then import the library in your `buildfile`:

```
import libs = cuda-cudart%libs{cudart}
```


## Importable targets

This package provides the following importable targets:

```
libs{cudart}
```


## Configuration variables

This package provides the following configuration variables:

```
[dir_path] config.cuda_cudart.cache ?= $out_root
```

The directory used to cache downloaded binary archives between builds. If
`config.cuda.cache` is set (a shared project-wide cache directory), it
takes precedence over the per-package default of `$out_root`.
