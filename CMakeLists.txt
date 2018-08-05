cmake_minimum_required(VERSION 3.4)
project(freshstl)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(/usr/local/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS -std=c++11)

add_subdirectory(test)