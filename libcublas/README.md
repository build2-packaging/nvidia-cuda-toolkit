# libcublas - A C library

The `libcublas` C library provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libcublas` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libcublas ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libcublas%lib{<TARGET>}
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
[bool] config.libcublas.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
