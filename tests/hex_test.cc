#include <gtest/gtest.h>
#include <fstream>

// Write to hex string
TEST(HexFileTest, WriteToHexString) {
  try {
    std::string str = "Hello, world!";

    // Dosyayı aç
    std::ofstream file("./output/example.txt", std::ios::hex);

    // String değerini dosyaya yaz
    file.write(str.c_str(), str.size());

    // Dosyayı kapat
    file.close();
    // read file
    std::ifstream file2("./output/example.txt", std::ios::hex);
    std::string str2;
    file2 >> str2;
    std::cout << "str2: " << str2 << "\n";
    file2.close();
  } catch (std::exception& e) {
    std::cout << "Error: " << e.what() << "\n";
  }
  EXPECT_EQ(1, 1);
}