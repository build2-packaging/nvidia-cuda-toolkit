# cuda-nvcc - A C library

> **NOTE:**  
This package is not open source and does not contain any source code. Instead,
in order to "build" the exported target(s) it downloads (potentially large)
pre-built binaries provided by NVIDIA for the target platform.
>
> CI for this package is disabled due to the above.  
Supported platforms/compilers are Windows/MSVC. Linux binaries exist but are
currently not available through this package.

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
import libs = cuda-nvcc%liba{nvcc}
```


## Importable targets

This package provides the following importable targets:

```
liba{nvcc}
exe{bin2c}
exe{cudafe++}
exe{fatbinary}
exe{nvcc}
exe{nvlink}
exe{ptxas}
```
