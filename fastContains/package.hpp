#ifndef FAST_CONTAINS_PACKAGE_HPP
#define FAST_CONTAINS_PACKAGE_HPP
#include "simd.hpp"

struct Faster {
  uint8_t* data;
  size_t size;
  [[nodiscard]] __attribute((always_inline)) inline bool check(
      uint8_t value) const;
};

__attribute((always_inline)) inline bool Faster::check(uint8_t value) const {
  return contains(data, value);
}

#endif