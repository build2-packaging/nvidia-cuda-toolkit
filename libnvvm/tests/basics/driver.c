#include <nvvm.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <stdio.h>

int main() {
  int major=0, minor=0;
  assert(nvvmVersion(&major, &minor) == NVVM_SUCCESS);
  printf("libnvvm - nvvmVersion(): v%d.%d\n", major, minor);
  return 0;
}
