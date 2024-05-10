#include <benchmark/benchmark.h>
#include <chrono>
#include <iostream>

#ifdef __clang__
#include <experimental/coroutine>
#else
#include <coroutine>
#endif

namespace cor {
#ifdef __clang__
using namespace std::experimental;
#else
using namespace std;
#endif
}  // namespace cor

constexpr size_t N = 1024;

struct Future {
  struct promise_type {
    double value_;
    Future get_return_object() {
      return {cor::coroutine_handle<promise_type>::from_promise(*this)};
    }
    inline cor::suspend_always initial_suspend() { return {}; }
    inline cor::suspend_always final_suspend() noexcept { return {}; }
    inline void unhandled_exception() {}
    inline void return_value(double v) { value_ = v; }
  };
  inline bool done() { return h_.done(); }
  inline void resume() { return h_(); }
  inline double value() { return h_.promise().value_; }
  ~Future() { h_.destroy(); }
  cor::coroutine_handle<promise_type> h_;
};

double compute() {
  double res = 0;
  for (size_t i = 0; i < N; ++i)
    res += i;
  return res;
}

double computeInCoroutine() {
  auto future = []() -> Future {
    double res = 0;
    for (size_t i = 0; i < N; ++i)
      res += i;
    co_return res;
  }();
  while (!future.done())
    future.resume();
  return future.value();
}

static void BenchCompute(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(compute());
  }
}
BENCHMARK(BenchCompute);

static void BenchComputeCoroutine(benchmark::State& state) {
  for (auto _ : state) {
    benchmark::DoNotOptimize(computeInCoroutine());
  }
}

BENCHMARK(BenchComputeCoroutine);