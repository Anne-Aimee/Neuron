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
	void newconnexion(Neuron* n1, Neuron* n2);
	void setexcitatoryneurons();
	void initialconnexions();
	
	
	
	private :
	array<Neuron*,1250> neurons;				//array to access to  all the neurons 
	int connexions[1250][1250] = {{0}};			//matrix of connexions between neurons (first index corresponds to the preneuron - with same index of the array neurons, 
												// 								second index corresponds to the postneuron - also with same index of the array neurons)
	int globalclock ;							//equivalent of timestepfrom class Neuron but for global scale
	
	const size_t nb_excitatory =1000;			//amount of excitatory neurons in the simulation
	const size_t nb_inhibitory =250;			//amount of inhibitory neurons in the simulation
	const unsigned int CE =100;					//amount of excitatory neurons linked to each neuron
	const unsigned int CI=25 ;					//amount of inhibitory neurons linked to each neuron
	const double JE =0.1; 						//current given to neighbours when excitatory neuron spikes
	const double JI=-JE*WEIGHT_JIJE;			//current given to neighbours when inhibitory neuron spikes
	const double WEIGHT_JIJE=5;					// wight between currents from inhibitory and excitatory (weight = -JI/JE)

};


#endif


/// mauvais nb de neurones mais si mon array connexions est de dim 12500*12500 ca fait segfault direct...
///-> solution : array<Neuron,12500> neurons; et int connexions[12500][12500] puis corrger a chaque fois que jaccede a neurons[i], corriger -> par .



