#include <nvrtc.h>

#undef NDEBUG

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int major=0, minor=0;
  assert(nvrtcVersion(&major, &minor) == NVRTC_SUCCESS);
  printf("cuda-nvrtc - nvrtcVersion(): v%d.%d\n", major, minor);

  /* Compiling loads nvrtc-builtins by bare name. */
  const char* src = "__global__ void k (float* p) { p[0] = 1.0f; }\n";

  nvrtcProgram prog;
  assert(nvrtcCreateProgram(&prog, src, "k.cu", 0, NULL, NULL) == NVRTC_SUCCESS);

  nvrtcResult r = nvrtcCompileProgram(prog, 0, NULL);

  if (r != NVRTC_SUCCESS) {
    size_t n = 0;
    nvrtcGetProgramLogSize(prog, &n);
    char* log = (char*)malloc(n + 1);
    log[0] = '\0';
    nvrtcGetProgramLog(prog, log);
    printf("cuda-nvrtc - nvrtcCompileProgram(): %s\n%s\n",
           nvrtcGetErrorString(r), log);
    free(log);
  }

  assert(r == NVRTC_SUCCESS);

  size_t size = 0;
  assert(nvrtcGetPTXSize(prog, &size) == NVRTC_SUCCESS);
  printf("cuda-nvrtc - nvrtcGetPTXSize(): %zu bytes\n", size);
  assert(size != 0);

  assert(nvrtcDestroyProgram(&prog) == NVRTC_SUCCESS);
  return 0;
}
