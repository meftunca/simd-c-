
cc_test(
    name = "testing",
    size = "small",
    # srcs = ["main_test.cc","create_or_append_collection_test.cc"],
    srcs = glob(["**/*.cc"]),
    deps = [
        "@com_google_googletest//:gtest_main",
        "@simdjson",
        # "@eastl",
        "@yyjson",
        "@nlohmann_json//:json",
        "@eve",
        "@lz4",
        "@mio",
        "//src:simd"
    ],

    copts =  ['-std=c++20','-O0', '-g'],

    # visibility = ["//visibility:public"],
    # copts = ["-Iexternal/llvm/include"],
    # linkopts = ["-Lexternal/llvm/lib","-lexternals"],
)
