load("@rules_cc//cc:defs.bzl", "cc_binary")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "benchmark",
    srcs = glob([
        "*.cc",
        "**/*.cc",
        "*.h",
        "**/*.h",
    ]),
    copts = [
        "-O3",
        "-DNEDBUG",
        "-std=c++2b",
        "-march=armv8-a",
        "-mtune=native",
        "-mpopcnt",
        "-mfma",
        "-funroll-loops",
        "-ffast-math",
        "-finline-functions",
        "-ftree-vectorize",
    ],
    deps = [
        # "@com_github_gperftools_gperftools//:all",
        # "@benchmark",
        "@com_google_benchmark//:benchmark_main",
        # "@eastl",
        # "@eve",
        # # "@sonic",
        # "@lz4",
        # "@mio",
        "//src:bon_lib",
        "//fastContains:fast_contains",
    ],
)
