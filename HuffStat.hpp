#ifndef __J2K__LZH__HuffStat_HPP__
#define __J2K__LZH__HuffStat_HPP__

#include "LZHMacro.hpp"
#include "HuffStatTmp.hpp"

class HuffStat {
public:
  HuffStat();
  virtual ~HuffStat();
public:
  HUFFINT* stat;

protected:
  int makeSortedTmp( HuffStatTmpStruct* );

};

#endif
