#include <cublas.h>

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <assert.h>
#include <stdio.h>

int main() {
  int version=0;
  assert(cublasGetVersion(&version) == CUBLAS_STATUS_SUCCESS);
  int major = version / 10000;
  int minor = (version - (10000 * major)) / 100;
  printf("libcublas - cublasGetVersion(): v%d.%d (%d)\n", major, minor, version);
  return 0;
}
