# Copyright (C)  2022 devloops
# Use of this software is govered by the Business Source License included in the LICENSE.TXT file and at www.mariadb.com/bsl11.
#
# Change Date:
#
# On the date above, in accordance with the Business Source License, use of this software will be governed by the open source license specified in the LICENSE.TXT file.

from conan import ConanFile
from conan.tools.files import save, load
from conan.tools.gnu import AutotoolsToolchain, AutotoolsDeps
from conan.tools.microsoft import unix_path, VCVars, is_msvc
from conan.errors import ConanInvalidConfiguration
from conan.errors import ConanException


class SONDB(ConanFile):
    name = "SONDB"
    settings = "os", "compiler", "build_type", "arch"
    folders = {"source": "source", "build": "build", "install": "install"}
    #  build_type=RelWithDebInfo;compiler=apple-clang;compiler.version=13.1;compiler.libcxx=libc++;os.version=;arch=x86_64
    # settings = {"os": ["Linux", "Windows", "Macos"],
    #         "compiler": {"gcc": {"version": ["14"]}, "clang": {"version": ["13.1"]}, "apple-clang": {"version": ["14"]}, "Visual Studio": {"version": ["16"]}},
    #      "build_type": ["Debug", "Release", "RelWithDebInfo"], "arch": ["x86_64"] }
    # options = {"shared": [True, False]}
    # default_options = {"shared": False}
    # "jerryscript/2.4.0", "folly/2022.01.31.00",
    requires = (
        "lz4/1.9.4",
        "zstd/1.5.5",
        # "jfalcou-eve/v2023.02.15",
        # "gperftools/2.15",
        "yyjson/0.8.0",
        "fast_float/5.3.0",
        "mio/cci.20230303",
        "taskflow/3.6.0",
        "glaze/2.6.1",
    )
    generators = ["BazelDeps", "BazelToolchain"]
    os = "Macos"
    compiler = "apple-clang"
    arch = "armv8"
    build_type = "Release"

    cppstd = "20"

    # should_configure = True
    # libcxx = "libc++"
    # compiler_version = "15"
    compiler_cppstd = "20"

    # build_requires = "cmake/3.28.2"
    def build(self):
        self.run("cmake --version")

    def configure(self):
        self.folders.build = "conanDeps"
        # set cppstd
        self.cppstd = "20"

        # set os
        if self.settings.os == "Linux":
            self.os = "Linux"
        elif self.settings.os == "Windows":
            self.os = "Windows"
        elif self.settings.os == "Macos":
            self.os = "Macos"
        else:
            raise ConanInvalidConfiguration("Unsupported os")

        pass

    def imports(self):
        pass
