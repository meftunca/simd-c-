#ifndef FAST_CONTAINS_PACKAGE_HPP
#define FAST_CONTAINS_PACKAGE_HPP
#include "simd.hpp"

struct faster
{
  uint8_t                                 *data;
  size_t                                   size;
  __attribute((always_inline)) inline bool check(uint8_t value);
};

__attribute((always_inline)) inline bool
faster::check(uint8_t value)
{
  return contains(data, value, size);
}

#endif