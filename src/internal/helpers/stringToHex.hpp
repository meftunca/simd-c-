#include <iostream>
#include <vector>

namespace internal::helpers::string_to_hex {
using uint8_t = unsigned char;
using ByteBuffer = std::vector<uint8_t>;
using ByteString = std::string;
const char kHex[] = "0123456789ABCDEF";

/*
=================================================================================
*/
inline int ascii2val(char c) {
  int iRetVal;

  if ((c >= '0') && (c <= '9')) {
    iRetVal = (c - '0');
  } else if ((c >= 'a') && (c <= 'f')) {
    iRetVal = (c - 'a' + 10);
  } else if ((c >= 'A') && (c <= 'F')) {
    iRetVal = (c - 'A' + 10);
  } else {
    iRetVal = 0;
  }

  return iRetVal;
}

/*
=================================================================================
*/
inline std::string hexlify(const ByteBuffer& InBuffer) {
  std::string OutBuffer(InBuffer.size() * 2 + 1, '\0');

  for (size_t i = 0; i < InBuffer.size(); ++i) {
    char* dest = &OutBuffer[i * 2];
    *dest++ = kHex[((InBuffer[i] >> 4) & 0xF)];
    *dest++ = kHex[(InBuffer[i] & 0xF)];
  }

  return OutBuffer;
}

/*
=================================================================================
*/
inline std::string hexlify(const ByteBuffer& InBuffer, size_t szStart,
                           size_t szNrElems) {
  std::string OutBuffer(szNrElems * 2 + 1, '\0');

  // don't read beyond the InBuffer border
  if (szStart + szNrElems > InBuffer.size()) {
    szNrElems = InBuffer.size() - szStart;
  }

  for (size_t i = 0; i < szNrElems; ++i) {
    char* dest = &OutBuffer[i * 2];
    *dest++ = kHex[((InBuffer[szStart + i] >> 4) & 0xF)];
    *dest++ = kHex[(InBuffer[szStart + i] & 0xF)];
  }

  return OutBuffer;
}

/*
=================================================================================
*/

inline ByteBuffer unhexlify(const std::string& InBuffer) {
  ByteBuffer OutBuffer(InBuffer.size() / 2 + 1);

  for (size_t i = 0, j = 0; i < InBuffer.size(); i += 2, ++j) {
    uint8_t* dest = &OutBuffer[j];
    *dest++ = (((ascii2val(InBuffer[i]) << 4) | (ascii2val(InBuffer[i + 1]))));
  }

  return OutBuffer;
}
}  // namespace internal::helpers::string_to_hex
