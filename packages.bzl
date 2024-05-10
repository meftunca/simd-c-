load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def loadPackages():
    # print message
    print("Loading packages...")
    # Nanobench
    # new_git_repository(
    #     name = "nanobench",
    #     branch = "master",
    #     build_file = "//:bazel_packages/nanobench.BUILD",
    #     remote = "https://github.com/martinus/nanobench",
    # )

    # com_github_gperftools_gperftools
    # new_git_repository(
    #     name = "com_github_gperftools",
    #     # branch = "master",
    #     tag = "gperftools-2.10",
    #     build_file = "//:bazel_packages/gperftools.BUILD",
    #     remote = "https://github.com/gperftools/gperftools.git",
    #     # sha256 = "The SHA-256 hash of the tarball",
    # )

    # http_archive(
    #     name = "sonic",
    #     urls = ["https://github.com/bytedance/sonic-cpp/archive/refs/tags/v1.0.0.zip"],
    #     strip_prefix = "sonic-cpp-1.0.0",
    # )
    # new_git_repository(
    #     name = "sonic",
    #     branch = "master",
    #     build_file = "//:bazel_packages/sonic.BUILD",
    #     remote = "https://github.com/bytedance/sonic-cpp.git",
    # )

    # new_git_repository(
    #     name = "mio",
    #     branch = "master",
    #     build_file = "//:bazel_packages/mio.BUILD",
    #     remote = "https://github.com/mandreyel/mio.git",
    # )

    # new_git_repository(
    #     name = "lz4",
    #     branch = "release",  #release|dev
    #     build_file = "//:bazel_packages/lz4.BUILD",
    #     remote = "https://github.com/lz4/lz4.git",
    # )

    # # new_git_repository(
    # #     name = "fast_float",
    # #     branch = "main",
    # #     build_file = "//:bazel_packages/fast_float.BUILD",
    # #     remote = "https://github.com/fastfloat/fast_float.git",
    # # )
    # new_git_repository(
    #     name = "eve",
    #     branch = "main",
    #     # commit = '5264e20c51aeca17675e67abf236ce1ead781c52',
    #     # shallow_since = "1677570610 +0100",
    #     # strip_prefix="include",
    #     build_file = "//:bazel_packages/eve.BUILD",
    #     remote = "https://github.com/jfalcou/eve.git",
    # )

    # # new_git_repository(
    # #     name = "gperftools",
    # #     branch = "master",
    # #     # commit = '5264e20c51aeca17675e67abf236ce1ead781c52',
    # #     # shallow_since = "1677570610 +0100",
    # #     # strip_prefix="include",
    # #     build_file = "//:bazel_packages/gperftools.BUILD",
    # #     remote = "https://github.com/gperftools/gperftools.git",
    # # )

    # git_repository(
    #     name = "nlohmann_json",
    #     branch = "develop",
    #     # build_file = "//:bazel_packages/nlohmann_json.BUILD",
    #     remote = "https://github.com/nlohmann/json.git",
    # )

    http_archive(
        name = "com_google_googletest",
        urls = ["https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip"],
        strip_prefix = "googletest-1.14.0",
    )

    http_archive(
        name = "com_google_benchmark",
        urls = ["https://github.com/google/benchmark/archive/refs/tags/v1.8.3.zip"],
        strip_prefix = "benchmark-1.8.3",
    )

    # Load Bazel Compilation Database
    http_archive(
        name = "com_grail_bazel_compdb",
        strip_prefix = "bazel-compilation-database-0.5.2",
        urls = ["https://github.com/grailbio/bazel-compilation-database/archive/0.5.2.tar.gz"],
    )
