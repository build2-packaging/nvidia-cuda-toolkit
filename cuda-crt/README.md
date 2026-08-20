# cuda-crt - CUDA C Runtime

> **NOTE:**  
> This package is not open source and does not contain any source code. Instead,
> in order to "build" the exported target(s) it downloads (potentially large)
> pre-built binaries provided by Intel for the target platform.
>
> CI for this package is disabled due to the above.
> Supported platforms/compilers are Windows/MSVC and Linux.

The CUDA CRT (C Runtime) provides the device-side runtime support library for
CUDA applications. It underpins kernel launches, device memory management,
dynamic parallelism, and essential runtime features on the GPU. The CUDA CRT
is required for separate compilation and linking of device code.

## Usage

To start using `cuda-crt` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: cuda-crt ^13.0.1
```

Then import the library in your `buildfile`:

```
import libs = cuda-crt%lib{crt}
```


## Importable targets

This package provides the following importable targets:

```
lib{crt}
```


## Configuration variables

This package provides the following configuration variables:

```
[dir_path] config.cuda_crt.cache ?= $out_root
```

The directory used to cache downloaded binary archives between builds. If
`config.cuda.cache` is set (a shared project-wide cache directory), it
takes precedence over the per-package default of `$out_root`.
