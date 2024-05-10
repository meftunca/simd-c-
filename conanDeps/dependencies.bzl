# This Bazel module should be loaded by your WORKSPACE file.
# Add these lines to your WORKSPACE one (assuming that you're using the "bazel_layout"):
# load("@//conan:dependencies.bzl", "load_conan_dependencies")
# load_conan_dependencies()

def load_conan_dependencies():
    native.new_local_repository(
        name="lz4",
        path="/Users/mapletechnologies/.conan2/p/b/lz484bb7bc191790/p",
        build_file="/Users/mapletechnologies/Desktop/big_projects/bon/conanDeps/lz4/BUILD.bazel",
    )
    native.new_local_repository(
        name="zstd",
        path="/Users/mapletechnologies/.conan2/p/b/zstd0252b053e99a2/p",
        build_file="/Users/mapletechnologies/Desktop/big_projects/bon/conanDeps/zstd/BUILD.bazel",
    )
    native.new_local_repository(
        name="yyjson",
        path="/Users/mapletechnologies/.conan2/p/b/yyjso911275d9aa9d5/p",
        build_file="/Users/mapletechnologies/Desktop/big_projects/bon/conanDeps/yyjson/BUILD.bazel",
    )
    native.new_local_repository(
        name="fast_float",
        path="/Users/mapletechnologies/.conan2/p/fast_ba23615a9aa5f/p",
        build_file="/Users/mapletechnologies/Desktop/big_projects/bon/conanDeps/fast_float/BUILD.bazel",
    )
    native.new_local_repository(
        name="mio",
        path="/Users/mapletechnologies/.conan2/p/miofc2037bac7adf/p",
        build_file="/Users/mapletechnologies/Desktop/big_projects/bon/conanDeps/mio/BUILD.bazel",
    )
    native.new_local_repository(
        name="taskflow",
        path="/Users/mapletechnologies/.conan2/p/taskf9b3cd4aaf670d/p",
        build_file="/Users/mapletechnologies/Desktop/big_projects/bon/conanDeps/taskflow/BUILD.bazel",
    )
