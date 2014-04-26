#include <stddef.h>

void *initComp();
size_t compress(void *comp, unsigned char *buf, size_t size, unsigned char *ret);
void *initDecomp();
size_t decompress(void *decomp, unsigned char *buf, size_t size, unsigned char *ret, size_t retsize);
