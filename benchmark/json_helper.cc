
// #include <benchmark/benchmark.h>
// clang ignore
#include "./src/JSONHelper.hpp"
#include "./src/simdTool.hpp"

#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>

#include <benchmark/benchmark.h>
#include <experimental/coroutine>

static std::pair<std::string, size_t>
readFile()
{
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json";
  std::size_t       fileSize  = std::filesystem::file_size(kFilePath);
  // readData
  std::ifstream ifs(kFilePath, std::ios::binary);
  std::string   buf;
  buf.resize(fileSize);
  ifs.read(buf.data(), static_cast<std::streamsize>(fileSize));
  ifs.close();
  return {buf, fileSize};
}
static void
std_isws(benchmark::State& state)
{
  auto [buf, fileSize] = readFile();
  // auto bytes =
  try
  {
    while( state.KeepRunning() )
    {
      // random float number
      // for( auto c : buf )
      // {
      //   benchmark::DoNotOptimize(json_helper::isCharExist(c));
      //   benchmark::ClobberMemory();
      // }
      for( auto c : buf )
      {
        benchmark::DoNotOptimize(isspace(c));
        benchmark::ClobberMemory();
      }
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
  // // ns/op
  // auto totalTime          = state.iterations() * fileSize;
  // state.counters["ns/op"] = static_cast<double>(totalTime / state.items_processed());
}
static void
simd_isws(benchmark::State& state)
{
  auto [buf, fileSize] = readFile();
  // auto bytes =
  try
  {
    while( state.KeepRunning() )
    {
      // random float number
      for( auto c : buf )
      {
        benchmark::DoNotOptimize(isSpace(c));
        benchmark::ClobberMemory();
      }
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}
static void
json_helper_isws(benchmark::State& state)
{
  auto [buf, fileSize] = readFile();
  // auto bytes =
  try
  {
    while( state.KeepRunning() )
    {
      // random float number
      for( auto c : buf )
      {
        // bool isws = json_helper::isWhiteSpace(c);
        // std::cout << isws << std::endl;
        benchmark::DoNotOptimize(json_helper::isWhiteSpace(c));
        benchmark::ClobberMemory();
      }
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}

static void
json_helper_isws_scalar(benchmark::State& state)
{
  auto [buf, fileSize] = readFile();
  // auto bytes =
  try
  {
    while( state.KeepRunning() )
    {
      // random float number
      for( auto c : buf )
      {
        benchmark::DoNotOptimize(json_helper::isScalarWhiteSpace(c));
        benchmark::ClobberMemory();
      }
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}

// BENCHMARK(std_isws)->ReportAggregatesOnly(true)->DisplayAggregatesOnly();
// BENCHMARK(simd_isws)->ReportAggregatesOnly(true)->DisplayAggregatesOnly();
// BENCHMARK(json_helper_isws)->ReportAggregatesOnly(true)->DisplayAggregatesOnly();
// BENCHMARK(json_helper_isws_scalar)->ReportAggregatesOnly(true)->DisplayAggregatesOnly();
