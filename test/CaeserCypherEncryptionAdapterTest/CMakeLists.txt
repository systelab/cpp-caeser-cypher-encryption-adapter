enable_testing()

# Add project folder into includes
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find external dependencies
find_package(gtest)

# Configure test project
set(CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT CaeserCypherEncryptionAdapterTest)
file(GLOB_RECURSE CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT_SRC "*.cpp")
file(GLOB_RECURSE CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT_HDR "*.h")
add_executable(${CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT} ${CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT_SRC} ${CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT_HDR})
target_link_libraries(${CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT} CaeserCypherEncryptionAdapter gtest::gtest)

# Ignored missing PDBs link warning on Visual Studio
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(${CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT} PROPERTIES LINK_FLAGS "/ignore:4099")
endif()

#Configure source groups
foreach(FILE ${CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT_SRC} ${CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT_HDR}) 
    get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    string(REPLACE "/" "\\" GROUP "${GROUP}")

    if ("${FILE}" MATCHES ".*\\.cpp")
       set(GROUP "Source Files${GROUP}")
    elseif("${FILE}" MATCHES ".*\\.h")
       set(GROUP "Header Files${GROUP}")
    endif()

    source_group("${GROUP}" FILES "${FILE}")
endforeach()

# Register tests
add_test(NAME CaeserCypherEncryptionAdapterTest COMMAND ${CAESER_CYPHER_ENCRYPTION_ADAPTER_TEST_PROJECT})

# Additional target for code coverage analysis
if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
	include(CodeCoverage)
	setup_target_for_coverage(CaeserCypherEncryptionAdapterTestCoverage CaeserCypherEncryptionAdapterTest coverage)
endif()
