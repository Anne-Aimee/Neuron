#ifndef SIMULATION_H
#define SIMULATION_H

#include "Neuron.hpp"
#include <vector>
#include <array>
using namespace std;


class Simulation{
	
	public :
	Simulation() ;
	void simule (double t_stop);
	void newconnection(Neuron* n1, Neuron* n2);
	
	
	
	private :
	array<Neuron*,1250> neurons;
	vector<int> arr;
	int connexions[1250][1250] = {{0}};
	int globalclock ;
	
	const size_t nb_excitatory =1000;			//amount of excitatory neurons
	const size_t nb_inhibitory =250;			//amount of inhibitory neurons
	const unsigned int CE =100;					//amount of excitatory neurons linked to each neuron
	const unsigned int CI=15 ;					//amount of inhibitory neurons linked to each neuron
	const double JE =0.1; //??
};


#endif


/// mauvais nb de meurones mais si mon array connexions est de dim 12500*12500 ca fait segfault direct...
