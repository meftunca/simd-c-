load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "eve",
    srcs = glob(["vcpkg_installed/x64-osx/include/eve-2023.2.15/eve/**/*.hpp"]),
    hdrs = [],
    # alwayslink = True,
    copts = [
        # "EVE_USE_BMI_ON_AVX2 OFF",
        "EVE_USE_PCH ON",
        "EVE_BUILD_TEST OFF",
        "EVE_BUILD_BENCHMARKS OFF",
        "EVE_BUILD_DOCUMENTATION OFF",
        "-DNEDBUG",
        "-std=c++23",
        "-fno-rtti",
        # set apple m2 arch
        "-march=native",
        "-mtune=native",
    ],
    includes = ["include"],
    linkopts = [],
    strip_include_prefix = "include",

)
