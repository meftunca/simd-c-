#ifndef ASTRO_HPP
#define ASTRO_HPP
// Astro is new generation json dom api

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <variant>
#include <vector>

// #include "simdjson.h"

namespace astro
{

/*
  @brief Type is a enum class that can hold any type of value
*/
enum class Type { Null, Bool, Number, String, Array, Object };
/*
  @brief NumericType is a variant type that can hold any type of numeric value
*/
using NumericType = std::variant<int, float, double, long, long long, long double>;
/*
  @brief Value is a variant type that can hold any type of value
*/
struct Value;
// !TODO NativeArray is not used yet
// class NativeArray : public std::vector<Value> {};
struct Number final
{
  Number()              = default;
  Number(const Number&) = default;
  Number(Number&&)      = default;
  Number(const NumericType& num) : value(num) {};
  Number(const double& num) : value(num) {};
  Number(const int& num) : value(num) {};
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

struct String final
{
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

struct Array final
{
  Array()                        = default;
  Array(const Array&)            = default;
  Array(Array&&)                 = default;
  Array& operator=(const Array&) = default;
  Array& operator=(Array&&)      = default;
  //   consturct with std::vector
  Array(const std::vector<Value>& vec) : Blocks(vec) { countElements = vec.size(); };
  // Array(std::vector<Value> vec) : Blocks(vec) { countElements = vec.size();
  // }; Array(std::vector<Value> &&vec) : Blocks(vec) { countElements =
  // vec.size(); }; consturct with std::initializer_list
  /**
   * @brief Construct a new Array object
   * Example:
   * Array arr = {1,2,3,4,5};
   */
  Array(const std::initializer_list<Value>& vec) : Blocks(vec) { countElements = vec.size(); };
  // Array(std::initializer_list<Value> vec) : Blocks(vec) {
  //   countElements = vec.size();
  // };
  // Array(std::initializer_list<Value> &&vec) : Blocks(vec) {
  //   countElements = vec.size();
  // };

  // = std::vector
  Array& operator=(const std::vector<Value>&& vec)
  {
    Blocks        = vec;
    countElements = vec.size();
    return *this;
  };
  // Array &operator=(std::vector<Value> &&vec) {
  //   Blocks = vec;
  //   countElements = vec.size();
  //   return *this;
  // };
  // Array &operator=(std::vector<Value> &vec) {
  //   Blocks = vec;
  //   countElements = vec.size();
  //   return *this;
  // };
  // = std::initializer_list
  Array& operator=(const std::initializer_list<Value>& list)
  {
    Blocks        = list;
    countElements = list.size();
    return *this;
  };
  // Array &operator=(std::initializer_list<Value> &&list) {
  //   Blocks = list;
  //   countElements = list.size();
  //   return *this;
  // };
  // Array &operator=(std::initializer_list<Value> &list) {
  //   Blocks = list;
  //   countElements = list.size();
  //   return *this;
  // };

  ~Array() = default;
  // object start end around string values
  std::vector<Value> Blocks;
  std::size_t        countElements = 0;
};

struct Object final
{
  Object()                         = default;
  Object(const Object&)            = default;
  Object(Object&&)                 = default;
  Object& operator=(const Object&) = default;
  Object& operator=(Object&&)      = default;
  // consturct with std::map
  Object(const std::map<std::string, Value>& map) : Blocks(map) { countElements = map.size(); };

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
};

struct Value final
{
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

  // Parse With SimdJSON
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
  std::string stringify(const Value& value)
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
  std::string stringify_object(const Value& value)
  {
    std::string result = "{";
    for( auto& pair : std::get<Object>(value.value).Blocks )
    {
      result += "\"" + pair.first + "\":" + stringify(pair.second) + ",";
    }
    if( result.back() == ',' ) { result.pop_back(); }
    result += "}";
    return result;
  };
  std::string stringify_array(const Value& value)
  {
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