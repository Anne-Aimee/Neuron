#ifndef SIMULATION_H
#define SIMULATION_H


#include <vector>
//#include <cmath>
using namespace std;
//#include <iostream>

class Simulation{
	
	public :
	Simulation() ;
	void simule (size_t nb_neuron,double t_stop);
	
	
	private :
	vector<Neuron*> neurons;
};


#endif
