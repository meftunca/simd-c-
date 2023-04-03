load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])
cc_library(
  name = "eve",
  srcs = glob(["include/eve/**/*.hpp"]),
      hdrs = [],
    linkopts = [],
  includes = ["include"],
  strip_include_prefix = "include",
  # alwayslink = True,
  copts=[
    # "EVE_USE_BMI_ON_AVX2 OFF",
    "EVE_USE_PCH OFF",
    "EVE_BUILD_TEST OFF",
    "EVE_BUILD_BENCHMARKS OFF",
    "EVE_BUILD_DOCUMENTATION OFF"
  ]
  # copts = ['-O3', '-DNDEBUG', "-march=native",
  #       "-mtune=native",
  #       "-O3",
  #       "-std=c++20",
  #       "-mavx2",
  #       "-mfma",
  #       "-mavx512f",
  #       "-mavx512cd",
  #       "-mavx512er",
  #       "-mavx512pf",
  #       "-mavx512dq",
  #       "-mavx512bw",
  #       "-mavx512vl",
  #       "-mavx512ifma",],
)