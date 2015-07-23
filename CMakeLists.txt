cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

include (cmake/DefaultCMakeLists.txt)

include_directories (${CMAKE_SOURCE_DIR}/include
					 ${CMAKE_SOURCE_DIR}/third-party/gtest-1.7.0
					 ${Boost_INCLUDE_DIR})

add_library (gtest		third-party/gtest-1.7.0/gtest/gtest-all.cc)
add_library (core		util/thread.cc
						util/thread-ctx.cc)

add_executable (thread-test test/thread-test.cc)

target_link_libraries(thread-test gtest core pthread boost_regex)

add_test(${RUN_TEST_CASE} ${CMAKE_BINARY_DIR}/thread-test)
