#ifndef JSON_HELPER_HPP
#define JSON_HELPER_HPP
#include <eve/conditional.hpp>
#include <eve/memory.hpp>
#include <eve/module/algo.hpp>
#include <eve/module/core.hpp>
#include <eve/wide.hpp>

#include <cstdint>
#include <iostream>
#include <ranges>
#include <vector>
namespace json_helper
{

using wide_u4  = eve::wide<std::uint8_t, eve::fixed<4>>;
using wide_u8  = eve::wide<std::uint8_t, eve::fixed<8>>;
using wide_u16 = eve::wide<std::uint8_t, eve::fixed<16>>;
using wide_u32 = eve::wide<std::uint8_t, eve::fixed<32>>;
using wide_u64 = eve::wide<std::uint8_t, eve::fixed<64>>;

#define fill_16 (c) c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c

// JSON White Space Table
/*
  ' ': 0x20, '\t': 0x09, '\n': 0x0a, '\r': 0x0d, '\f': 0x0c, '\b': 0x08, '\v':
  0x0b, '\a': 0x07, '\0': 0x00 total count is 9
*/
static constexpr std::array<std::uint8_t, 9> whiteSpaceTable =
    {0x20, 0x09, 0x0a, 0x0d, 0x0c, 0x08, 0x0b, 0x07, 0x00};
inline bool
isScalarWhiteSpace(const std::uint8_t& c)
{
  switch( c )
  {
  case 0x20:
  case 0x09:
  case 0x0a:
  case 0x0d:
  case 0x0c:
  case 0x08:
  case 0x0b:
  case 0x07:
  case 0x00:
  case 0x3a:
  case 0x2c:
    // case ' ':
    // case '\t':
    // case '\n':
    // case '\r':
    // case '\f':
    // case '\b':
    // case '\v':
    // case '\a':
    // case '\0':
    // case ':':
    // case ',':
    return true;
  default: return false;
  }

  // return std::any_of(whiteSpaceTable.begin(), whiteSpaceTable.end(),
  //                    [c](auto x) { return x == c; });
}
static const wide_u32 spaceCharList {
    ' ',  '\t', '\n', '\r', '\f', '\b', '\v', '\a', ':',  ',',  '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

static const std::vector<uint8_t> spaceCharList2 = {
    ' ',
    '\t',
    '\n',
    '\r',
    '\f',
    '\b',
    '\v',
    '\a',
    ':',
    ',',

};
// 32, 9, 10, 13, 12, 8, 11, 7, 58, 44
inline bool
isCharExist(char c)
{
  for( auto& x : spaceCharList2 )
  {
    if( x == c ) { return true; }
  }
  // for( int i = 0; i < spaceCharList2.size(); i++ )
  // {
  //   if( spaceCharList2[i] == c ) { return true; }
  // }
  return false;
}
EVE_FORCEINLINE bool
isWhiteSpace(const std::uint8_t& c)
{
  wide_u32 mask {c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c,
                 c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c};
  return eve::any(spaceCharList == mask);
  // return eve::any(spaceCharList == c);
  // return eve::algo::any_of(whiteSpaceTable, [c](auto x) { return x == c; });
}

// JSON Number Table
/*
  '0': 0x30, '1': 0x31, '2': 0x32, '3': 0x33, '4': 0x34, '5': 0x35, '6': 0x36,
  '7': 0x37, '8': 0x38, '9': 0x39,
  '-': 0x2d, '+': 0x2b, '.': 0x2e, 'e': 0x65, 'E': 0x45,
  total count is 15
*/

static const wide_u16 numericTable {0x30,
                                    0x31,
                                    0x32,
                                    0x33,
                                    0x34,
                                    0x35,
                                    0x36,
                                    0x37,
                                    0x38,
                                    0x39,
                                    0x2d,
                                    0x2b,
                                    0x2e,
                                    0x65,
                                    0x45,
                                    0x00};

inline bool
isNumber(const std::uint8_t& c)
{
  return eve::any(numericTable == c);
  // wide_u16 fill_c {c, c, c, c, c, c, c, c, c, c, c, c, c, c, c, c};

  // return eve::first_true(numericTable == fill_c) != 0;
}

static const wide_u16 hexTable {0x30,
                                0x31,
                                0x32,
                                0x33,
                                0x34,
                                0x35,
                                0x36,
                                0x37,
                                0x38,
                                0x39,
                                0x41,
                                0x42,
                                0x43,
                                0x44,
                                0x45,
                                0x46};

inline bool
isHex(const std::uint8_t& c)
{
  return eve::any(hexTable == c);
}

// JSON String Escape Table
/*
    "\"" => 0x22
    "\\" => 0x5c
    "\/" => 0x2f
    "\b" => 0x62
    "\f" => 0x66
    "\n" => 0x6e
    "\r" => 0x72
    "\t" => 0x74
    "\u" => 0x75

*/
static const wide_u16 stringEscapeTable {0x22,
                                         0x5c,
                                         0x2f,
                                         0x62,
                                         0x66,
                                         0x6e,
                                         0x72,
                                         0x74,
                                         0x75,
                                         0x00,
                                         0x00,
                                         0x00,
                                         0x00,
                                         0x00,
                                         0x00,
                                         0x00};

inline bool
isStringEscape(const std::uint8_t& c)
{
  // return eve::algo::find(stringEscapeTable, c) != stringEscapeTable.end();
  return eve::any(stringEscapeTable == c);
}

// JSON NULL Table
/*
  'n': 0x6e, 'u': 0x75, 'l': 0x6c,
  total count is 3
*/

static const wide_u16 nullTable {0x6e,
                                 0x75,
                                 0x6c,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00};

inline bool
isNull(const std::uint8_t& c)
{
  // return eve::algo::find(nullTable, c) != nullTable.end();
  return eve::any(nullTable == c);
}

// JSON TRUE Table
/*
  't': 0x74, 'r': 0x72, 'u': 0x75, 'e': 0x65,
  total count is 4
*/
static const wide_u16 trueTable {0x74,
                                 0x72,
                                 0x75,
                                 0x65,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00,
                                 0x00};

inline bool
isTrue(const std::uint8_t& c)
{
  // return eve::algo::find(trueTable, c) != trueTable.end();
  return eve::any(trueTable == c);
}

// JSON FALSE Table
/*
  'f': 0x66, 'a': 0x61, 'l': 0x6c, 's': 0x73, 'e': 0x65,
  total count is 5
*/

static const wide_u16 falseTable {0x66,
                                  0x61,
                                  0x6c,
                                  0x73,
                                  0x65,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00};

inline bool
isFalse(const std::uint8_t& c)
{
  return eve::any(falseTable == c);
}

// JSON Object Table
/*
  '{': 0x7b, '}': 0x7d, ':': 0x3a, ',': 0x2c,
  total count is 4
*/

// static std::vector<char> objectTable = {0x7b, 0x7d, 0x3a, 0x2c};
static const wide_u16 objectTable {0x7b,
                                   0x7d,
                                   0x3a,
                                   0x2c,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00,
                                   0x00};

inline bool
isObject(const std::uint8_t& c)
{
  // return eve::algo::find(objectTable, c) != objectTable.end();
  return eve::any(objectTable == c);
}

// JSON Array Table
/*
  '[': 0x5b, ']': 0x5d, ',': 0x2c,
  total count is 3
*/
// static std::vector<char> arrayTable = {0x5b, 0x5d, 0x2c};
static const wide_u16 arrayTable {0x5b,
                                  0x5d,
                                  0x2c,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00,
                                  0x00};

inline bool
isArray(const std::uint8_t& c)
{
  return eve::any(arrayTable == c);
}

static const std::vector<std::uint8_t> nullTable_4 {0x6e, 0x75, 0x6c, 0x6c};
inline bool
fastStrIteratorNullCompare(std::string_view::const_iterator& str)
{
  std::vector<std::uint8_t> strTable {
      static_cast<std::uint8_t>(*str),
      static_cast<std::uint8_t>(*(str + 1)),
      static_cast<std::uint8_t>(*(str + 2)),
  };
  // return strTable == nullTable_4;
  return eve::algo::equal(strTable, nullTable_4);
}

static const std::vector<std::uint8_t> trueTableV {0x74, 0x72, 0x75, 0x65};

inline bool
fastStrIteratorTrueCompare(std::string_view::const_iterator& str)
{
  std::vector<std::uint8_t> strTable {static_cast<std::uint8_t>(*str),
                                      static_cast<std::uint8_t>(*(str + 1)),
                                      static_cast<std::uint8_t>(*(str + 2)),
                                      static_cast<std::uint8_t>(*(str + 3))};
  return eve::algo::equal(strTable, trueTableV);
  // return strTable == trueTable;
}

static const std::vector<std::uint8_t> falseTableV {0x66, 0x61, 0x6c, 0x73};

inline bool
fastStrIteratorFalseCompare(std::string_view::const_iterator& str)
{
  std::vector<std::uint8_t> strTable {static_cast<std::uint8_t>(*str),
                                      static_cast<std::uint8_t>(*(str + 1)),
                                      static_cast<std::uint8_t>(*(str + 2)),
                                      static_cast<std::uint8_t>(*(str + 3))};
  return eve::algo::equal(strTable, falseTableV);
  // return strTable == falseTable;
}

} // namespace json_helper
#endif // JSON_HELPER_H_