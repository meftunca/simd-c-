load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "bon_lib",
    hdrs = glob([
        "**/*.hh",
        "**/*.h",
        "**/*.hpp",
    ]),
    copts = [
        # "-Ofast",
        "-O0",
        "-DNEDBUG",
        "-std=c++2b",
        "-lprofiler",
        # "-march=armv8.5-a",
        # "-mfpu=neon",
        #  inline
        # "-finline-functions",
        # "-fno-inline-functions-called-once",
        # # vectorize
        # "-ftree-vectorize",
    ],
    visibility = ["//visibility:public"],
    deps = [
        # "@gperftools//:tcmalloc",
        # "@gperftools//:profiler",
        # "@gperftools//:heap-checker",
        # "@sonic_json",
        # "@fast_float",
        # "@eve",
        # "@mio",
        # "@lz4",
    ],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "bon",
    srcs = ["main.cc"],
    copts = [],
    deps = [
        "//src:bon_lib",
        # "@gperftools//:heap-checker",
        # "@gperftools//:profiler",
        # "@gperftools//:tcmalloc",
    ],
)
