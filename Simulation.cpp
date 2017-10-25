#include "Simulation.hpp"
#include <string>
#include <random>
#include <cassert>

Simulation::Simulation(){
	
	for(unsigned int i(0);i<neurons.size();++i){
		neurons[i]=new Neuron;
	}
	assert(neurons.size()==nb_excitatory+nb_inhibitory);
	globalclock=0;
}
	

void Simulation::simule(double t_stop) {
	while (globalclock<(t_stop/neurons[0]->h)){
		for(unsigned int i(0);i<neurons.size();++i){
			neurons[i]->spike=neurons[i]->update_state();
			if (neurons[i]->spike) {
				for (unsigned int j(0);j<neurons.size();++j){
					if(connexions[i][j]){
					neurons[j]->receive(globalclock+(neurons[i]->delaystep),neurons[i]->J);}
				}
			}
		}
	}
	++globalclock;
}

void Simulation::newconnection(Neuron* n1, Neuron* n2){//faire retourner un message d erreur si il ne trouve pas n1 et ou n2 dans la liste de neurones
	int pre(0);
	int post(0);
	for (unsigned int i(0);i<neurons.size();++i){
		if (neurons[i]==n1) 
		 pre=i;
		else if (neurons[i]==n2)
		 post=i;
	}
	++ connexions[pre][post];
}
		
	//a mettre dans uhne fonction ou qqpart	
	/*	
for (auto neuron : neurons){	

for (unsigned int i(0);i<CE;++i){
	
	
}
		
	}
		
		
		
		
		*/
		
		
		
		
	

