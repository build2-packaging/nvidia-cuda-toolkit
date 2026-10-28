#include <fatbinary_section.h>

#undef NDEBUG

#include <assert.h>
#include <stdio.h>

int main() {
  assert(FATBINC_MAGIC > 0);
  printf("cuda-nvcc - FATBINC_MAGIC: %d FATBINC_VERSION: %d FATBINC_LINK_VERSION: %d\n",
         FATBINC_MAGIC, FATBINC_VERSION, FATBINC_LINK_VERSION);
  return 0;
}
