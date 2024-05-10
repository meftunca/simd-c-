load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "lz4",
    srcs = [
         "lib/lz4.h",
        "lib/lz4frame.c",
        "lib/lz4frame.h",
        "lib/lz4hc.h",
        "lib/xxhash.h",
    ],
    hdrs = [],
    copts = [
        "-DLZ4_DISABLE_DEPRECATE_WARNINGS",
        "-O3",
    ],
    defines = [
        "XXH_PRIVATE_API",
    ],
    includes = [
        "lib",
    ],
    linkopts = [],
    textual_hdrs = [
        "lib/xxhash.c",
        "lib/lz4.c",
    ],
    # srcs = glob(["lib/*.c"]),
    # hdrs = glob(["lib/*.h"]),
    # includes = ["lib"],
    # strip_include_prefix = "lib",
    alwayslink = True,
)
