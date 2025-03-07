#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

#undef NDEBUG

#include <assert.h>
#include <stdio.h>
// #include <string.h>

int main() {
  int version = 0;
  // returns success with version 0 if no
  // cuda driver (& GPU) is available.
  assert(cudaDriverGetVersion(&version) == cudaSuccess);
  int major = version / 1000;
  int minor = (version - (1000 * major)) / 10;
  printf("libcudart - cudaDriverGetVersion(): v%d.%d (%d)\n", major, minor, version);

  int count = 0;
  cudaGetDeviceCount(&count);
  printf("libcudart - cudaGetDeviceCount(): %d\n", count);

  /* Only available on system with Nvidia GPUs */
  // int len = 1024;
  // char* name = (char*)malloc(len * sizeof(char));
  // for(int i = 0; i < count; ++i)
  // {
  //   CUdevice dev;
  //   assert(cuDeviceGet(&dev, i) == CUDA_SUCCESS);
  //   memset(name, 0, len);
  //   assert(cuDeviceGetName(name, len, dev) == CUDA_SUCCESS);
  //   printf("libcudart - cuDeviceGetName(): %s (device: %d)\n", name, dev);
  // }
  // free(name);

  // expects the driver version as input
  if(version > 0)
  {
    assert(cudaRuntimeGetVersion(&version) == cudaSuccess);
    major = version / 1000;
    minor = (version - (1000 * major)) / 10;
    printf("libcudart - cudaRuntimeGetVersion(): v%d.%d (%d)\n", major, minor, version);
  }
  else
  {
    assert(cudaRuntimeGetVersion(&version) == cudaSuccess);
  }
  return 0;
}
