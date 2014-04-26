#ifndef __J2K__LZH__LZBuffer_HPP__
#define __J2K__LZH__LZBuffer_HPP__

#include "LZHMacro.hpp"
#include <cstddef>

class LZBuffer {
public:
  LZBuffer();
  ~LZBuffer();

protected:
  static int _wrap( LZPOS pos );
  static int _distance( int diff );

  void _toBuf( uint8_t );
  void _toBuf( const uint8_t*, size_t sz );
  void _bufCpy( uint8_t* dst, int pos, size_t sz );
  int _nMatch( int pos, const uint8_t* p, int nLimit );

public:
  uint8_t* buf;
  LZPOS bufPos;
};

#endif
