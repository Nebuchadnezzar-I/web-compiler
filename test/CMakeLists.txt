file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(run_tests ${TEST_SOURCES})

target_link_libraries(run_tests PRIVATE web_compiler_lib gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)
