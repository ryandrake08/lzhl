#ifndef __J2K__LZH__LZHLDecompressor_HPP__
#define __J2K__LZH__LZHLDecompressor_HPP__

#include "LZBuffer.hpp"
#include "LZHLDecoderStat.hpp"

class LZHLDecompressor : public LZBuffer, public LZHLDecoderStat {
private:
  uint32_t bits;
  int nBits;

public:
  LZHLDecompressor();
  virtual ~LZHLDecompressor();
  bool decompress( uint8_t* dst, size_t* dstSz, const uint8_t* src, size_t* srcSz );

private:
  inline int _get( const uint8_t*& src, const uint8_t* srcEnd, int n );
};

#endif
