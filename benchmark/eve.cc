#include "src/EveTest.hpp"

#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>

#include <benchmark/benchmark.h>

static void
atan2Bench(benchmark::State& state)
{
  // auto bytes =
  try
  {
    for( auto _ : state )
    {
      // random float number
      float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
      float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
      theta(x, y);
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }
  auto fileSize = sizeof(float) * 2;
  // auto processedBytes = sizeof(float) * size * 3;

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}

static void
sqrtBench(benchmark::State& state)
{
  // auto bytes =
  try
  {
    for( auto _ : state )
    {
      // random float number
      float x = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
      float y = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
      rho(x, y);
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }
  auto fileSize = sizeof(float) * 2;
  // auto processedBytes = sizeof(float) * size * 3;

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}

static void
eveAtan2Bench(benchmark::State& state)
{
  // auto bytes =
  try
  {
    for( auto _ : state )
    {
      // random float number
      eve::wide<float> x {12.0, 13.5, 15.1, 16.5};
      eve::wide<float> y {19.5, 21.1, 22.5, 24};
      benchmark::DoNotOptimize(eve_theta(x, y));
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }
  auto fileSize = eve::wide<float>::size() * 2;
  // auto processedBytes = sizeof(float) * size * 3;

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}

static void
eveSqrtBench(benchmark::State& state)
{
  // auto bytes =
  try
  {
    for( auto _ : state )
    {
      // random float number
      eve::wide<float> x {12, 13.5, 15, 16.5};
      eve::wide<float> y {19.5, 21, 22.5, 24};
      benchmark::DoNotOptimize(eve_rho(x, y));
    }
  }
  catch( std::exception& e )
  {
    std::cout << e.what() << "\n\n";
  }
  auto fileSize = sizeof(float) * 2;
  // auto processedBytes = sizeof(float) * size * 3;

  // state.SetItemsProcessed((state.iterations()) * bytes);
  // state.SetBytesProcessed((state.iterations()) * bytes);
  state.SetItemsProcessed(state.iterations() * fileSize);
  state.SetBytesProcessed(state.iterations() * fileSize);
  // state.SetBytesProcessed(state.bytes_processed());
  state.counters["FileSize"] = static_cast<double>(fileSize);
}

BENCHMARK(atan2Bench)->Name("Standart atan2 Benchmark");
BENCHMARK(sqrtBench)->Name("Standart sqrt Benchmark");
BENCHMARK(eveAtan2Bench)->Name("Standart eveAtan2 Benchmark");
BENCHMARK(eveSqrtBench)->Name("Standart eveSqrt Benchmark");
