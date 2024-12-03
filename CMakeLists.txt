cmake_minimum_required(VERSION 3.14)
project(web_compiler)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(
    web_compiler_lib
    src/helpers/helpers.cpp
    src/validators/validators.cpp
    src/lexer/lexer.cpp
    src/token/token.cpp
)

add_executable(web_compiler src/main.cpp)

target_link_libraries(web_compiler PRIVATE web_compiler_lib)

enable_testing()
add_subdirectory(test)

add_custom_target(run_tests_manual COMMAND ctest --output-on-failure)
