#pragma once
/**
 * Info Page Header (Start of 0x00, endof 0x00)
 * Encoding: 0x01 0x(UTF-8 hex value)
 * Bon Version: 0x02 0x(Version hex value)
 * Revision: 0x03 0x(Revision hex value)
 * Total Body Row Count: 0x04 0x(Count hex value)
 * Total Body Size: 0x05 0x(Size hex value)
 * Compression Algorithm: 0x06 0x(Algorithm hex value) (is Compressed 0x01, is not compressed 0x00)
 * Example Page Header [stop = 0x00]
    * 0x01 0x75 0x74 0x66 0x2d 0x38 0x00 0x02 0x30 0x2e 0x31 0x00 0x03 0x30 0x2e 0x31 0x00 0x04 0x00 0x00 0x00 0x00 0x05 0x00 0x00 0x00 0x00 0x06 0x00 0x00 0x00 0x00
*/
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include "../../enums.hpp"
namespace bon::internal::page {
struct Compression {
  bon::enums::CompressionAlgorithm algorithm;
  bon::enums::CompressionLevel level;
  bool isCompressed;
};
class Header {
 public:
  Header(std::string_view encoding, std::string_view bon_version,
         std::uint16_t revision, std::uint16_t rowCount, std::uint16_t bodySize,
         Compression compression)
      : encoding_(encoding),
        bon_version_(bon_version),
        revision_(revision),
        rowCount_(rowCount),
        bodySize_(bodySize),
        compression_(compression) {}
  Header() = default;
  ~Header() = default;

  // GetX
  [[nodiscard]] std::string_view Encoding() const { return encoding_; }
  [[nodiscard]] std::string_view BonVersion() const { return bon_version_; }
  [[nodiscard]] std::uint16_t Revision() const { return revision_; }
  [[nodiscard]] std::uint16_t RowCount() const { return rowCount_; }
  [[nodiscard]] std::uint16_t BodySize() const { return bodySize_; }
  [[nodiscard]] Compression Compression() const { return compression_; }

  // SetX
  void setEncoding(std::string_view encoding) { encoding_ = encoding; }
  void setBonVersion(std::string_view bon_version) {
    bon_version_ = bon_version;
  }
  void setRevision(std::uint16_t revision) { revision_ = revision; }
  void setRowCount(std::uint16_t rowCount) { rowCount_ = rowCount; }
  void setBodySize(std::uint16_t bodySize) { bodySize_ = bodySize; }
  void setCompression(const struct Compression& compression) {
    compression_ = compression;
  }

  // Operators
  bool operator==(const Header& rhs) const {
    return encoding_ == rhs.encoding_ && bon_version_ == rhs.bon_version_ &&
           revision_ == rhs.revision_ && rowCount_ == rhs.rowCount_ &&
           bodySize_ == rhs.bodySize_ &&
           compression_.algorithm == rhs.compression_.algorithm &&
           compression_.level == rhs.compression_.level &&
           compression_.isCompressed == rhs.compression_.isCompressed;
  }

 private:
  std::string_view encoding_;
  std::string_view bon_version_;
  std::int16_t revision_;
  std::int16_t rowCount_;
  std::uint16_t bodySize_;
  struct Compression compression_;
};

inline std::string headerToHex(bon::internal::page::Header& header) {

  std::vector<std::uint8_t> buffer = {};
  buffer.reserve(64);      // default 64 bytes
  buffer.push_back(0x00);  //start header

  buffer.push_back(0x01);  //encoding
  for (const auto& c : header.Encoding()) {
    buffer.push_back(static_cast<std::uint8_t>(c));
  }

  buffer.push_back(0x02);  //bon version
  for (const auto& c : header.BonVersion()) {
    buffer.push_back(static_cast<std::uint8_t>(c));
  }

  buffer.push_back(0x03);  //revision
  buffer.push_back((header.Revision() >> 8) & 0xFF);
  buffer.push_back(header.Revision() & 0xFF);

  buffer.push_back(0x04);  //row count
  buffer.push_back((header.RowCount() >> 8) & 0xFF);
  buffer.push_back(header.RowCount() & 0xFF);

  buffer.push_back(0x05);  //body size
  buffer.push_back((header.BodySize() >> 8) & 0xFF);
  buffer.push_back(header.BodySize() & 0xFF);

  buffer.push_back(0x06);  //compression algorithm
  buffer.push_back(header.Compression().algorithm);

  buffer.push_back(0x07);  //compression level
  buffer.push_back(header.Compression().level);

  buffer.push_back(0x08);  //is compressed
  if (header.Compression().isCompressed) {
    buffer.push_back(0x01);
  } else {
    buffer.push_back(0x02);
  }

  buffer.push_back(0x00);  //end header

  std::stringstream ss;
  for (const auto& c : buffer) {
    std::cout << c << " ";
    ss << std::hex << static_cast<int>(c) << " ";
  }
  return ss.str();
  // std::stringstream ss;
  // ss << "01 " << header.Encoding() << " 02 " << header.BonVersion() << " 03 "
  //    << std::hex << header.Revision() << " 04 " << std::hex << header.RowCount()
  //    << " 05 " << std::hex << header.BodySize() << " 06 "
  //    << header.Compression().algorithm << " 07 " << header.Compression().level
  //    << " 08 " << header.Compression().isCompressed;
  // return ss.str();
}

inline void readHeaderFromHexContent(std::string_view&& content,
                                     bon::internal::page::Header& header) {
  std::stringstream ss(content.data());
  std::string item;
  std::vector<std::string> items;
  while (std::getline(ss, item, ' ')) {
    items.push_back(item);
  }
  header.setEncoding(items[1]);
  header.setBonVersion(items[3]);
  header.setRevision(std::stoi(items[5], nullptr, 16));
  header.setRowCount(std::stoi(items[7], nullptr, 16));
  header.setBodySize(std::stoi(items[9], nullptr, 16));
  header.setCompression(
      {static_cast<bon::enums::CompressionAlgorithm>(std::stoi(items[11])),
       static_cast<bon::enums::CompressionLevel>(std::stoi(items[13])),
       static_cast<bool>(std::stoi(items[15]))});
}

}  // namespace bon::internal::page