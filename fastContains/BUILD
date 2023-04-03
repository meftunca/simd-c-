load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "fast_contains",
    hdrs = glob(["*.hpp"]),
    visibility = ["//visibility:public"],
    copts=[
        "-march=native",
        "-O3",
        "-DNEDBUG",
        "-std=c++20",
                # "-fcoroutines",
        # "-fcoroutines-ts",
        # "-fconcepts",
        ]

)
