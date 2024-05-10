
// #include <benchmark/benchmark.h>
// clang ignore
#include <benchmark/benchmark.h>
#include <benchmark/export.h>
#include <sys/resource.h>
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

// #include "src/BlockAnalyzer.hpp"
// #include <tao/json.hpp>

template <typename T>
struct CountingAllocator : std::allocator<T> {
  T* allocate(std::size_t n) {
    count_ += n;
    return std::allocator<T>::allocate(n);
  }
  void deallocate(T* p, std::size_t n) {
    count_ -= n;
    std::allocator<T>::deallocate(p, n);
  }

  static std::size_t count_;
};

template <typename T>
std::size_t CountingAllocator<T>::count_ = 0;

inline std::pair<std::string, size_t> readFile() {
  const std::string kFilePath =
      "/Users/mapletechnologies/Desktop/big_projects/simd/bulker/twitter.json";
  std::size_t fileSize = std::__fs::filesystem::file_size(kFilePath);
  // readData
  std::ifstream ifs(kFilePath, std::ios::binary);
  std::string buf;
  // PRINT CURRENT CXX STANDARD
  // std::cout << ">> CXX STANDARD: " << __cplusplus << "\n";
  buf.resize(fileSize);
  ifs.read(buf.data(), static_cast<std::streamsize>(fileSize));
  return {buf, fileSize};
}

inline std::pair<std::uint8_t*, size_t> readAlignedFile() {
  const std::string kFilePath =
      "/Users/mapletechnologies/Desktop/big_projects/simd/bulker/twitter.json";
  std::size_t fileSize = std::__fs::filesystem::file_size(kFilePath);
  // readData
  std::ifstream ifs(kFilePath, std::ios::binary);
  std::uint8_t* buf;
  if (posix_memalign(reinterpret_cast<void**>(&buf), 32, fileSize) != 0) {
    std::cout << ">> posix_memalign failed\n";
    exit(1);
  }
  ifs.read(reinterpret_cast<char*>(buf),
           static_cast<std::streamsize>(fileSize));
  return {buf, fileSize};
}

BENCHMARK_MAIN();
// int main(int argc, char* argv[]) {
//   ::benchmark::Initialize(&argc, argv);
//   if (::benchmark::ReportUnrecognizedArguments(argc, argv))
//     return 1;

//   // TestMemoryManager'ınızın bir örneğini oluşturun ve kaydedin.
//   TestMemoryManager* myMemoryManager = new TestMemoryManager();
//   ::benchmark::RegisterMemoryManager(myMemoryManager);

//   ::benchmark::RunSpecifiedBenchmarks();
//   // benchmark::Initialize(&argc, argv);
//   // std::unique_ptr<benchmark::MemoryManager> mm(new TestMemoryManager());
//   // benchmark::RunSpecifiedBenchmarks();

//   // benchmark::RegisterMemoryManager(mm.get());
//   // // RunOutputTests(argc, argv);
//   // benchmark::RegisterMemoryManager(nullptr);
//   // benchmark::Shutdown();
// }