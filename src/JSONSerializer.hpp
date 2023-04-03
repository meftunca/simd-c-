#pragma once
// Set default compiler cxxopt optimization flags
#pragma pack(1)

#include <algorithm>
#include <complex>
// #include <eve/wide.hpp>
#include <iostream>
#include <iterator>
#include <memory>
#include <ranges>

#include <string_view>
// #include <tao/json.hpp>
// #include <tao/json/contrib/traits.hpp>
#include "Astro.hpp"
#include "JSONHelper.hpp"
#include "PerformanceLogger.hpp"
// #include "simdTool.hpp"

#include <vector>
// compiler optimize flags

#define JSON_MAX_DEPTH                   32
#define ANALYZER_NO_OPTIMIZE             __attribute__((optnone))
#define ANALYZER_NO_OPTIMIZE_INLINE      __attribute__((noinline, optnone))
#define ANALYZER_NO_OPTIMIZE_INLINE_SIZE __attribute__((noinline, optnone, optimize("Os")))
#define ANALYZER_NO_RETURN               __attribute__((noreturn))
#define ANALYZER_ALWAYS_INLINE           __attribute__((always_inline))
#define ANALYZER_CONST                   __attribute__((const))
#define ANALYZER_UNUSED                  __attribute__((unused), __warn_unused_result__, __nonnull__)
#define ANALYZER_PACKED                  __attribute__((packed))
#define ANALYZER_PACKED_4                __attribute__((packed, __aligned__(4)))
#define ANALYZER_PACKED_ALIGNES(x)       __attribute__((packed, __aligned__(x)))
#define ANALYZER_RESTRICT                __restrict__
#define ANALYZER_LIKELY(x)               __builtin_expect(!!(x), 1)

namespace devson
{
namespace serializer
{

  // std::mutex parserMutex11;

  /* UTILS */

  /**
   * JSON type identifier. Basic types are:
   * 	o Object
   * 	o Array
   * 	o String
   * 	o Other primitive: number, boolean (true/false) or null
   */

  /**
   * JSON token with constants.
   */

  using JSON_chr = enum {
    chr_Object          = 0x7b, //  0x7b
    chr_Object_Close    = 0x7d, // 0x7d
    chr_Array           = 0x5b, // 0x5b
    chr_Array_Close     = 0x5d, // 0x5d
    chr_String          = 0x22, // 0x22
    chr_Comma           = 0x2c, // 0x2c
    chr_Colon           = 0x3a, // 0x3a
    chr_EscapeBackslash = 0x5c, // 0x5c
  } ANALYZER_PACKED;

  // enum JSON_ERROR {
  //     /* Not enough tokens were provided */
  //     JSON_ERROR_NOMEM = -1,
  //     /* Invalid character inside JSON string */
  //     JSON_ERROR_INVAL = -2,
  //     /* The string is not a full JSON packet, more bytes expected */
  //     JSON_ERROR_PART = -3
  // };

  /**
   * JSON token description.
   * type		type (object, array, string etc.)
   * start	start positionition in JSON data string
   * end		end positionition in JSON data string
   */

  /**
   * Initialize given JSON parser instance.
   * @param parser	JSON parser to initialize.
   */

  class Tokenizer final
  {
    public:
    explicit Tokenizer(const std::string_view& strFrom) noexcept;
    explicit Tokenizer(const char *strFrom) noexcept;
    ~Tokenizer() noexcept         = default;
    explicit Tokenizer() noexcept = default;
    explicit Tokenizer(Tokenizer&& other) noexcept;
    explicit Tokenizer(const Tokenizer& other) noexcept;
    ANALYZER_ALWAYS_INLINE Tokenizer& operator=(Tokenizer&& other) noexcept;
    ANALYZER_ALWAYS_INLINE Tokenizer& operator=(const Tokenizer& other) noexcept;

    bool ANALYZER_ALWAYS_INLINE isEqual(const char&& c);
    void ANALYZER_ALWAYS_INLINE gotoNextChar(unsigned&& offset = 1) noexcept;
    void ANALYZER_ALWAYS_INLINE consumeWS() noexcept;

