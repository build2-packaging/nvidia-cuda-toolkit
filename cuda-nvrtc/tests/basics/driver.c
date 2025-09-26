#include <nvrtc.h>

#undef NDEBUG

#include <assert.h>
#include <stdio.h>

int main() {
  int major=0, minor=0;
  assert(nvrtcVersion(&major, &minor) == NVRTC_SUCCESS);
  printf("cuda-nvrtc - nvrtcVersion(): v%d.%d\n", major, minor);
  return 0;
}
