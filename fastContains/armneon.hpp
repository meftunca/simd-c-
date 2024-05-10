#include <arm_neon.h>
#include <cstddef>

// // amaç: simd ile bir dizi içerisinde bir değerin olup olmadığını en hızlı şekilde bulmak
inline bool contains(const uint8_t* data, uint8_t& target) {
  // if (__has_feature(arm_neon)) {
  //   printf("ARM Neon SIMD instructions are supported.\n");
  // } else {
  //   printf("ARM Neon SIMD instructions are not supported.\n");
  // }
  auto v_array = vld1q_u16(reinterpret_cast<const uint16_t*>(data));

  // Compare the array with the character.
  auto v_result = vceqq_u16(v_array, vdupq_n_u16(target));

  // Count the number of 1 bits in the result.
  uint32_t count = vgetq_lane_u32(vcntq_u8(v_result), 0);
  return count > 0;
}
