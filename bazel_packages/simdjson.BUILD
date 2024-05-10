package(default_visibility = ["//visibility:public"])

cc_library(
    name = "simdjson",
    srcs = ["singleheader/simdjson.cpp"],
    hdrs = ["singleheader/simdjson.h"],
    copts = ["-DSIMDJSON_AVX512_ALLOWED=0"],
    includes = ["singleheader"],
)
