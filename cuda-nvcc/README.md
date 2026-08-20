# cuda-nvcc - A C library

> **NOTE:**  
> This package is not open source and does not contain any source code. Instead,
> in order to "build" the exported target(s) it downloads (potentially large)
> pre-built binaries provided by Intel for the target platform.
>
> CI for this package is disabled due to the above.
> Supported platforms/compilers are Windows/MSVC and Linux.

The compilation trajectory involves several splitting, compilation,
preprocessing, and merging steps for each CUDA source file. It is
the purpose of nvcc, the CUDA compiler driver, to hide the intricate
details of CUDA compilation from developers. It accepts a range of
conventional compiler options, such as for defining macros and
include/library paths, and for steering the compilation process. All
non-CUDA compilation steps are forwarded to a C++ host compiler that
is supported by nvcc, and nvcc translates its options to appropriate
host compiler command line options.

## Usage

To start using `cuda-nvcc` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: cuda-nvcc ^13.0.1
```

Then import the library in your `buildfile`:

```
import libs = cuda-nvcc%lib{nvcc}
```


## Importable targets

This package provides the following importable targets:

```
lib{nvcc}
exe{bin2c}
exe{cudafe++}
exe{fatbinary}
exe{nvcc}
exe{nvlink}
exe{ptxas}
```


## Configuration variables

This package provides the following configuration variables:

```
[dir_path] config.cuda_nvcc.cache ?= $out_root
```

The directory used to cache downloaded binary archives between builds. If
`config.cuda.cache` is set (a shared project-wide cache directory), it
takes precedence over the per-package default of `$out_root`.
