# libnvrtc - A C library

The `libnvrtc` C library provides <SUMMARY-OF-FUNCTIONALITY>.


## Usage

To start using `libnvrtc` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnvrtc ^<VERSION>
```

Then import the library in your `buildfile`:

```
import libs = libnvrtc%lib{<TARGET>}
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
[bool] config.libnvrtc.<VARIABLE> ?= false
```

<DESCRIPTION-OF-CONFIG-VARIABLES>
