#include <emmintrin.h>
#include <smmintrin.h>

__attribute((always_inline)) inline bool
contains(uint8_t *arr, size_t size, uint8_t value)
{
  // SIMD yüksek hızlandırma için, 128-bitlik SIMD türü olan __m128i kullanıyoruz.
  // __m128i, 16 adet uint8_t değerini içerebilen bir türdür.
  constexpr size_t SimdWidth     = 16;
  constexpr size_t SimdAlignment = 16;
  size_t           simdCount     = size / SimdWidth;
  __m128i          simdValue     = _mm_set1_epi8(value);
  for( size_t i = 0; i < simdCount; i++ )
  {
    __m128i simdArray = _mm_load_si128(reinterpret_cast<__m128i *>(arr + i * SimdWidth));
    __m128i result    = _mm_cmpeq_epi8(simdArray, simdValue);
    int     mask      = _mm_movemask_epi8(result);
    if( mask != 0 ) { return true; }
  }
  for( size_t i = simdCount * SimdWidth; i < size; i++ )
  {
    if( arr[i] == value ) { return true; }
  }
  return false;
}
