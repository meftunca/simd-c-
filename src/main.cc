#include "JSONSerializer.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>

int
main()
{
  const std::string kFilePath = "/Users/devloops/Desktop/main_projects/json/bulker/bins.json";

  char           *buf;
  std::ifstream   ifs(kFilePath, std::ios::binary | std::ios::ate);
  std::streamsize size = ifs.tellg();
  ifs.seekg(0, std::ios::beg);
  buf = new char[size];
  ifs.read(buf, size);
  ifs.close();

  devson::serializer::Tokenizer blockAnalyzer(buf);
  blockAnalyzer.parse();

  return 0;
}