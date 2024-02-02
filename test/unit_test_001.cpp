//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-12-04
// PURPOSE: unit tests for the map2bit library
//          https://github.com/RobTillaart/map2bits
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)


#include <ArduinoUnitTests.h>


#include "map2bits.h"


unittest_setup()
{
  fprintf(stderr, "MAP2BITS_LIB_VERSION: %s\n", (char *) MAP2BITS_LIB_VERSION);
}


unittest_teardown()
{
}


unittest(test_constructor)
{
  map2bits mb;
  assertTrue(mb.init(0, 100, 10));

  asserEqual(0, mb.map(-10));
  asserEqual(0, mb.map(0));
  asserEqual(0, mb.map(4));
  asserEqual(1, mb.map(5));
  asserEqual(1, mb.map(14));
  asserEqual(3, mb.map(15));
  asserEqual(3, mb.map(24));
  asserEqual(7, mb.map(25));
  asserEqual(7, mb.map(34));
  asserEqual(15, mb.map(35));
  asserEqual(15, mb.map(44));
  asserEqual(31, mb.map(55));
  asserEqual(31, mb.map(54));
  asserEqual(63, mb.map(55));
  asserEqual(63, mb.map(64));
  asserEqual(127, mb.map(65));
  asserEqual(127, mb.map(74));
  asserEqual(255, mb.map(75));
  asserEqual(255, mb.map(84));
  asserEqual(511, mb.map(85));
  asserEqual(511, mb.map(94));
  asserEqual(1023, mb.map(10));
  asserEqual(1023, mb.map(1000));
}


unittest_main()


//  -- END OF FILE --

