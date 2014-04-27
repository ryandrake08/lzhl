#include "LZHLDecoderStat.hpp"
#include "LZHLCompressor.hpp"
#include "LZHLDecompressor.hpp"

extern "C" {

  void *initComp(void) {
    return new LZHLCompressor();
  }

  size_t compress(void *comp, unsigned char *buf, size_t size, unsigned char *ret) {
    return ((LZHLCompressor *)comp)->compress(ret, buf, size);
  }

  void *initDecomp(void) {
    return new LZHLDecompressor();
  }

  size_t decompress(void *decomp, unsigned char *buf, size_t size, unsigned char *ret, size_t retsize) {
    ((LZHLDecompressor *)decomp)->decompress(ret, &retsize, buf, &size);
    return retsize;
  }

}
