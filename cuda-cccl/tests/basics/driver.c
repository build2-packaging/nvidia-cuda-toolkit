// One header per installed include directory.
//
#include <cuda/version>
#include <cuda/std/array>
#include <thrust/version.h>
#include <nv/target>

#undef NDEBUG

#include <cassert>
#include <stdio.h>

int main() {
  cuda::std::array<int, 3> a{1, 2, 3};
  assert(a.size() == 3);

  printf("cuda-cccl - _CCCL_STD_VER: %d\n", _CCCL_STD_VER);
  printf("cuda-cccl - THRUST_VERSION: %d\n", THRUST_VERSION);
}
