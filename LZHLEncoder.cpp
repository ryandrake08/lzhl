#include "LZHLEncoder.hpp"
#include <cassert>

LZHLEncoder::LZHLEncoder( LZHLEncoderStat* stat_, uint8_t* dst_ )
  : stat( stat_ ),
    sstat( stat_->stat ),
    nextStat( stat_->nextStat ),
    dst( dst_ ),
    dstBegin( dst_ ),
    bits( 0 ),
    nBits( 0 )
{ }

LZHLEncoder::~LZHLEncoder() { }

void LZHLEncoder::_putBits( int codeBits, uint32_t code ) {
  assert( codeBits <= 16 );
  bits |= ( code << ( 32 - nBits - codeBits ) );
  nBits += codeBits;

  if ( nBits >= 16 ) {
    *dst++ = (uint8_t)( bits >> 24 );
    *dst++ = (uint8_t)( bits >> 16 );

    nBits -= 16;
    bits <<= 16;
  }
}

void LZHLEncoder::_put( uint16_t symbol ) {
  assert( symbol < NHUFFSYMBOLS );

  if ( --nextStat <= 0 ) {
    _callStat();
  }

  ++sstat[ symbol ];

  LZHLEncoderStat::Symbol* item = &stat->symbolTable[ symbol ];
  assert( item->nBits >= 0 );

  _putBits( item->nBits, item->code );
}

void LZHLEncoder::_put( uint16_t symbol, int codeBits, uint32_t code ) {
  assert( symbol < NHUFFSYMBOLS );
  assert( codeBits <= 4 );

  if ( --nextStat <= 0 ) {
    _callStat();
  }

  ++sstat[ symbol ];

  LZHLEncoderStat::Symbol* item = &stat->symbolTable[ symbol ];
  assert( item->nBits >= 0 );

  int nBits = item->nBits;
  _putBits( nBits + codeBits, ( item->code << codeBits ) | code );
}
