#include <nvPTXCompiler.h>

#undef NDEBUG

#include <assert.h>
#include <stdio.h>

int main() {
  unsigned int major=0, minor=0;
  assert(nvPTXCompilerGetVersion(&major, &minor) == NVPTXCOMPILE_SUCCESS);
  printf("libnvcc - nvPTXCompilerGetVersion(): v%d.%d\n", major, minor);
  return 0;
}
