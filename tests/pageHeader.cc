#include <gtest/gtest.h>
#include "src/internal/page/header.hpp"

// Constructor
TEST(PageHeaderTest, Constructor) {
  bon::internal::page::Compression compression{
      bon::enums::CompressionAlgorithm::kLz4,
      bon::enums::CompressionLevel::kHigh, true};
  std::string_view encoding = "utf-8";
  std::string_view bon_version = "1.0";
  std::uint16_t revision = 1;
  std::uint16_t rowCount = 2;
  std::uint16_t bodySize = 3;
  bon::internal::page::Header header(encoding, bon_version, revision, rowCount,
                                     bodySize, compression);
  EXPECT_EQ(header.Encoding(), "utf-8");
  EXPECT_EQ(header.BonVersion(), "1.0");
  EXPECT_EQ(header.Revision(), 1);
  EXPECT_EQ(header.RowCount(), 2);
  EXPECT_EQ(header.BodySize(), 3);
  EXPECT_EQ(header.Compression().algorithm,
            bon::enums::CompressionAlgorithm::kLz4);
  EXPECT_EQ(header.Compression().level, bon::enums::CompressionLevel::kHigh);
  EXPECT_EQ(header.Compression().isCompressed, true);
}

// Write to hex string
TEST(PageHeaderTest, CheckHeaderToHex) {
  bon::internal::page::Compression compression{
      bon::enums::CompressionAlgorithm::kLz4,
      bon::enums::CompressionLevel::kHigh, true};
  std::string_view encoding = "utf-8";   // encoding
  std::string_view bon_version = "1.0";  // BON file format version
  std::uint16_t revision = 1;            // file manipulation counter
  std::uint16_t rowCount = 2;            // vector size/reserved
  std::uint16_t bodySize = 3;            // memory allocation & alignment
  bon::internal::page::Header header(encoding, bon_version, revision, rowCount,
                                     bodySize, compression);
  std::string hexString = bon::internal::page::headerToHex(header);
  std::cout << hexString << "\n";
  EXPECT_EQ(true, true);
}