    bool ANALYZER_ALWAYS_INLINE fastCompare(const char *str1, const std::size_t& size) noexcept
    {
      return std::memcmp(str1, str.data() + tell(), size) == 0;
    };

    std::size_t tell() const noexcept { return std::distance(str.begin(), current); }
    /*
     * parse main wrapper
     */
    astro::Value ANALYZER_ALWAYS_INLINE parse();

    astro::Value ANALYZER_ALWAYS_INLINE  parseValue();
    void ANALYZER_ALWAYS_INLINE          skipParseValue();
    astro::Array ANALYZER_ALWAYS_INLINE  parseArray() noexcept;
    void ANALYZER_ALWAYS_INLINE          skipParseArray() /* ANALYZER_NO_RETURN */;
    astro::Object ANALYZER_ALWAYS_INLINE parseObject();
    void ANALYZER_ALWAYS_INLINE          skipParseObject() /* ANALYZER_NO_RETURN */;
    astro::String ANALYZER_ALWAYS_INLINE parseString() noexcept;
    void ANALYZER_ALWAYS_INLINE          skipParseString() /* ANALYZER_NO_RETURN */;
    astro::Number ANALYZER_ALWAYS_INLINE parseNumber() noexcept;
    void ANALYZER_ALWAYS_INLINE          skipParseNumber() /* ANALYZER_NO_RETURN */;

    private:
    ANALYZER_PACKED std::string_view str;
    std::string_view::const_iterator current;
    unsigned short                   depth = 0;
  };

  inline Tokenizer::Tokenizer(const std::string_view& strFrom) noexcept : str(strFrom)
  {
    // speed up vector
    current = str.cbegin();
  }

  inline Tokenizer::Tokenizer(const char *strFrom) noexcept : str(strFrom)
  {
    // speed up vector
    current = str.begin();
  }
  // destructor

  void ANALYZER_ALWAYS_INLINE inline Tokenizer::gotoNextChar(unsigned&& offset) noexcept
  {
    current += offset;
  }

  bool ANALYZER_ALWAYS_INLINE inline Tokenizer::isEqual(const char&& c) { return *current == c; }

  //
  void ANALYZER_ALWAYS_INLINE inline Tokenizer::consumeWS() noexcept
  {
    // while( isSpace(*current) && current != str.end() ) { current++; }
    // while( json_helper::isWhiteSpace(*current) && current != str.end() ) { current++; }
    while( json_helper::isScalarWhiteSpace(*current) && current != str.end() ) { current++; }
  }

  /*
   * parse main wrapper
   */
  astro::Value ANALYZER_ALWAYS_INLINE inline Tokenizer::parse()
  {
    if( current > str.end() )
    {
      // std::cout << "current > end: " << tell() << "," << str.size() <<
      // std::endl;
      throw std::runtime_error("Tokenizer::parse() - current >= str.end()");
      return 0;
    }
    auto value = parseValue();
    if( current != str.end() )
    {
      std::cout << "current != end: " << tell() << "," << str.size() << std::endl;
      throw std::runtime_error("Tokenizer::parse() - current != str.end()");
      return 0;
    }
    current = str.cbegin();
    return value;
  };

