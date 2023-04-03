#include <immintrin.h>
#include <iostream>
#include <string>

__attribute((always_inline)) inline bool
contains(const uint8_t *arr, uint8_t value, size_t len)
{
  __m256i v = _mm256_set1_epi8(value); // simd vector with all bytes equal to val
  for( size_t i = 0; i < len; i += 32 )
  {                                    // process 32 bytes at a time
    __m256i a    = _mm256_loadu_si256((__m256i *)&arr[i]); // load 32 bytes from arr
    __m256i cmp  = _mm256_cmpeq_epi8(a, v);                // compare with val
    int     mask = _mm256_movemask_epi8(cmp); // convert the comparison result to a bitmask
    if( mask != 0 )
    {
      return true; // at least one byte is equal to val
    }
  }
  return false; // none of the bytes are equal to val
}

/*
  Example For whitespace:
  contains((uint8_t *)"Hello World", 11, ' ');
*/