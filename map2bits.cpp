//
//    FILE: map2bits.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Arduino library for mapping a float to a number of bits.
//     URL: https://github.com/RobTillaart/map2bits


#include "map2bits.h"


map2bits::map2bits()
{
  init(0, 100, 10);
}


bool map2bits::init(float in_min, float in_max, uint8_t size)
{
  float _inRange = in_max - in_min;
  _outMax = size;
  if ((_inRange == 0.0 ) || (_outMax > 32)) return false;

  _in_min = in_min;
  _in_max = in_max;

  _factor = _outMax/_inRange;
  _base = - _in_min * _factor;
  return true;
}


uint32_t map2bits::map(float value)
{
  if (value <= _in_min) return 0;
  if (value >= _in_max) return (1 << _outMax) - 1;

  uint8_t count = round(_base + value * _factor);
  return (1 << count) - 1;
}


//  -- END OF FILE --

