# libnvvm - A C library

> **NOTE:**  
This package is not open source and does not contain any source code. Instead,
in order to "build" the exported target(s) it downloads (potentially large)
pre-built binaries provided by NVIDIA for the target platform.
>
> CI for this package is disabled due to the above.  
Supported platforms/compilers are Windows/MSVC. Linux binaries exist but are
currently not available through this package.

NVVM IR is a compiler IR (intermediate representation) based on the LLVM IR.
The NVVM IR is designed to represent GPU compute kernels (for example, CUDA
kernels). High-level language front-ends, like the CUDA C compiler front-end,
can generate NVVM IR. The NVVM compiler (which is based on LLVM) generates
PTX code from NVVM IR.

## Usage

To start using `libnvvm` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnvvm ^12.8.0
```

Then import the library in your `buildfile`:

```
import libs = libnvvm%libs{nvvm}
```


## Importable targets

This package provides the following importable targets:

```
libs{nvvm}
exe{cicc}
```
