[![Build Status](https://travis-ci.org/systelab/cpp-caeser-cypher-encryption-adapter.svg?branch=master)](https://travis-ci.org/systelab/cpp-caeser-cypher-encryption-adapter)
[![Build status](https://ci.appveyor.com/api/projects/status/qdrjivrs26gf46lo?svg=true)](https://ci.appveyor.com/project/systelab/cpp-caeser-cypher-encryption-adapter)
[![codecov](https://codecov.io/gh/systelab/cpp-caeser-cypher-encryption-adapter/branch/master/graph/badge.svg)](https://codecov.io/gh/systelab/cpp-caeser-cypher-encryption-adapter)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/170a7a69e61e45ba8924f5cf13d97ea8)](https://www.codacy.com/gh/systelab/cpp-caeser-cypher-encryption-adapter/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-caeser-cypher-encryption-adapter&amp;utm_campaign=Badge_Grade)


# C++ Encryption Adapter implementation for Caeser Cypher

This repository implements the interface for the [C++ Encryption Adapter](https://github.com/systelab/cpp-encryption-adapter) using the [Caeser Cypher](https://en.wikipedia.org/wiki/Caesar_cipher) algorithm.

> This implementation has been created just for demonstration purposes of the use of the encryption interface, so do not use it on production environments.


## Setup

### Download using Conan

This library is designed to be installed by making use of [Conan](https://conan.io/) package manager. So, you just need to add the following requirement into your Conan recipe:

```python
def requirements(self):
   self.requires("CaeserCypherEncryptionAdapter/1.0.0@systelab/stable")
```

> Version number of this code snipped is set just as an example. Replace it for the desired package version to retrieve.

As this package is not available on the conan-center, you will also need to configure a remote repository before installing dependencies:

```bash
conan remote add systelab-public https://systelab.jfrog.io/artifactory/api/conan/cpp-conan-production-local
```

See Conan [documentation](https://docs.conan.io/en/latest/) for further details on how to integrate this package with your build system.

### Build from sources

See [BUILD.md](BUILD.md) document for details.


## Usage

Initialize this encryption adapter by creating an instance of the `systelab::encryption::caeser_cypher::EncryptionAdapter` class:

```cpp
#include "CaeserCypherEncryptionAdapter/EncryptionAdapter.h"

std::unique_ptr<systelab::encryption::IEncryptionAdapter> encryptionAdapter =
    std::make<systelab::encryption::caeser_cypher::EncryptionAdapter>();
```

Use the `systelab::encryption::IEncryptionAdapter` interface of the created object to access to the encryption features as described on [C++ Encryption Adapter](https://github.com/systelab/cpp-encryption-adapter) documentation.
