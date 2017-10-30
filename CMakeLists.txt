cmake_minimum_required(VERSION 2.6)
project (Neuron)

set(CMAKE_CXX_FLAGS "-W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})

add_executable (Neuron Neuron.cpp main.cpp Simulation.cpp)

add_executable (Neur_unittest Neuron.cpp Neur_unittest.cpp)
target_link_libraries(Neur_unittest gtest gtest_main)
add_test (Neur_unittest Neur_unittest)

