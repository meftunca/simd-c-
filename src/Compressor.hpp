#ifndef COMPRESSOR_HPP
#define COMPRESSOR_HPP
#include <iostream>
#include <lz4.h>
#include <lz4hc.h>
#include <string>
namespace utils
{

inline char *
compress(std::string&& uncompressed_data)
{
  // Buffer boyutunu hesapla
  const int compressed_size = LZ4_compressBound(uncompressed_data.size());
  char     *compressed_data = new char[compressed_size];

  // Sıkıştır
  int compressed_data_size = LZ4_compress_HC(uncompressed_data.c_str(),
                                             compressed_data,
                                             uncompressed_data.size(),
                                             compressed_size,
                                             LZ4HC_CLEVEL_MAX);
  return compressed_data;
}

inline char *
decompress(char *compressed_data, int compressed_data_size, int uncompressed_data_size)
{
  // Yeniden aç
  char *decompressed_data      = new char[uncompressed_data_size];
  int   decompressed_data_size = LZ4_decompress_safe(
      compressed_data, decompressed_data, compressed_data_size, uncompressed_data_size);
  return decompressed_data;
}

// int main() {
//     std::string uncompressed_data = "Bu bir testtir. Bu bir testtir. Bu bir testtir. Bu bir
//     testtir. Bu bir testtir. Bu bir testtir."; std::cout << "Orjinal boyut: " <<
//     uncompressed_data.size() << " bytes\n";

//     // Buffer boyutunu hesapla
//     const int compressed_size = LZ4_compressBound(uncompressed_data.size());
//     char* compressed_data = new char[compressed_size];

//     // Sıkıştır
//     int compressed_data_size = LZ4_compress_HC(uncompressed_data.c_str(), compressed_data,
//     uncompressed_data.size(), compressed_size, LZ4HC_CLEVEL_MAX);

//     std::cout << "Sıkıştırılmış boyut: " << compressed_data_size << " bytes\n";

//     // Yeniden aç
//     char* decompressed_data = new char[uncompressed_data.size()];
//     int decompressed_data_size = LZ4_decompress_safe(compressed_data, decompressed_data,
//     compressed_data_size, uncompressed_data.size());

//     std::cout << "Yeniden açılan boyut: " << decompressed_data_size << " bytes\n";
//     std::cout << "Veri: " << decompressed_data << "\n";

//     // Bellek temizle
//     delete[] compressed_data;
//     delete[] decompressed_data;

//     return 0;
// }
}

#endif