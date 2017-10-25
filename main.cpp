#include <iostream>
#include <array>
#include "Neuron.hpp"
#include "Simulation.hpp"
#include <vector>




int main(){
	Simulation sim;
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




///ancien main
/*cout<<" simulation sim ;  "<< flush;
	sim.newneurons2();*/
	
	/*cout<<" sim.newneurons2();  "<< flush;
	sim.newconnection(sim.neurons[0],sim.neurons[1]);*/
	
	/*cout<<" sim.newconnection(sim.neurons[0],sim.neurons[1]);"<< flush;
	//sim.simule(2,100.0);
	
	cout<<" sim.simule(2,100.0);"<< flush;
*/
