/*
  google benchmark
  fstream read
  fread
  read
*/

// #include <benchmark/benchmark.h>
// clang ignore
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

// using json::JSON;
// using namespace simdjson;
static void
ifstreamPerf(benchmark::State& state)
{
  // auto bytes =
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json";
  std::size_t       fileSize  = std::filesystem::file_size(kFilePath);
  try
  {
    while( state.KeepRunning() )
    {
      // ifstream read file
      std::ifstream ifs(kFilePath, std::ios::binary);
      std::string   buf;
      buf.resize(fileSize);
      ifs.read(buf.data(), static_cast<std::streamsize>(fileSize));
      buf.clear();
      ifs.close();
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

static void
fstreamPerf(benchmark::State& state)
{
  // auto bytes =
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json";
  std::size_t       fileSize  = std::filesystem::file_size(kFilePath);
  try
  {
    while( state.KeepRunning() )
    {
      // fstream read file
      std::fstream ifs(kFilePath, std::ios::binary | std::ios::in);
      std::string  buf;
      buf.resize(fileSize);
      ifs.read(buf.data(), static_cast<std::streamsize>(fileSize));
      ifs.close();
      buf.clear();
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

static void
readPerf(benchmark::State& state)
{
  // auto bytes =
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json";
  std::size_t       fileSize  = std::filesystem::file_size(kFilePath);
  try
  {
    while( state.KeepRunning() )
    {
      // read
      FILE *fp = fopen(kFilePath.c_str(), "rb");
      if( fp == nullptr )
      {
        std::cout << "file open failed" << std::endl;
        return;
      }
      char *buf = new char[fileSize];
      if( read(fileno(fp), buf, fileSize) != fileSize )
      {
        std::cout << "file read failed" << std::endl;
        return;
      }
      fclose(fp);
      delete[] buf;
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

static void
freadPerf(benchmark::State& state)
{
  // auto bytes =
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json";
  std::size_t       fileSize  = std::filesystem::file_size(kFilePath);
  try
  {
    while( state.KeepRunning() )
    {
      // fread
      FILE *fp = fopen(kFilePath.c_str(), "rb");
      if( fp == nullptr )
      {
        std::cout << "fopen failed" << std::endl;
        return;
      }
      char *buf = new char[fileSize];
      fread(buf, 1, fileSize, fp);
      fclose(fp);
      delete[] buf;
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
// BENCHMARK(ifstreamPerf);
// BENCHMARK(fstreamPerf);
// BENCHMARK(readPerf);
// BENCHMARK(freadPerf);
