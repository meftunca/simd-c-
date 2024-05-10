
// #include </opt/homebrew/include/gperftools/profiler.h>
#include <gtest/gtest.h>
int main(int argc, char** argv) {
  // ProfilerStart("main.prof");
  testing::InitGoogleTest(&argc, argv);
  auto val = RUN_ALL_TESTS();
  // ProfilerStop();

  return val;
}
