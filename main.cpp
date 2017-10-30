
#include <array>
#include "Neuron.hpp"
#include "Simulation.hpp"
#include <vector>




int main(){
	Simulation sim;
	sim.simule(20);
	return 0;
}







/*
A rajouter dans le Cmake quand j'aurai créé des tests : 
enable_testing()
add_subdirectory(gtest)
include directories(${gtest_SOURCE_DIR}/include${gtest_SOURCE_DIR})
add_executable (Neur_unittest Neuron.cpp Neur_unittest.cpp)
target_link_libraries(Neur_unittest gtest gtest_main)
add_test (Neur_unittest Neur_unittest)
*/

