cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("cc-core")

set (CMAKE_CXX_FLAGS "-Wall -std=c++11 -Werror")

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(cc-core
			thread-pool/thread.cc
			thread-pool/thread-pool.cc)

