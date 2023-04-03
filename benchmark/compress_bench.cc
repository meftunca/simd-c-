/*
  google benchmark
  fstream read
  fread
  read
*/

// #include <benchmark/benchmark.h>
// clang ignore
#include "lz4.h"

#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <unistd.h>
#include <vector>

#include <benchmark/benchmark.h>

static void
lz4CompressBenchmark(benchmark::State& state)
{
  // auto bytes =
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json";
  std::size_t       fileSize  = std::filesystem::file_size(kFilePath);
  FILE             *fp        = fopen(kFilePath.c_str(), "rb");
  // LZ4_stream_t     *streamPtr = LZ4_createStream();
  if( fp == nullptr )
  {
    std::cout << "fopen failed" << std::endl;
    return;
  }
  char *buf = new char[fileSize];
  fread(buf, 1, fileSize, fp);
  fclose(fp);
  delete[] buf;
  try
  {
    while( state.KeepRunning() )
    {
      // fread
      char *output = new char[LZ4_compressBound(fileSize)];
      // LZ4_compress_default(buf, output, fileSize, LZ4_compressBound(fileSize));
      LZ4_compress_fast(buf, output, fileSize, LZ4_compressBound(fileSize), 6);
      // LZ4_compress_fast_continue(streamPtr, buf, output, fileSize, LZ4_compressBound(fileSize),
      // 6);
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }
  // auto processedBytes = sizeof(float) * size * 3;

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}

// Register the function as a benchmark

// BENCHMARK(lz4CompressBenchmark);