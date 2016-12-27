cmake_minimum_required(VERSION 3.6)
project(simple_coroutine_library)

add_subdirectory(src)
add_subdirectory(libcr)

configure_file(README.md ${PROJECT_BINARY_DIR})

