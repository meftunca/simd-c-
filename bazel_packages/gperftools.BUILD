cc_library(
    name = "tcmalloc",
    srcs = ["lib/libtcmalloc.dylib"],
    hdrs = glob(["include/gperftools/*.h"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "profiler",
    srcs = ["lib/libprofiler.dylib"],
    hdrs = glob(["include/gperftools/*.h"]),
    includes = ["include"],
    visibility = ["//visibility:public"],
)

# cc_library(
#     name = "heap-checker",
#     srcs = ["lib/libheap-checker.dylib"],
#     hdrs = glob(["include/gperftools/*.h"]),
#     visibility = ["//visibility:public"],
# )