  /**
   * Parse the input text into an unescaped cstring, and populate item.
   */
  astro::Value ANALYZER_ALWAYS_INLINE inline Tokenizer::parseValue()
  {
    consumeWS();
    // switch( *current )
    // {
    // case chr_Array: return parseArray();
    // case chr_Object: return parseObject();
    // case chr_String: return parseString();
    // case 't':
    //   if( fastCompare("true", 4) ) { return (current += 4, true); };
    // case 'f':
    //   if( fastCompare("false", 5) ) { return (current += 5, false); };
    // case 'n':
    //   if( fastCompare("null", 4) ) { return (current += 4, nullptr); };
    // case '\0': return nullptr;
    // default:
    //   if( json_helper::isNumber(*current) ) { return parseNumber(); };
    // }
    // return nullptr;
    if( isEqual(chr_Array) ) { return parseArray(); }
    if( isEqual(chr_Object) ) { return parseObject(); }
    if( isEqual(chr_String) ) { return parseString(); }
    if( fastCompare("true", 4) )
    {
      current += 4;
      return true;
    }
    if( fastCompare("false", 5) )
    {
      current += 5;
      return false;
    }
    if( fastCompare("null", 4) )
    {
      current += 4;
      return nullptr;
    }
    if( json_helper::isNumber(*current) ) { return parseNumber(); }
    if( isEqual(chr_Object_Close) )
    {
      // current++;
      std::cout << "[PARSE_OBJECT_CLOSE] Error char at: " << *current << " is not equal to "
                << std::to_string(chr_String) << std::endl;
      throw std::runtime_error("Unexpected end of the object");
      return nullptr;
    }
    if( isEqual(chr_Array_Close) )
    {
      // current++;
      std::cout << "[PARSE_ARRAY_CLOSE] Error char at: " << *current << " is not equal to "
                << std::to_string(chr_String) << std::endl;
      throw std::runtime_error("Unexpected end of the array");
      return nullptr;
    }
    // consumeWS();
    std::cout << std::endl
              << "Error at: " << tell() << " : " << std::distance(str.begin(), str.end())
              << std::endl;
    throw std::runtime_error("Unknown value");
    return nullptr;
  };

  void ANALYZER_ALWAYS_INLINE inline Tokenizer::skipParseValue()
  {
    consumeWS();
    if( isEqual(chr_Array) ) { return skipParseArray(); }
    if( isEqual(chr_Object) ) { return skipParseObject(); }
    if( isEqual(chr_String) ) { return skipParseString(); }
    if( fastCompare("true", 4) )
    {
      current += 4;
      return;
    }
    if( fastCompare("false", 5) )
    {
      current += 5;
      return;
    }
    if( fastCompare("null", 4) )
    {
      current += 4;
      return;
    }
    if( json_helper::isNumber(*current) ) { return skipParseNumber(); }
    if( isEqual(chr_Object_Close) )
    {
      // current++;
      std::cout << "[SKIP_PARSE_OBJECT_CLOSE] Error char at: " << *current << " is not equal to "
                << std::to_string(chr_String) << std::endl;
      throw std::runtime_error("Unexpected end of the object");
      return;
    }
    if( isEqual(chr_Array_Close) )
    {
      std::cout << "[SKIP_PARSE_ARRAY_CLOSE] Error char at: " << *current << " is not equal to "
                << std::to_string(chr_String) << std::endl;
      throw std::runtime_error("Unexpected end of the array");
      return;
    }

    if( current == str.end() ) { return; }

    std::cout << std::endl
              << "Error at: " << tell() << " : " << std::distance(str.begin(), str.end())
              << std::endl;
    throw std::runtime_error("Unknown value");
    return;
  };

  /**
   * Parse the input text into an unescaped cstring, and populate item.
   */
  astro::Array ANALYZER_ALWAYS_INLINE inline Tokenizer::parseArray() noexcept
  {
    current++; // skip '['
    consumeWS();
    astro::Array arr;
    depth++;
    auto skip = depth > 0;
    while( !isEqual(chr_Array_Close) && current != str.end() )
    {
      if( skip )
      {
        // std::cout << "Skipping array" << std::endl;
        skipParseValue();
      }
      else { arr.Blocks.push_back(parseValue()); }
      consumeWS();
    }
    current++; // skip ']'
    depth--;
    consumeWS();
    return arr;
  };

  void ANALYZER_ALWAYS_INLINE inline Tokenizer::skipParseArray()
  {
    current++; // skip '['
    consumeWS();
    while( !isEqual(chr_Array_Close) && current != str.end() )
    {
      skipParseValue();
      consumeWS();
    }
    current++; // skip ']'
    consumeWS();
  };

