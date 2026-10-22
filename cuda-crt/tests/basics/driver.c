#define __CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__
#include <crt/host_config.h>

#ifndef __HOST_CONFIG_H__
  #error __HOST_CONFIG_H__ not defined
#endif

/* .hpp headers are included by the .h ones as siblings, so they have to
   install into the same directory. */
#if !__has_include(<crt/device_functions.hpp>)
  #error crt/device_functions.hpp not reachable beside crt/device_functions.h
#endif

int main() {
  return 0;
}
