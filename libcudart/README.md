# libcudart - A C library

> **NOTE:**  
This package is not open source and does not contain any source code. Instead,
in order to "build" the exported target(s) it downloads (potentially large)
pre-built binaries provided by NVIDIA for the target platform.
>
> CI for this package is disabled due to the above.  
Supported platforms/compilers are Windows/MSVC. Linux binaries exist but are
currently not available through this package.

The CUDA Runtime Library (cudart) provides a high-level API for CUDA
programming, simplifying memory management, kernel launches, and GPU
operations. It abstracts the complexities of the CUDA Driver API,
offering an easier interface for developers to write CUDA applications
in both C and C++. The cudart library is essential for leveraging
NVIDIA GPUs for general-purpose computing, enabling efficient
execution of parallel algorithms.

## Usage

To start using `libcudart` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libcudart ^12.8.0
```

Then import the library in your `buildfile`:

```
import libs = libcudart%libs{cudart}
```


## Importable targets

This package provides the following importable targets:

```
libs{cudart}
```