  astro::Object ANALYZER_ALWAYS_INLINE inline Tokenizer::parseObject()
  {
    astro::Object obj;

    current++;
    consumeWS();
    depth++;
    auto skip = depth > 0;

    bool        isKey = true;
    std::string key;
    while( !isEqual(chr_Object_Close) && current != str.end() )
    {
      if( isKey )
      {
        if( *current != chr_String )
        {
          std::cout << "Error at: " << *current << ", Pos:" << tell() << std::endl;
          std::cout << "[PARSE_OBJECT] Error char at: " << *current << " is not equal to "
                    << static_cast<char>(chr_String) << std::endl;
          throw std::runtime_error("Key must be a string");
        }
        if( skip ) { skipParseString(); }
        else { key = parseString().value; }
        isKey = false;
        consumeWS();
      }
      // obj[key] = parseValue();
      if( skip ) { skipParseValue(); }
      else
      {
        obj.Blocks[key] = parseValue();
        // obj.Blocks.insert(std::pair<std::string, astro::Value>(key,
        // parseValue()));
      }
      if( isEqual(chr_Object_Close) ) { break; }
      isKey = true;
      consumeWS();
    }
    // current++;
    depth--;
    return obj;
  };

  void ANALYZER_ALWAYS_INLINE inline Tokenizer::skipParseObject()
  {
    current++;
    consumeWS();

    bool        isKey = true;
    std::string key;
    while( !isEqual(chr_Object_Close) && current != str.end() )
    // while( *current != chr_Object_Close && current != str.end() )
    {
      if( isKey )
      {
        if( *current != chr_String )
        {
          std::cout << "Error at: " << current << std::endl;
          std::cout << "[SKIP_PARSE_OBJECT] Error char at: " << *current << " is not equal to "
                    << static_cast<char>(chr_String) << std::endl;
          throw std::runtime_error("Key must be a string");
        }
        skipParseString();

        isKey = false;
        consumeWS();
      }
      // obj[key] = parseValue();
      skipParseValue();
      if( isEqual(chr_Object_Close) ) { break; }
      isKey = true;
      consumeWS();
    }
    // current++;
  };

  astro::Number ANALYZER_ALWAYS_INLINE inline Tokenizer::parseNumber() noexcept
  {
    // consumeWS();
    astro::Number num;
    // std::string   number_str;
    auto pos = tell();
    while( json_helper::isNumber(*current) && current != str.end() )
    {
      // number_str += *current;
      current++;
    }
    std::string_view number_str = str.substr(pos, tell() - pos);
    // consumeWS();
    if( number_str.empty() ) { return 0; }
    num = std::stod(number_str.data());
    return num;
  };

  void ANALYZER_ALWAYS_INLINE inline Tokenizer::skipParseNumber()
  {
    while( json_helper::isNumber(*current) && current != str.end() ) { current++; }
  };

  astro::String ANALYZER_ALWAYS_INLINE inline Tokenizer::parseString() noexcept
  {
    current++; // skip "
    auto pos = tell();
    // std::string json_string = "";

    while( !isEqual(chr_String) && current != str.end() )
    {
      if( isEqual('\\') )
      {
        current++;
        switch( *current )
        {
        case 'b':
        case 'f':
        case 'n':
        case 'r':
        case 't':
        case 'v':
        case '/':
        case '\\': current++; break;
        case 'u':
          // for( int i = 0; i < 4; i++ ) { current++; }
          current += 4;
          break;
        default: break;
        }
        // current++;
      }
      else { current++; }
      // else { json_string += *current; }
    }
    // auto end = tell() - 1;
    auto end = tell() - pos;
    // if (isEqual(chr_String))
    auto json_string = str.substr(pos, end);
    return json_string;
  }

  void ANALYZER_ALWAYS_INLINE inline Tokenizer::skipParseString()
  {
    current++; // skip "
    // auto pos = tell();

    while( !isEqual(chr_String) && current != str.end() )
    {
      if( isEqual('\\') )
      {
        current++;
        switch( *current )
        {
        case 'b':
        case 'f':
        case 'n':
        case 'r':
        case 't':
        case 'v':
        case '/':
        case '\\': current++; break;
        case 'u':
          // for( int i = 0; i < 4; i++ ) { current++; }
          current += 4;
          break;
        default: break;
        }
      }
      else { current++; }
    }

    // if (isEqual(chr_String))
    // json_string = str.substr(pos, end);
  }
} // namespace serializer
} // namespace devson
