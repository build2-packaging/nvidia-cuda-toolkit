# libcudart - A C library

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
depends: libcudart ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libcudart%lib{cudart}
```


## Importable targets

This package provides the following importable targets:

```
lib{cudart}
```
