#include "Simulation.hpp"
#include "Neuron.hpp"

Simulation::Simulation()

void Simulation::simule(size_t nb_neuron,double t_stop) {
	while (neurons[nb_neuron+1].get_t()<(tstop/neurons[nb_neuron+1].h)){
	size_t i(0) ;
	while (i<=nb_neuron){
		for (auto n : neurons){
		n.update_state();
		++i;}
	}
	}	
}
