#include <fatbinary_section.h>

#undef NDEBUG

#include <assert.h>
#include <stdio.h>

int main() {
  unsigned int major=0, minor=0;
  assert(FATBINC_MAGIC > 0);
  printf("libnvcc - FATBINC_MAGIC: %d FATBINC_VERSION: %d FATBINC_LINK_VERSION: %d\n",
         FATBINC_MAGIC, FATBINC_VERSION, FATBINC_LINK_VERSION);
  return 0;
}
