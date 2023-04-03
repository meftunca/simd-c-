
// #include "src/gason.hpp"
// #include "src/simdjsonToNlohman.hpp"
// #include "src/simdjsonToTao.hpp"
// #include "src/jsmn.hpp"
// #include "src/stix.hpp"
// #include "src/jsont.hh"
#include "src/Astro.hpp"
#include "src/JSONSerializer.hpp"
#include "src/PerformanceLogger.hpp"

#include <chrono>
#include <clocale>
#include <codecvt>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>
#include <unistd.h>
#include <vector>

#include <gtest/gtest.h>
#include <string_view>
#include <sys/fcntl.h>

// #define DEVSON2_PERFORMANCE_LOGGING 1
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
  return {buf, fileSize};
}
