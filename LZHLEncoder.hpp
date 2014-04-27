#ifndef __J2K__LZH__LZHLEncoder_HPP__
#define __J2K__LZH__LZHLEncoder_HPP__

#include "LZHLEncoderStat.hpp"
#include "LZHMacro.hpp"
#include <cstddef>

class LZHLEncoder {
public:
  enum { maxMatchOver = 517, maxRaw = 64 };
  LZHLEncoder( LZHLEncoderStat* stat_, uint8_t* dst_ );
  ~LZHLEncoder();

private:
  LZHLEncoderStat* stat;
  HUFFINT* sstat;
  int& nextStat;

  uint8_t* dst;
  uint8_t* dstBegin;
  uint32_t bits;
  int nBits;

public:
  static size_t calcMaxBuf( size_t rawSz ) {
    return rawSz + ( rawSz >> 1 ) + 32;
  }

public:
  size_t flush();

  void putRaw( const uint8_t* src, size_t sz );
  void putMatch( const uint8_t* src, size_t nRaw, size_t matchOver, size_t disp );

private:
  void _callStat();

  void _put( uint16_t symbol );
  void _put( uint16_t symbol, int codeBits, uint32_t code );
  void _putBits( int codeBits, uint32_t code );
};

#endif
