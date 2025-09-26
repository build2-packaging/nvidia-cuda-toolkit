# libcublas - A C library

> **NOTE:**  
This package is not open source and does not contain any source code. Instead,
in order to "build" the exported target(s) it downloads (potentially large)
pre-built binaries provided by NVIDIA for the target platform.
>
> CI for this package is disabled due to the above.  
Supported platforms/compilers are Windows/MSVC. Linux binaries exist but are
currently not available through this package.

NVIDIA cuBLAS is a GPU-accelerated library for accelerating AI and HPC applications.
It includes several API extensions for providing drop-in industry standard BLAS APIs
and GEMM APIs with support for fusions that are highly optimized for NVIDIA GPUs.
The cuBLAS library also contains extensions for batched operations, execution across
multiple GPUs, and mixed- and low-precision execution with additional tuning for the
best performance.

## Usage

To start using `libcublas` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libcublas ^13.0.1
```

Then import the library in your `buildfile`:

```
import libs = libcublas%libs{cublas}
```


## Importable targets

This package provides the following importable targets:

```
libs{cublas}
```
