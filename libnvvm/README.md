# libnvvm - A C library

The `libnvvm` C library provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libnvvm` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnvvm ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libnvvm%lib{<TARGET>}
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
[bool] config.libnvvm.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
