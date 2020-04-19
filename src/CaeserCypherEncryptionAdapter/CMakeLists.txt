cmake_minimum_required(VERSION 3.2)

# Find external dependencides
find_package(EncryptionAdapterInterface)

# Add project folder into includes
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Configure CaeserCypherEncryptionAdapter static library
set(CAESER_CYPHER_ENCRYPTION_ADAPTER CaeserCypherEncryptionAdapter)
file(GLOB_RECURSE CAESER_CYPHER_ENCRYPTION_ADAPTER_SRC "*.cpp")
file(GLOB_RECURSE CAESER_CYPHER_ENCRYPTION_ADAPTER_HDR "*.h")
add_library(${CAESER_CYPHER_ENCRYPTION_ADAPTER} STATIC ${CAESER_CYPHER_ENCRYPTION_ADAPTER_SRC} ${CAESER_CYPHER_ENCRYPTION_ADAPTER_HDR})
target_link_libraries(${CAESER_CYPHER_ENCRYPTION_ADAPTER} EncryptionAdapterInterface::EncryptionAdapterInterface)

#Configure source groups
foreach(FILE ${CAESER_CYPHER_ENCRYPTION_ADAPTER_SRC} ${CAESER_CYPHER_ENCRYPTION_ADAPTER_HDR}) 
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
