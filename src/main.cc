#include <fstream>
#include <ios>
#include <iostream>
#include <thread>
// #include "gperftools/profiler.h"
#include "internal/helpers/stringToHex.hpp"
#include "package.hpp"

int main() {
  // ProfilerStart("./output/cpu_profile.prof");
  std::ofstream file("./output/example.txt", std::ios::binary);
  std::string str = "Hello, world!";  // initialize the vector
  internal::helpers::string_to_hex::ByteBuffer mybuffer(str.begin(), str.end());

  // hexlify; now we have a string of hex representations of the original ByteBuffer
  std::string stringResult =
      internal::helpers::string_to_hex::hexlify(mybuffer);
  std::cout << "Hexlifyed: " << stringResult << std::endl;
  // String değerini dosyaya yaz
  file.write(stringResult.c_str(), stringResult.size());

  // Dosyayı kapat
  file.close();
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  // ProfilerStop();
  return 0;
}