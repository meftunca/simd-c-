// #ifndef SIMD_TOOL_HPP
// #define SIMD_TOOL_HPP
#pragma once
#include <memory>
// #define SIMD_TARGET
#define SIMD_REALlY_INLINE __attribute__((always_inline))

#define REPEAT8_ARGS(typ)  typ v0, typ v1, typ v2, typ v3, typ v4, typ v5, typ v6, typ v7
#define REPEAT16_ARGS(typ) REPEAT8_ARGS(typ), REPEAT8_ARGS(typ)
#define REPEAT32_ARGS(typ) REPEAT16_ARGS(typ), REPEAT16_ARGS(typ)

#define FILL_4(c)  c, c, c, c
#define FILL_8(c)  FILL_4(c), FILL_4(c)
#define FILL_16(c) FILL_8(c), FILL_8(c)
#define FILL_32(c) FILL_16(c), FILL_16(c)
#ifndef __SIMD_ARCH__
#  define __SIMD_ARCH__ "null"
#endif

#if defined(__AVX__) || defined(__AVX2__)
#  include <immintrin.h>
// set simd flags  align 16

// uint8_t spaceMask[32] = {0x20, 0x09, 0x0a, 0x0d, 0x0c, 0x08, 0x0b, 0x07, 0x3a, 0x2c, 0x00, 0x00,
static const __m256i spaceMask = _mm256_setr_epi8(0x20,
                                                  0x09,
                                                  0x0a,
                                                  0x0d,
                                                  0x0c,
                                                  0x08,
                                                  0x0b,
                                                  0x07,
                                                  0x3a,
                                                  0x2c,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00);

inline bool SIMD_REALlY_INLINE
isSpace(const char c)
{
  return _mm256_movemask_epi8(_mm256_cmpeq_epi8(_mm256_set1_epi8(c), spaceMask)) != 0;
}
#elif defined(__SSE__)
#  include <immintrin.h>
#  include <nmmintrin.h>
#  include <smmintrin.h>
//  space char detection

static const __m128i spaceMask = _mm_setr_epi8(0x20,
                                               0x09,
                                               0x0a,
                                               0x0d,
                                               0x0c,
                                               0x08,
                                               0x0b,
                                               0x07,
                                               0x3a,
                                               0x2c,
                                               0x00,
                                               0x00,
                                               0x00,
                                               0x00,
                                               0x00,
                                               0x00);

SIMD_REALlY_INLINE bool
isSpace(char c)
{
  return _mm_movemask_epi8(_mm_cmpeq_epi8(_mm_set1_epi8(c), spaceMask)) != 0;
}

#elif defined(__AVX512F__) || defined(__AVX512BW__)
#  include <immintrin.h>
static const __m512i spaceMask = _mm512_setr_epi8(0x20,
                                                  0x09,
                                                  0x0a,
                                                  0x0d,
                                                  0x0c,
                                                  0x08,
                                                  0x0b,
                                                  0x07,
                                                  0x3a,
                                                  0x2c,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00,
                                                  0x00);

//  space char detection
SIMD_REALlY_INLINE bool
isSpace(char c)
{
  return _mm512_cmpeq_epi8_mask(_mm512_set1_epi8(c), spaceMask) != 0;
}
#else
inline bool
isSpace(char c)
{
  return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}
#endif

// #endif // SIMD_TOOL_HPP