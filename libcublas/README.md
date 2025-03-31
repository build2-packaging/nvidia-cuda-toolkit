# libcublas - A C library

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
depends: libcublas ^12.8.0
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
