#pragma once

namespace bon::enums {

// Data File Type
enum FileType {
  kCollection = 0x01,
  kIndex = 0x02,
  kBulkData = 0x03,
  kStructured = 0x04,
  kUnstructured = 0x05,  // all in one
};

// Compression Algorithm
enum CompressionAlgorithm {
  kLz4 = 0x01,
  kZstd = 0x02,
};

// Compression Level
enum CompressionLevel {
  kMin = 0x01,     // so fast but worst compression
  kLow = 0x02,     // fast
  kMedium = 0x03,  // default
  kHigh = 0x04,    // slow
  kMax = 0x05,     // so slow but best compression
};

}  // namespace bon::enums