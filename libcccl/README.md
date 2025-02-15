# libcccl - A C++ library

The goal of CCCL is to provide CUDA C++ developers with building blocks
that make it easier to write safe and efficient code. Bringing these
libraries together streamlines your development process and broadens
your ability to leverage the power of CUDA C++.


## Usage

To start using `libcccl` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libcccl ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libcccl%lib{cccl}
```


## Importable targets

This package provides the following importable targets:

```
lib{cccl}
```
