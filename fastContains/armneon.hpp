#if defined(__ARM_NEON__)
#  include <stdint.h>

#  include <arm_neon.h>

bool
contains(const uint8_t *data, uint8_t value, size_t size)
{
  uint8x16_t     needle = vdupq_n_u8(value);
  const uint8_t *end    = data + size;

  for( ; data + 16 <= end; data += 16 )
  {
    uint8x16_t haystack = vld1q_u8(data);
    uint8x16_t cmp      = vceqq_u8(haystack, needle);
    uint64x2_t mask     = vreinterpretq_u64_u8(cmp);
    if( vgetq_lane_u64(mask, 0) != 0 || vgetq_lane_u64(mask, 1) != 0 ) { return true; }
  }

  for( ; data < end; ++data )
  {
    if( *data == value ) { return true; }
  }

  return false;
}

#endif