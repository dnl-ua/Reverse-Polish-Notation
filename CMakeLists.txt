cmake_minimum_required(VERSION 3.14)
project("RPN")

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
	RPN_test
	RPN_test.cc
	RPN.cpp
)

target_link_libraries(
	RPN_test	
	GTest::gtest_main
)

add_test(NAME RPN_test COMMAND RPN_test)

include(GoogleTest)
gtest_discover_tests(RPN_test)
