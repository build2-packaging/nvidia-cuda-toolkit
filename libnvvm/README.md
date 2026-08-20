# libnvvm - A C library

> **NOTE:**  
> This package is not open source and does not contain any source code. Instead,
> in order to "build" the exported target(s) it downloads (potentially large)
> pre-built binaries provided by Intel for the target platform.
>
> CI for this package is disabled due to the above.
> Supported platforms/compilers are Windows/MSVC and Linux.

NVVM IR is a compiler IR (intermediate representation) based on the LLVM IR.
The NVVM IR is designed to represent GPU compute kernels (for example, CUDA
kernels). High-level language front-ends, like the CUDA C compiler front-end,
can generate NVVM IR. The NVVM compiler (which is based on LLVM) generates
PTX code from NVVM IR.

## Usage

To start using `libnvvm` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnvvm ^13.0.1
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


## Configuration variables

This package provides the following configuration variables:

```
[dir_path] config.libnvvm.cache ?= $out_root
```

The directory used to cache downloaded binary archives between builds. If
`config.cuda.cache` is set (a shared project-wide cache directory), it
takes precedence over the per-package default of `$out_root`.
