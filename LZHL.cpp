// LHZL.cpp : Defines the entry point for the console application.
//

#include "LZHLDecoderStat.hpp"
#include "LZHLCompressor.hpp"
#include "LZHLDecompressor.hpp"

typedef LZHLDecoderStat::Group Group;

extern "C" {

void *initComp() {
	return new LZHLCompressor();
}

size_t compress(LZHLCompressor *comp, unsigned char *buf, size_t size, unsigned char *ret) {
	return comp->compress(ret, buf, size);
}

void *initDecomp() {
	return new LZHLDecompressor();
}

size_t decompress(LZHLDecompressor *decomp, unsigned char *buf, size_t size, unsigned char *ret, size_t retsize) {
	decomp->decompress(ret, &retsize, buf, &size);
	return retsize;
}

}
