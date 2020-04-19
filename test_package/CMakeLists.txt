cmake_minimum_required(VERSION 3.2)

project(CaeserCypherEncryptionAdapterPackageTestProject)

# Configure environment
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find external dependencies
find_package(CaeserCypherEncryptionAdapter)

# Configure test package project
set(CAESER_CYPHER_ENCRYPTION_ADAPTER_PACKAGE_TEST_PROJECT CaeserCypherEncryptionAdapterPackageTest)
add_executable(${CAESER_CYPHER_ENCRYPTION_ADAPTER_PACKAGE_TEST_PROJECT} CaeserCypherEncryptionAdapterExample.cpp)
target_link_libraries(${CAESER_CYPHER_ENCRYPTION_ADAPTER_PACKAGE_TEST_PROJECT} CaeserCypherEncryptionAdapter::CaeserCypherEncryptionAdapter)

# Register tests
enable_testing()
add_test(NAME CaeserCypherEncryptionAdapterPackageTest COMMAND ${CAESER_CYPHER_ENCRYPTION_ADAPTER_PACKAGE_TEST_PROJECT})
