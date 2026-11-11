from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import collect_libs, copy
import os

required_conan_version = ">=2.0.0"


class CaeserCypherEncryptionAdapterConan(ConanFile):
    name = "caeser-cypher-encryption-adapter"
    description = "C++ encryption adapter based on Caeser Cypher algorithm"
    url = "https://github.com/systelab/cpp-caeser-cypher-encryption-adapter"
    homepage = "https://github.com/systelab/cpp-caeser-cypher-encryption-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "caeser", "cypher", "encryption", "wrapper")
    license = "MIT"
    settings = "os", "compiler", "build_type", "arch"

    def requirements(self):
        self.requires("encryption-adapter-interface/1.2.1", transitive_headers=True)

    def build_requirements(self):
        self.test_requires("gtest/1.14.0")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        CMakeDeps(self).generate()
        CMakeToolchain(self).generate()
        for dep in self.dependencies.values():
            for bindir in dep.cpp_info.bindirs:
                copy(self, "*.dll", bindir, os.path.join(self.build_folder, "bin"), keep_path=False)
            for libdir in dep.cpp_info.libdirs:
                copy(self, "*.dylib*", libdir, os.path.join(self.build_folder, "bin"), keep_path=False)
                copy(self, "*.so*", libdir, os.path.join(self.build_folder, "bin"), keep_path=False)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(self, "EncryptionAdapter.h", os.path.join(self.source_folder, "src", "CaeserCypherEncryptionAdapter"),
             os.path.join(self.package_folder, "include", "CaeserCypherEncryptionAdapter"))
        for pattern in ("*CaeserCypherEncryptionAdapter.lib", "*CaeserCypherEncryptionAdapter.pdb", "*CaeserCypherEncryptionAdapter.a"):
            copy(self, pattern, self.build_folder, os.path.join(self.package_folder, "lib"), keep_path=False)

    def package_info(self):
        # Preserve the CMake names used by consumers
        self.cpp_info.set_property("cmake_file_name", "CaeserCypherEncryptionAdapter")
        self.cpp_info.set_property("cmake_target_name", "CaeserCypherEncryptionAdapter::CaeserCypherEncryptionAdapter")
        self.cpp_info.libs = collect_libs(self)
