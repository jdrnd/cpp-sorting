cmake_minimum_required(VERSION 3.10)

project(SortingTestBench)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

include_directories(src)
find_package(benchmark REQUIRED)


add_executable(SortingTestBench src/SortingTests.cpp bench/main.cpp)
target_link_libraries(SortingTestBench benchmark::benchmark)

