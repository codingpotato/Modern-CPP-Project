list(APPEND CMAKE_MODULE_PATH "${catch_SOURCE_DIR}/contrib")
include(CTest)
include(ParseAndAddCatchTests)

function(add_test_executable)
    cmake_parse_arguments(ADD OPTIONS NAME SOURCES ${ARGN})
    add_executable(${ADD_NAME} ${ADD_SOURCES})
    target_compile_features(${ADD_NAME} PUBLIC cxx_std_17)
    target_include_directories(${ADD_NAME} PUBLIC ../include ${catch_SOURCE_DIR}/single_include)
    #target_link_libraries(${ADD_NAME} PUBLIC w)

    ParseAndAddCatchTests(${ADD_NAME})
endfunction(add_test_executable)

add_test_executable(NAME modern_cpp_tests SOURCES modern_cpp_tests.cpp)