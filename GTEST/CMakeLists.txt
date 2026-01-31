cmake_minimum_required(VERSION 3.14)
project(GTestDemo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# -----------------------
# Production library
# -----------------------
add_library(core_lib
    src/math.cpp
    src/myFirstProgram.cpp
    src/stack.cpp
)

target_include_directories(core_lib PUBLIC include)

# -----------------------
# Test executables
# -----------------------
add_executable(math_test
    tests/test_math.cpp
)

add_executable(myFirstProgram_test
    tests/test_myFirstProgram.cpp
)

add_executable(Stack_Fixture_test
    tests/test_Stack_Fixture.cpp
)

add_executable(Google_mock_test
    tests/test_GooogleMock.cpp
)
add_executable(Google_Test_Frame_Work
    tests/test_Google_frame.cpp
)

target_link_libraries(math_test
    gtest_main
    core_lib
)

target_link_libraries(myFirstProgram_test
    gtest_main
    core_lib
)

target_link_libraries(Stack_Fixture_test
    gtest_main
    core_lib
)

target_link_libraries(Google_mock_test

    gtest_main
    gmock
    core_lib

)

target_link_libraries(Google_Test_Frame_Work
    
    gtest_main
    gmock
    core_lib
)



include(GoogleTest)
gtest_discover_tests(math_test)
gtest_discover_tests(myFirstProgram_test)
gtest_discover_tests(Stack_Fixture_test)
gtest_discover_tests(Google_mock_test)
gtest_discover_tests(Google_Test_Frame_Work)
