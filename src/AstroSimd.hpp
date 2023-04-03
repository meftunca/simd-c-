#ifndef ASTRO_SIMD_HPP
#define ASTRO_SIMD_HPP
// Astro is new generation json dom api

#include "simdjson.h"

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace astro_simd
{

/*
  @brief Type is a enum class that can hold any type of value
*/
enum class Type { Null, Bool, Number, String, Array, Object };
/*
  @brief NumericType is a variant type that can hold any type of numeric value
*/
using NumericType = std::variant<int, float, uint64_t, double, long, long long, long double>;
/*
  @brief Value is a variant type that can hold any type of value
*/
class Array;
class Number;
class Object;
class Value;
// !TODO NativeArray is not used yet
// class NativeArray : public std::vector<Value> {};
class Number final
{
  public:
  Number()              = default;
  Number(const Number&) = default;
  Number(Number&&)      = default;
  Number(const NumericType& num) : value(num) {};
  Number(const double& num) : value(num) {};
  Number(const int& num) : value(num) {};
  Number(const uint64_t& num) : value(num) {};
  Number(const float& num) : value(num) {};
  Number(const long& num) : value(num) {};
  Number(const long long& num) : value(num) {};
  Number& operator=(const Number&) = default;
  Number& operator=(Number&&)      = default;
  Number& operator=(const NumericType& num)
  {
    value = num;
    return *this;
  };
  Number& operator=(const double& num)
  {
    value = num;
    return *this;
  };
  Number& operator=(const int& num)
  {
    value = num;
    return *this;
  };
  Number& operator=(const float& num)
  {
    value = num;
    return *this;
  };
  Number& operator=(const long& num)
  {
    value = num;
    return *this;
  };
  Number& operator=(const long long& num)
  {
    value = num;
    return *this;
  };
  ~Number() = default;
  NumericType value;
};

class String final
{
  public:
  String()                         = default;
  String(const String&)            = default;
  String(String&&)                 = default;
  String& operator=(const String&) = default;
  String& operator=(String&&)      = default;
  String(const std::string& str) : value(str) {};
  String(const std::string_view& str) : value(str) {};
  String(const char *str) : value(str) {};
  ~String() = default;
  String& operator=(const std::string& str)
  {
    value = str;
    return *this;
  };
  String& operator=(const std::string_view& str)
  {
    value = str;
    return *this;
  };
  String& operator=(const char *str)
  {
    value = str;
    return *this;
  };

  std::string value;
};

class Array final
{
  public:
  Array()                        = default;
  Array(const Array&)            = default;
  Array(Array&&)                 = default;
  Array& operator=(const Array&) = default;
  Array& operator=(Array&&)      = default;
  //   consturct with std::vector
  Array(const std::vector<Value>& vec) : Blocks(vec) { countElements = vec.size(); };
  Array(simdjson::dom::element domy)
  {
    isParsed   = false;
    domElement = &domy;
  };

  /**
   * @brief Construct a new Array object
   * Example:
   * Array arr = {1,2,3,4,5};
   */
  Array(const std::initializer_list<Value>& vec) : Blocks(vec) { countElements = vec.size(); };

  Array& operator=(const std::vector<Value>&& vec)
  {
    Blocks        = vec;
    countElements = vec.size();
    return *this;
  };

  Array& operator=(const std::initializer_list<Value>& list)
  {
    Blocks        = list;
    countElements = list.size();
    return *this;
  };

  ~Array() = default;
  // object start end around string values
  std::vector<Value> Blocks;
  std::size_t        countElements = 0;

  inline bool             isParseCompleted() const { return isParsed; };
  inline std::string_view getDomString() const
  {
    if( domElement == nullptr ) { throw std::runtime_error("domElement is nullptr"); }
    std::cout << "Array Type Is: " << domElement->type() << std::endl;
    return domElement->get_string().value();
  };

  private:
  bool                    isParsed   = false;
  simdjson::dom::element *domElement = nullptr;
  void inline parse();
};

class Object final
{
  public:
  Object()                         = default;
  Object(const Object&)            = default;
  Object(Object&&)                 = default;
  Object& operator=(const Object&) = default;
  Object& operator=(Object&&)      = default;
  // consturct with std::map
  Object(const std::map<std::string, Value>& map) : Blocks(map) { countElements = map.size(); };
  Object(simdjson::dom::element map)
  {
    isParsed      = false;
    domElement    = &map;
    countElements = map.get_object().size();
  };

  Object& operator=(const std::map<std::string, Value> map)
  {
    Blocks        = map;
    countElements = map.size();
    return *this;
  };
  Object& operator=(std::map<std::string, Value>&& map)
  {
    Blocks        = map;
    countElements = map.size();
    return *this;
  };
  Object& operator=(std::map<std::string, Value>& map)
  {
    Blocks        = map;
    countElements = map.size();
    return *this;
  };
  ~Object() = default;
  // operators
  // object start end around string values
  std::map<std::string, Value> Blocks;
  std::size_t                  countElements = 0;

  inline bool             isParseCompleted() const { return isParsed; };
  inline std::string_view getDomString() const
  {
    if( domElement == nullptr ) { throw std::runtime_error("domElement is nullptr"); }
    std::cout << "Object Type Is: " << domElement->type() << std::endl;
    return domElement->get_c_str().value();
  };

  private:
  bool                    isParsed   = false;
  simdjson::dom::element *domElement = nullptr;
  void inline parse()
  {
    if( isParsed ) return;
    isParsed = true;
    if( domElement == nullptr ) return;
    if( !domElement->is_array() ) return;
    for( auto&& element : domElement->get_object() )
    {
      auto key = element.key;
      switch( element.value.type() )
      {
      case simdjson::dom::element_type::INT64:
        Blocks.emplace(key, element.value.get_int64());
        break;
      case simdjson::dom::element_type::UINT64:
        Blocks.emplace(key, element.value.get_uint64());
        break;
      case simdjson::dom::element_type::DOUBLE:
        Blocks.emplace(key, element.value.get_double());
        break;
      case simdjson::dom::element_type::STRING:
        Blocks.emplace(key, element.value.get_c_str());
        break;
      case simdjson::dom::element_type::BOOL: Blocks.emplace(key, element.value.get_bool()); break;
      case simdjson::dom::element_type::ARRAY: Blocks.emplace(key, Array {element.value}); break;
      case simdjson::dom::element_type::OBJECT: Blocks.emplace(key, Object {element.value}); break;
      case simdjson::dom::element_type::NULL_VALUE: Blocks.emplace(key, nullptr); break;
      default: break;
      }
    };
  };
};

// phony answer for forward declaration bug
void inline Array::parse()
{
  if( isParsed ) return;
  isParsed = true;
  if( domElement == nullptr ) return;
  if( !domElement->is_array() ) return;
  for( simdjson::dom::element&& element : domElement->get_array() )
  {
    switch( element.type() )
    {
    case simdjson::dom::element_type::INT64: Blocks.emplace_back(element.get_int64()); break;
    case simdjson::dom::element_type::UINT64: Blocks.emplace_back(element.get_uint64()); break;
    case simdjson::dom::element_type::DOUBLE: Blocks.emplace_back(element.get_double()); break;
    case simdjson::dom::element_type::STRING: Blocks.emplace_back(element.get_c_str()); break;
    case simdjson::dom::element_type::BOOL: Blocks.emplace_back(element.get_bool()); break;
    case simdjson::dom::element_type::ARRAY:
      Blocks.emplace_back(Array {
          element,
      });
      break;
    case simdjson::dom::element_type::OBJECT: Blocks.emplace_back(Object {element}); break;
    case simdjson::dom::element_type::NULL_VALUE: Blocks.emplace_back(nullptr); break;
    default: break;
    }
  }
}
class Value final
{
  public:
  Value()                        = default;
  Value(const Value&)            = default;
  Value(Value&&)                 = default;
  Value& operator=(const Value&) = default;
  Value& operator=(Value&&)      = default;

  // Member functions
  Value(String str) : type(Type::String) { value = str; };
  // from string
  Value(const std::string& str) : type(Type::String)
  {
    type  = Type::String;
    value = String {str};
  };
  // from char *
  Value(const char *str) : type(Type::String)
  {
    type  = Type::String;
    value = String {str};
  };
  // = string
  Value& operator=(const std::string& str)
  {
    type  = Type::String;
    value = String {str};
    return *this;
  };
  // = char *
  Value& operator=(const char *str)
  {
    type  = Type::String;
    value = String {str};
    return *this;
  };

  // from bool
  Value(const bool& b) : type(Type::Bool)
  {
    type  = Type::Bool;
    value = b;
  };
  // = bool
  Value& operator=(const bool& b)
  {
    type  = Type::Bool;
    value = b;
    return *this;
  };

  // from number
  Value(const Number& num) : type(Type::Number)
  {
    type  = Type::Number;
    value = num;
  };
  Value(const double& num) : type(Type::Number)
  {
    type  = Type::Number;
    value = Number {num};
  };
  Value(const int& num) : type(Type::Number)
  {
    type  = Type::Number;
    value = Number {num};
  };
  Value(const uint64_t& num) : type(Type::Number)
  {
    type  = Type::Number;
    value = Number {num};
  };
  Value(const float& num) : type(Type::Number)
  {
    type  = Type::Number;
    value = Number {num};
  };
  Value(const long& num) : type(Type::Number)
  {
    type  = Type::Number;
    value = Number {num};
  };
  Value(const long long& num) : type(Type::Number)
  {
    type  = Type::Number;
    value = Number {num};
  };
  // = number
  Value& operator=(const double& num)
  {
    type  = Type::Number;
    value = Number {num};
    return *this;
  };

  // from array
  Value(const Array& arr) : type(Type::Array)
  {
    type  = Type::Array;
    value = arr;
  };
  // = array
  Value& operator=(const Array& arr)
  {
    type  = Type::Array;
    value = arr;
    return *this;
  };
  Value& operator=(const std::vector<Value>& arr)
  {
    type  = Type::Array;
    value = Array {arr};
    return *this;
  };
  Value& operator=(std::vector<Value> arr)
  {
    type  = Type::Array;
    value = Array {arr};
    return *this;
  };

  // from object
  Value(const Object& obj) : type(Type::Object)
  {
    type  = Type::Object;
    value = obj;
  };
  // = object
  Value& operator=(const Object& obj)
  {
    type  = Type::Object;
    value = obj;
    return *this;
  };
  Value& operator=(const std::map<std::string, Value>& obj)
  {
    type  = Type::Object;
    value = Object {obj};
    return *this;
  };
  Value& operator=(std::map<std::string, Value> obj)
  {
    type  = Type::Object;
    value = Object {obj};
    return *this;
  };

  // from null
  Value(const nullptr_t& null) : type(Type::Null) { value = null; };
  // = null
  Value& operator=(const nullptr_t& null)
  {
    type  = Type::Null;
    value = null;
    return *this;
  };

  ~Value() = default;
  Type                                                         type;
  std::variant<nullptr_t, bool, Number, String, Array, Object> value {};
  // isRules
  inline bool       isNull() const { return std::holds_alternative<nullptr_t>(value); };
  inline bool       isBool() const { return std::holds_alternative<bool>(value); };
  inline bool       isNumber() const { return std::holds_alternative<Number>(value); };
  inline bool       isString() const { return std::holds_alternative<String>(value); };
  inline bool       isArray() const { return std::holds_alternative<Array>(value); };
  inline bool       isObject() const { return std::holds_alternative<Object>(value); }
  inline nullptr_t& getNull() { return std::get<nullptr_t>(value); };
  inline bool     & getBool() { return std::get<bool>(value); };
  inline Number   & getNumber() { return std::get<Number>(value); };
  inline String   & getString() { return std::get<String>(value); };
  inline Array    & getArray() { return std::get<Array>(value); };
  inline Object   & getObject() { return std::get<Object>(value); };
  // get any value

  template<class T> T& as() { return std::get<T>(value); };

  inline void simdLoad(std::string path)
  {
    simdjson::dom::parser  parser;
    simdjson::dom::element dom;
    auto                   error = parser.load(path).get(dom);
    if( error ) throw std::runtime_error("Error loading file");
    domElement = &dom;
    parse();
  }

  // Parse With SimdJSON
  private:
  bool                    isParsed   = false;
  simdjson::dom::element *domElement = nullptr;
  void inline parse()
  {
    if( isParsed ) return;
    isParsed = true;
    if( domElement == nullptr ) return;
    switch( type )
    {
    case Type::Null: break;
    case Type::Bool: value = domElement->get_bool().take_value(); break;
    case Type::Number:

      if( domElement->is_int64() ) { value = domElement->get_int64().take_value(); }
      else if( domElement->is_uint64() ) { value = domElement->get_uint64().value(); }
      else if( domElement->is_double() ) { value = domElement->get_double().take_value(); }
      break;
    case Type::String: value = domElement->get_string().value(); break;
    case Type::Array: value = Array {*domElement}; break;
    case Type::Object: value = Object {*domElement}; break;
    default: break;
    }
  }
};

// struct Parser final {
//   Parser() = default;
//   Parser(const Parser &) = default;
//   Parser(Parser &&) = default;
//   Parser &operator=(const Parser &) = default;
//   Parser &operator=(Parser &&) = default;
//   ~Parser() = default;
//   std::string::const_iterator begin;
//   std::string::const_iterator end;
//   Value parse() = {};
//   Value parse_next() = {};
//   void consume_ws();
//   Value parse_string() = {};
//   Value parse_number() = {};
//   Value parse_object() = {};
//   Value parse_array() = {};
//   Value parse_bool() = {};
//   Value parse_null() = {};
// };

struct Stringifier final
{
  Stringifier()                              = default;
  Stringifier(const Stringifier&)            = default;
  Stringifier(Stringifier&&)                 = default;
  Stringifier& operator=(const Stringifier&) = default;
  Stringifier& operator=(Stringifier&&)      = default;
  ~Stringifier()                             = default;
  std::string stringify(Value& value)
  {
    switch( value.type )
    {
    case Type::String: return stringify_string(value);
    case Type::Number: return stringify_number(value);
    case Type::Object: return stringify_object(value);
    case Type::Array: return stringify_array(value);
    case Type::Bool: return stringify_bool(value);
    case Type::Null:
      // return stringify_null(value);
      return stringify_null();
    default: return "";
    }
  };
  std::string stringify_string(const Value& value)
  {
    return "\"" + std::get<String>(value.value).value + "\"";
  };
  std::string stringify_number(const Value& value)
  {
    auto vv = std::get<Number>(value.value).value;
    if( std::holds_alternative<int>(vv) ) { return std::to_string(std::get<int>(vv)); }
    else if( std::holds_alternative<float>(vv) ) { return std::to_string(std::get<float>(vv)); }
    else if( std::holds_alternative<long>(vv) ) { return std::to_string(std::get<long>(vv)); }
    else if( std::holds_alternative<long long>(vv) )
    {
      return std::to_string(std::get<long long>(vv));
    }
    else if( std::holds_alternative<double>(vv) ) { return std::to_string(std::get<double>(vv)); }
    else if( std::holds_alternative<long double>(vv) )
    {
      return std::to_string(std::get<long double>(vv));
    }
    else { return "0"; }
  };
  std::string stringify_object(Value& value)
  {
    std::cout << "stringify_object" << std::endl;
    auto obj = value.getObject();

    if( !obj.isParseCompleted() )
    {
      std::cout << "Str Object: " << std::string(obj.getDomString()) << std::endl;
      return std::string(obj.getDomString());
    }

    std::string result = "{";
    for( auto& pair : std::get<Object>(value.value).Blocks )
    {
      result += "\"" + pair.first + "\":" + stringify(pair.second) + ",";
    }
    if( result.back() == ',' ) { result.pop_back(); }
    result += "}";
    return result;
  };
  std::string stringify_array(Value& value)
  {
    std::cout << "stringify_array" << std::endl;
    auto arr = value.getArray();
    if( !arr.isParseCompleted() )
    {
      std::cout << "Str Array: " << std::string(arr.getDomString()) << std::endl;
      return std::string(arr.getDomString());
    }
    std::string result = "[";
    for( auto& item : std::get<Array>(value.value).Blocks ) { result += stringify(item) + ","; }
    if( result.back() == ',' ) { result.pop_back(); }
    result += "]";
    return result;
  };
  std::string stringify_bool(const Value& value)
  {
    return std::get<bool>(value.value) ? "true" : "false";
  };
  std::string stringify_null() { return "null"; };
};

} // namespace astro

#endif