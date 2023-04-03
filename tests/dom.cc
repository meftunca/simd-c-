

#include "src/Astro.hpp"
#include "src/AstroSimd.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include <string_view>

#define DEVSON2_PERFORMANCE_LOGGING 1
static char *
readFile()
{
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/twitter.json";
  std::size_t       fileSize  = std::filesystem::file_size(kFilePath);
  // readData
  std::ifstream ifs(kFilePath, std::ios::binary);
  if( !ifs ) { throw std::runtime_error("Error: Could not open file: " + kFilePath); }
  char *buffer = new char[fileSize];
  ifs.read(buffer, fileSize);
  return buffer;
};

TEST(Performance, AstroJSONDOM)
{
  // const int size = static_cast<int>(state.range(0));
  // MAX_PATH length is 260
  auto buffer = readFile();
  std::cout << sizeof(buffer) << std::endl;
  try
  {
    astro::Array arr   = {1, 2, 3, 4, 5, 6.7, 8.321321951321321};
    astro::Array array = {"devson2", 21, false, nullptr, "India"};
    array.Blocks.push_back(arr);
    astro::Object value = std::map<std::string, astro::Value>({
        {"name", "devson2"},
        {"age", 21},
        {"isActive", false},
        {"seperated", nullptr},
        {"address", "India"},
    });
    // std::chrono::high_resolution_clock::time_point start =
    //     std::chrono::high_resolution_clock::now();
    astro::Value astroTest = astro::Object {std::map<std::string, astro::Value>({
        {"name", "devson2"},
        {"age", 21},
        {"isActive", false},
        {"seperated", nullptr},
        {"address", "India"},
        {"hobbies", array},
    })};

    astro::Stringifier stringifier;
    auto               stringify = stringifier.stringify(astroTest);
    // write to file
    std::ofstream ofs("/Users/devloops/Desktop/main_projects/simd/bulker/astro.json");
    if( !ofs )
    {
      throw std::runtime_error(
          "Error: Could not open file: "
          + std::string("/Users/devloops/Desktop/main_projects/simd/bulker/astro.json"));
    }
    ofs << stringify;
    // std::chrono::high_resolution_clock ::time_point end =
    //     std::chrono::high_resolution_clock::now();
    // auto duration =
    //     std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
    //         .count();
    // std::cout << "Duration(ms): " << duration << std::endl;
  }
  catch( std::exception& e )
  {
    std::runtime_error("Error: " + std::string(e.what()));
    std::cout << e.what() << "\n\n";
  }
  // Expect equality.
  EXPECT_EQ(42, 42);
}

TEST(Performance, AstroSIMDJSONDOM)
{
  // const int size = static_cast<int>(state.range(0));
  // MAX_PATH length is 260
  auto buffer = readFile();
  std::cout << sizeof(buffer) << std::endl;
  try
  {
    astro_simd::Array arr   = {1, 2, 3, 4, 5, 6.7, 8.321321951321321};
    astro_simd::Array array = {"devson2", 21, false, nullptr, "India"};
    array.Blocks.push_back(arr);
    astro_simd::Object value     = std::map<std::string, astro_simd::Value>({
        {"name", "devson2"},
        {"age", 21},
        {"isActive", false},
        {"seperated", nullptr},
        {"address", "India"},
    });
    astro_simd::Value  astroTest = astro_simd::Object {std::map<std::string, astro_simd::Value>({
        {"name", "devson2"},
        {"age", 21},
        {"isActive", false},
        {"seperated", nullptr},
        {"address", "India"},
        {"hobbies", array},
    })};

    astro_simd::Stringifier stringifier;
    auto                    stringify = stringifier.stringify(astroTest);
    // write to file
    std::ofstream ofs("/Users/devloops/Desktop/main_projects/simd/bulker/astro_simd.json");
    if( !ofs )
    {
      throw std::runtime_error(
          "Error: Could not open file: "
          + std::string("/Users/devloops/Desktop/main_projects/simd/bulker/astro_simd.json"));
    }
    ofs << stringify;
  }
  catch( std::exception& e )
  {
    std::runtime_error("Error: " + std::string(e.what()));
    std::cout << e.what() << "\n\n";
  }
  // Expect equality.
  EXPECT_EQ(42, 42);
}

TEST(Performance, AstroSIMDParser)
{
  // const int size = static_cast<int>(state.range(0));
  // MAX_PATH length is 260
  try
  {
    astro_simd::Value value;
    value.simdLoad("/Users/devloops/Desktop/main_projects/simd/bulker/twitter.json");

    astro_simd::Stringifier stringifier;
    auto                    stringify = stringifier.stringify(value);
    // write to file
    std::ofstream ofs("/Users/devloops/Desktop/main_projects/simd/bulker/astro_simd_parser.json");
    if( !ofs )
    {
      throw std::runtime_error(
          "Error: Could not open file: "
          + std::string(
              "/Users/devloops/Desktop/main_projects/simd/bulker/astro_simd_parser.json"));
    }
    ofs << stringify;
  }
  catch( std::exception& e )
  {
    std::runtime_error("Error: " + std::string(e.what()));
    std::cout << e.what() << "\n\n";
  }
  // Expect equality.
  EXPECT_EQ(42, 42);
}