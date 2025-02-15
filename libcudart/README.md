# libcudart - A C library

The `libcudart` C library provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libcudart` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libcudart ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libcudart%lib{<TARGET>}
```


## Importable targets

This package provides the following importable targets:

```
lib{<TARGET>}
```

<DESCRIPTION-OF-IMPORTABLE-TARGETS>


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libcudart.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
