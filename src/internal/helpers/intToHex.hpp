#pragma once

#include <sstream>
#include <string>
namespace bon::internal::helper {
/* 
    * Convert int to hex
        * @param int
        * @param int16_t
        * @param int32_t
        * @param int64_t
        * @param uint16_t
        * @param uint64_t
        * @return std::vector<std::uint8_t>
        * @example
        *  intToHex(1) -> 0x01
 */

/// @brief
/// @tparam T
/// @param value
/// @return
template <typename T>
inline std::string intToHex(T& value) {
  std::stringstream ss;
  ss << std::hex << value;
  std::string res(ss.str());
  return res;
}

}  // namespace bon::internal::helper