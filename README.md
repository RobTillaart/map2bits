
[![Arduino CI](https://github.com/RobTillaart/map2bits/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/map2bits/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/map2bits/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/map2bits/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/map2bits/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/map2bits.svg)](https://github.com/RobTillaart/map2bits/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/map2bits/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/map2bits.svg?maxAge=3600)](https://github.com/RobTillaart/map2bits/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/map2bits.svg)](https://registry.platformio.org/libraries/robtillaart/map2bits)


# map2bits

Arduino library for mapping a float to a number of bits.


## Description

Map2bits is an **experimental** library which can be used to map a float 
value to a number of bits.
The float value can be the result of a calculation or read from a sensor, 
e.g. temperature, humidity, light, distance, direction or pressure. 

**map2bits** is developed to drive a led bar like this one.
https://www.tinytronics.nl/shop/nl/displays/segmenten/led-bar-10x-rood
However there are many other devices to drive or applications to think of.

As always, feedback is welcome.


#### Related

Other mapping libraries

- https://github.com/RobTillaart/FastMap
- https://github.com/RobTillaart/Gamma
- https://github.com/RobTillaart/map2bits
- https://github.com/RobTillaart/map2colour
- https://github.com/RobTillaart/moduloMap
- https://github.com/RobTillaart/MultiMap


## Interface

```cpp
#include "map2bits.h"
```

#### Functions

- **map2bits()** Constructor, defines a default mapping of (0..100 => 10)
- **uint8_t init(float in_min, float in_max, uint32_t bits)** defines the mapping
input range and how many bits output should be generated.
- **uint32_t map(float value)** maps value to an uint32_t with the appropriate 
number of bits set. These are constrained by the number of bits set in **init()**.

The output of **map()** is a bit mask and can be used to drive e.g. a led bar etc.


## Operation

Suppose you have the following code 
```
mb.init(0, 100, 10);
x = mb.map(64);        //  x becomes 111111     (binair) 6 bits set
x = mb.map(99);        //  x becomes 1111111111 (binair) 10 bits set
x = mb.map(4);         //  x becomes 0 (binair) no bit set

x = mb.map(-10);       //  x becomes 0 (binair) no bit set
x = mb.map(1000);      //  x becomes 1111111111 (binair) 10 bits set
```

See examples.


## Performance

Indicative performance figures measured with the performance example.
Performance depends on colours chosen, platform etc.

Note: time in microseconds
Note: UNO at 16 MHz, ESP32 at 240 MHz

TO ELABORATE


## Future

#### Must

- update documentation

#### Should

- extend the idea
- add examples
- optimize

#### Could

- max 64 bit output version?  **map64(value)**?
- Double intput version (for the range)
- uint32_t input version
- map2DAC? 
  - maps a range to analogWrite()..
  - separate class. 

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,
