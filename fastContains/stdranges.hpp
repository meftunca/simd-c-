

#include <algorithm>
#include <cstddef>

#include <_types/_uint8_t.h>
#include <experimental/simd>
using std::experimental::simd;
using vec16u = std::experimental::fixed_size_simd<uint8_t, 16>;

inline bool contains(uint8_t* arr, size_t size, uint8_t value) {
  //  experimental simd ile simd işlemleri yapabiliyoruz
  auto simdValue = vec16u(value);
  std::experimental::any_of(arr, arr + size, [&](uint8_t *data) {
    vec16u simdData = vec16u(*data);
    return simdData == simdValue;
  }
  return false;
}