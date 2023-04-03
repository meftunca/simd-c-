#pragma once

#include <cctype>
#include <cstring>

#include <experimental/simd>

// SIMD boyutu
constexpr std::size_t SimdSize = std::experimental::native_simd<int>::size();

// SIMD ile whitespace tablosunu eşleştiren fonksiyon
void
WhitespaceTableParallelMatch(const char *input, std::size_t size, bool *output)
{
  // SIMD boyutuna tam olarak bölünebilecek boyuta yuvarla
  std::size_t simdAlignedSize = (size / SimdSize) * SimdSize;

  // SIMD ile işleme yapmak için gerekli verileri yükle
  std::experimental::native_simd<int> maskSpace = std::experimental::simd::load(
      []()
      {
        int mask[SimdSize] = {};
        for( std::size_t i = 0; i < SimdSize; i++ )
        {
          mask[i] = std::isspace(static_cast<unsigned char>(i));
        }
        return mask;
      }());

  // SIMD ile işleme yapmak için gerekli verileri yükle
  std::experimental::native_simd<int> maskTab = std::experimental::simd::load(
      []()
      {
        int mask[SimdSize] = {};
        for( std::size_t i = 0; i < SimdSize; i++ ) { mask[i] = (i == '\t'); }
        return mask;
      }());

  // SIMD boyutunda işleme yapmak için gerekli verileri yükle
  for( std::size_t i = 0; i < simdAlignedSize; i += SimdSize )
  {
    std::experimental::native_simd<int> inputSimd =
        std::experimental::simd::load(reinterpret_cast<const int *>(input + i));
    std::experimental::native_simd<int> spaceMask  = inputSimd == maskSpace;
    std::experimental::native_simd<int> tabMask    = inputSimd == maskTab;
    std::experimental::native_simd<int> resultMask = spaceMask | tabMask;
    std::experimental::simd::store(reinterpret_cast<bool *>(output + i), resultMask);
  }

  // SIMD boyutuna tam olarak bölünebilen kısmı eşleştir
  for( std::size_t i = simdAlignedSize; i < size; i++ )
  {
    output[i] = std::isspace(static_cast<unsigned char>(input[i])) || (input[i] == '\t');
  }
}