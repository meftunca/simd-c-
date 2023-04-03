
// #include <benchmark/benchmark.h>
// clang ignore
#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <memory>
#include <thread>
#include <vector>

#include <benchmark/benchmark.h>
#include <benchmark/export.h>
// #include "src/BlockAnalyzer.hpp"
// #include <tao/json.hpp>
#include "fastContains/package.hpp"
#include "simdjson.h"
#include "src/Astro.hpp"
#include "src/AstroSimd.hpp"
#include "src/JSONSerializer.hpp"
#ifdef __linux__
#  include <sys/resource.h>

size_t
getCurrentRSS()
{
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  return usage.ru_maxrss;
}

#elif __APPLE__
#  include <mach/mach_init.h>
#  include <mach/task.h>

size_t
getCurrentRSS()
{
  struct task_basic_info info;
  mach_msg_type_number_t size = sizeof(info);
  task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&info, &size);
  return info.resident_size;
}

#elif _WIN32
#  include <psapi.h>
#  include <windows.h>

size_t
getCurrentRSS()
{
  PROCESS_MEMORY_COUNTERS_EX pmc;
  GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS *)&pmc, sizeof(pmc));
  return pmc.WorkingSetSize;
}

#endif
// using json::JSON;
// using namespace simdjson;

static std::pair<std::string, size_t>
readFile()
{
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json";
  std::size_t       fileSize  = std::__fs::filesystem::file_size(kFilePath);
  // readData
  std::ifstream ifs(kFilePath, std::ios::binary);
  std::string   buf;
  // PRINT CURRENT CXX STANDARD
  // std::cout << ">> CXX STANDARD: " << __cplusplus << "\n";
  buf.resize(fileSize);
  ifs.read(buf.data(), static_cast<std::streamsize>(fileSize));
  return {buf, fileSize};
}

// static void JsonBlockAnalyzer(benchmark::State& state) {
//     const auto [buf, fileSize] = readFile();
//     // std::cout << ">> compute with: " << eve::current_api << "\n";
//     // std::cout << ">> eve::wide is: " << eve::wide<float>::size()
//     //           << " elements large.\n";
//     try {
//         for (auto _ : state) {
//             // json::JSON json;
//             // json.Load(buf);
//             devson::block_analyzer::Tokenizer blockAnalyzer(buf, fileSize);
//             // blockAnalyzer.parse();
//         }
//     } catch (std::exception& e) {
//         std::cout << e.what() << "\n\n";
//     }

//     // auto processedBytes = sizeof(float) * size * 3;

//     // state.SetItemsProcessed((state.iterations()) * bytes);
//     // state.SetBytesProcessed((state.iterations()) * bytes);
//     state.SetItemsProcessed(state.iterations() * fileSize);
//     state.SetBytesProcessed(state.iterations() * fileSize);
//     // state.SetBytesProcessed(state.bytes_processed());
//     state.counters["FileSize"] = static_cast<double>(fileSize);
// }

static void
JSON_Serializer(benchmark::State& state)
{
  const auto [buf, fileSize] = readFile();
  // std::cout << ">> compute with: " << eve::current_api << "\n";
  // std::cout << ">> eve::wide is: " << eve::wide<float>::size()
  //           << " elements large.\n";
  try
  {
    while( state.KeepRunning() )
    // while( state.KeepRunning() )
    {
      devson::serializer::Tokenizer blockAnalyzer(buf);
      benchmark::DoNotOptimize(blockAnalyzer.parse());
      // auto json = blockAnalyzer.parse();
      // astro::Stringifier stringifier;
      // std::string        stringify = stringifier.stringify(json);
      // std::cout << stringifier.stringify(json) << "\n";
      // blockAnalyzer.parse();
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
fastContains(benchmark::State& state)
{
  const auto [buf, fileSize] = readFile();
  faster faster;
  faster.data = reinterpret_cast<uint8_t *>(const_cast<char *>(" \t\n\b\r\v\f;,"));
  faster.size = 6;
  // current used threads
  try
  {
    while( state.KeepRunning() )
    {
      for( auto i = 0; i < fileSize; i++ ) { benchmark::DoNotOptimize(faster.check(buf[i])); }
      // simdjson::ondemand::document doc = parser.iterate(
      //     json); // position a pointer at the beginning of the JSON data
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }

  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}
static void
SIMDJSON(benchmark::State& state)
{
  const auto [buf, fileSize] = readFile();

  // current used threads
  try
  {
    while( state.KeepRunning() )
    {
      simdjson::ondemand::parser parser;
      auto                       json = simdjson::padded_string(buf);

      benchmark::DoNotOptimize(parser.iterate(json));
      // simdjson::ondemand::document doc = parser.iterate(
      //     json); // position a pointer at the beginning of the JSON data
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }

  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}
//     12);

static void
AstroJSON(benchmark::State& state)
{
  const auto [buf, fileSize] = readFile();
  // std::cout << ">> compute with: " << eve::current_api << "\n";
  // std::cout << ">> eve::wide is: " << eve::wide<float>::size()
  //           << " elements large.\n";
  try
  {
    while( state.KeepRunning() )
    {
      astro::Array array     = {"devson2", 21, false, nullptr, "India"};
      astro::Value astroTest = astro::Object {std::map<std::string, astro::Value>({
          {"name", "devson2"},
          {"age", 21},
          {"isActive", false},
          {"seperated", nullptr},
          {"address", "India"},
          {"hobbies", array},
      })};
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
AstroSimdJSON(benchmark::State& state)
{
  const auto [buf, fileSize] = readFile();
  // std::cout << ">> compute with: " << eve::current_api << "\n";
  // std::cout << ">> eve::wide is: " << eve::wide<float>::size()
  //           << " elements large.\n";
  try
  {
    while( state.KeepRunning() )
    {
      astro_simd::Value loader;
      loader.simdLoad("/Users/devloops/Desktop/main_projects/json/bulker/twitter.json");
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
// BENCHMARK(JSON_Serializer);
// BENCHMARK(fastContains);
// BENCHMARK(SIMDJSON);
// BENCHMARK(AstroSimdJSON);

BENCHMARK_MAIN();
