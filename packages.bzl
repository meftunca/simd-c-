# Copyright (C)  2022 devloops
# Use of this software is govered by the Business Source License included in the LICENSE.TXT file and at www.mariadb.com/bsl11.
#
# Change Date:
#
# On the date above, in accordance with the Business Source License, use of this software will be governed by the open source license specified in the LICENSE.TXT file.

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# package(default_visibility = ["//visibility:public"])


# Load Packages
def loadPackages():
    """Load packages from git repositories"""
    # Nanobench
    new_git_repository(
        name = "nanobench",
        branch = "master",
        build_file = "//:bazel_packages/nanobench.BUILD",
        remote = "https://github.com/martinus/nanobench",
        # sha256 = "61fbbba5a5b5d9c5b5ab5b858843f72d4fb9322ed75c7981b23305f05508d02b",
        # strip_prefix = "nanobench-4.2.3",
    )
    new_git_repository(
        name = "simdjson",
        branch = "master",
        build_file = "//:bazel_packages/simdjson.BUILD",
        remote = "https://github.com/simdjson/simdjson.git",
    )

    new_git_repository(
        name = "yyjson",
        branch = "master",
        build_file = "//:bazel_packages/yyjson.BUILD",
        remote = "https://github.com/ibireme/yyjson.git",
    )

    new_git_repository(
        name = "mio",
        branch = "master",
        build_file = "//:bazel_packages/mio.BUILD",
        remote = "https://github.com/mandreyel/mio.git",
    )

    new_git_repository(
        name = "lz4",
        branch = "release", #release|dev
        build_file = "//:bazel_packages/lz4.BUILD",
        remote = "https://github.com/lz4/lz4.git",
    )

    # new_git_repository(
    #     name = "fast_float",
    #     branch = "main",
    #     build_file = "//:bazel_packages/fast_float.BUILD",
    #     remote = "https://github.com/fastfloat/fast_float.git",
    # )
    new_git_repository(
        name = "eve",
        branch = "main",
        # commit = '5264e20c51aeca17675e67abf236ce1ead781c52',
        # shallow_since = "1677570610 +0100",
        # strip_prefix="include",
        build_file = "//:bazel_packages/eve.BUILD",
        remote = "https://github.com/jfalcou/eve.git",
    )


    git_repository(
        name = "nlohmann_json",
        branch = "develop",
        # build_file = "//:bazel_packages/nlohmann_json.BUILD",
        remote = "https://github.com/nlohmann/json.git",
    )


    http_archive(
        name = "com_google_googletest",
        urls = ["https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip"],
        strip_prefix = "googletest-1.13.0",

    )

    http_archive(
        name = "com_google_benchmark",
        urls = ["https://github.com/google/benchmark/archive/refs/tags/v1.7.1.zip"],
        strip_prefix = "benchmark-1.7.1",

    )
