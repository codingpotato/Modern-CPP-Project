cmake_minimum_required(VERSION 3.12)

project(Modern-CPP-Project VERSION 0.1 DESCRIPTION "Modern CPP Project Template" LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(clang-tidy)

enable_testing()
include(catch2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)