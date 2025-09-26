#include <cuda/version>

#undef NDEBUG

#include <cassert>
#include <stdio.h>

int main() {
  printf("cuda-cccl - _CCCL_STD_VER: %d\n", _CCCL_STD_VER);
}
