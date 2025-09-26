# cuda-cccl - A C++ library

> **NOTE:**  
This package is not open source and does not contain any source code. Instead,
in order to "build" the exported target(s) it downloads (potentially large)
pre-built binaries provided by NVIDIA for the target platform.
>
> CI for this package is disabled due to the above.  
Supported platforms/compilers are Windows/MSVC. Linux binaries exist but are
currently not available through this package.

The goal of CCCL is to provide CUDA C++ developers with building blocks
that make it easier to write safe and efficient code. Bringing these
libraries together streamlines your development process and broadens
your ability to leverage the power of CUDA C++.


## Usage

To start using `cuda-cccl` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: cuda-cccl ^12.8.0
```

Then import the library in your `buildfile`:

```
import libs = cuda-cccl%lib{cccl}
```


## Importable targets

This package provides the following importable targets:

```
lib{cccl}
```
