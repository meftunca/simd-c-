#pragma once
#include <cstdint>
#include <iostream>
#include <vector>

#include <experimental/coroutine>

struct FindTask
{
  std::vector<uint8_t> const& data;
  uint8_t                     value;
  bool                        result;

  struct promise_type
  {
    bool initial_value;

    auto get_return_object() { return FindTask {*this}; }

    auto initial_suspend() { return std::experimental::suspend_never {}; }

    auto final_suspend() noexcept { return std::experimental::suspend_always {}; }

    void unhandled_exception() noexcept { std::terminate(); }

    void return_void() noexcept {}

    auto yield_value(bool value)
    {
      initial_value = value;
      return std::experimental::suspend_always {};
    }
  };

  FindTask(promise_type& promise) : result {promise.initial_value} {}
  // FindTask(FindTask&&) = default;
  // FindTask(std::vector<uint8_t> const& data, uint8_t value, bool promise)
  //     : data {data}
  //     , value {value}
  //     , result {promise}
  // {}
  // FindTask(FindTask const&) = delete;

  bool await_ready() const noexcept { return false; }

  bool await_resume() const noexcept { return result; }

  void await_suspend(std::experimental::coroutine_handle<> handle)
  {
    auto coro = [this, handle]() mutable -> bool
    {
      for( auto const& elem : data )
      {
        if( elem == value )
        {
          co_await std::experimental::suspend_always {};
          co_return true;
        }
      }
      co_await std::experimental::suspend_always {};
      co_return false;
    };
    coro();
  }
};

auto
co_contains(std::vector<uint8_t> const& data, uint8_t value)
{
  co_return co_await FindTask {data, value, false};
}

int
main()
{
  std::vector<uint8_t> data {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  uint8_t              value = 5;

  bool found = co_contains(data, value).await_resume();

  std::cout << "Found: " << std::boolalpha << found << std::endl;

  return 0;
}
