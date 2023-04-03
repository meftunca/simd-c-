#include <smmintrin.h>

__attribute((always_inline)) inline bool
contains(uint8_t *arr, size_t size, uint8_t value)
{
  __m128i v = _mm_set1_epi8(value); // simd vector with all bytes equal to val
  for( size_t i = 0; i < size; i += 16 )
  {                                                     // process 16 bytes at a time
    __m128i a    = _mm_loadu_si128((__m128i *)&arr[i]); // load 16 bytes from arr
    __m128i cmp  = _mm_cmpeq_epi8(a, v);                // compare with val
    int     mask = _mm_movemask_epi8(cmp); // convert the comparison result to a bitmask
    if( mask != 0 )
    {
      return true; // at least one byte is equal to val
    }
  }
  return false; // none of the bytes are equal to val
}