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
	void save(const string&);
	
	
	//=====CONSTANTES=====//
	const size_t nb_excitatory =1000;			//!<amount of excitatory neurons in the simulation
	const size_t nb_inhibitory =250;			//!<amount of inhibitory neurons in the simulation
	const unsigned int CE =100;					//!<amount of excitatory neurons linked to each neuron
	const unsigned int CI=25 ;					//!<amount of inhibitory neurons linked to each neuron
	const double JE =0.1; 						//!<current given to neighbours when excitatory neuron spikes
	const double JI=-JE*WEIGHT_JIJE;			//!<current given to neighbours when inhibitory neuron spikes
	const double WEIGHT_JIJE=5;					//!< wight between currents from inhibitory and excitatory (weight = -JI/JE)						
	//===================//
	
	
	private :
	array<Neuron*,1250> neurons;				//!<array to access to  all the neurons of the simulation
	int globalclock ;							//!<equivalent of timestep from class Neuron but for global scale
	
	

};


#endif


// mauvais nb de neurones et segfault automatiquement


