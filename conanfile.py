from conans import ConanFile, CMake, tools


class CaeserCypherEncryptionAdapterConan(ConanFile):
    name = "CaeserCypherEncryptionAdapter"
    description = "C++ encryption adapter based on Caeser Cypher algorithm"
    url = "https://github.com/systelab/cpp-caeser-cypher-encryption-adapter"
    homepage = "https://github.com/systelab/cpp-caeser-cypher-encryption-adapter"
    author = "CSW <csw@werfen.com>"
    topics = ("conan", "caeser", "cypher", "encryption", "wrapper")
    license = "MIT"
    generators = "cmake_find_package"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "*", "!build-*", "!*.yml", "!*.md", "!*.in", "!ci", "!.gitattributes", "!.gitignore", "!LICENSE"

    def requirements(self):
        self.requires("EncryptionAdapterInterface/1.2.0@systelab/stable")

    def build_requirements(self):
        self.build_requires("gtest/1.14.0#4372c5aed2b4018ed9f9da3e218d18b3")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*.so*", dst="bin", src="lib")

    def package(self):
        self.copy("EncryptionAdapter.h", dst="include/CaeserCypherEncryptionAdapter", src="src/CaeserCypherEncryptionAdapter")
        self.copy("*CaeserCypherEncryptionAdapter.lib", dst="lib", keep_path=False)
        self.copy("*CaeserCypherEncryptionAdapter.pdb", dst="lib", keep_path=False)
        self.copy("*CaeserCypherEncryptionAdapter.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
