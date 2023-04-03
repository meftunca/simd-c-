#pragma once
// coroutine isspace detection

#include <cctype>
#include <iostream>

#include <experimental/coroutine>

struct isSpaceAwaitable
{
  bool await_ready() const noexcept { return false; }
  void await_suspend(std::experimental::coroutine_handle<> h) const noexcept
  {
    std::cout << "await_suspend" << std::endl;
    h.resume();
  }
  bool await_resume() const noexcept { return true; }
};

struct isSpace
{
  isSpaceAwaitable operator()(char c) const noexcept
  {
    std::cout << "isSpace" << std::endl;
    return isSpaceAwaitable {};
  }
};
