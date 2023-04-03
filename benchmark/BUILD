load("@rules_cc//cc:defs.bzl", "cc_binary")
package(default_visibility = ["//visibility:public"])


cc_binary(
    name = "benchmark",
    srcs = glob(["*.cc","**/*.cc"]),
    deps = [
        # "@benchmark",
        "@com_google_benchmark//:benchmark_main",
        "@simdjson",
        # "@eastl",
        "@yyjson",
        "@nlohmann_json//:json",
        "@eve",
        "@lz4",
        "@nanobench",
        "@mio",
        "//src:simd",
        "//fastContains:fast_contains",
    ],
    # simd = True,
       copts=[
        "-O3",
        "-mavx2",
        "-DNEDBUG",
        "-std=c++20",
        "--stdlib=libc++",
        "-ftree-vectorize",
        ]
    # copts =  ['-DNDEBUG','-std=c++20'],
    # linkopts = ['-lstdc++fs'],
)