load("@rules_cc//cc:defs.bzl", "cc_library","cc_binary")

cc_library(
    name = "simd",
    hdrs = glob(["*.hh","*.h","*.hpp"]),
    visibility = ["//visibility:public"],
    deps = [
        "@simdjson",
        # "@sonic_json",
        # "@fast_float",
        "@lz4",
        "@eve",
        "@mio",
        "@nlohmann_json//:json",
        # "@taocpp-pegtl",
    ],
    copts=[
        # "-march=native",
        "-O3",
        "-DNEDBUG",
        "-std=c++20",
        # "-fcoroutines",
        # "-fcoroutines-ts",
        # "-fconcepts",
        # "--stdlib=libc++",
        ]

)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "simd_out",
    srcs = ["main.cc"],
    copts = [],
    deps = ["//eve:eve",  "//src:simd"],

)