
// #include "src/gason.hpp"
// #include "src/simdjsonToNlohman.hpp"
// #include "src/simdjsonToTao.hpp"
// #include "src/jsmn.hpp"
// #include "src/stix.hpp"
// #include "src/jsont.hh"
#include "lz4.h"
#include "mio.hpp"
#include "src/PerformanceLogger.hpp"
#include "src/mmap.hpp"

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>

#include <gtest/gtest.h>
#include <string_view>
#include <sys/fcntl.h>

// TEST(Performance, LZ4)
// {
//   // auto bytes =
//   try
//   {
//     const std::string kFilePath =
//     "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json"; std::size_t       fileSize
//     = std::filesystem::file_size(kFilePath); FILE             *fp        =
//     fopen(kFilePath.c_str(), "rb");
//     // LZ4_stream_t     *streamPtr = LZ4_createStream();
//     if( fp == nullptr )
//     {
//       std::cout << "fopen failed" << std::endl;
//       return;
//     }
//     char *buf = new char[fileSize];
//     fread(buf, 1, fileSize, fp);
//     fclose(fp);
//     delete[] buf;
//     // fread
//     int   src_size        = (int)(strlen(buf) + 1);
//     char *output          = new char[LZ4_compressBound(fileSize)];
//     int   nCompressedSize = LZ4_compress(buf, output, fileSize);
//     std::cout << "LZ4_compress: " << nCompressedSize << std::endl;
//     // LZ4_compress_default(buf, output, fileSize, LZ4_compressBound(fileSize));
//     // LZ4_compress_fast(buf, output, sizeof(buf), LZ4_compressBound(fileSize), 2);
//     // LZ4_compress_default(buf, output, src_size, LZ4_compressBound(src_size));
//     // write to file .min
//     std::cout << "output size: " << output << std::endl;
//     std::ofstream ofs;
//     ofs.open("/Users/devloops/Desktop/main_projects/simd/bulker/twitter.min.json",
//              std::ios::binary);
//     if( !ofs || !ofs.is_open() )
//     {
//       std::cout << "open file failed" << std::endl;
//       return;
//     }
//     ofs << output;

//     ofs.close();
//   }
//   catch( const std::exception& e )
//   {
//     std::cerr << e.what() << '\n';
//   }
//   // LZ4_compress_fast_continue(streamPtr, buf, output, fileSize, LZ4_compressBound(fileSize),
//   // 6);
// }

TEST(Performance, MMAP_TEST)
{
  // const int size = static_cast<int>(state.range(0));
  // MAX_PATH length is 260

  try
  {
    std::chrono::high_resolution_clock::time_point start =
        std::chrono::high_resolution_clock::now();
    // Open a file.
    MemoryMappedFile mmapped_file("test.txt");

    std::cout << "Current file content:" << std::endl;
    mmapped_file.read();

    std::string content = "Hello, memory-mapped file!";
    std::cout << "\n\nWriting to the file: \"" << content << "\"" << std::endl;
    mmapped_file.write(content);

    std::cout << "\nNew file content:" << std::endl;
    mmapped_file.read();

    std::cout << "\n\nRemoving the file." << std::endl;
    mmapped_file.removeFile();
    std::chrono::high_resolution_clock ::time_point end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Duration(ms): " << duration << std::endl;
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }
  // Expect equality.
  EXPECT_EQ(42, 42);
}
