#include "Simulation.hpp"
#include <string>
#include <random>
#include <cassert>
#include <iostream>
using namespace std;



/* constructor
 * @see setexcitatoryneurons()
 * @see initialconnexions()
 * */


Simulation::Simulation(){
	
	for(unsigned int i(0);i<neurons.size();++i){
		neurons[i]=new Neuron;
	}
	assert(neurons.size()==nb_excitatory+nb_inhibitory);
	globalclock=0;
	setexcitatoryneurons();
	initialconnexions();
}
	
	
/* simulation : simulates the activity of the neuron network during a certain period
 * @param double : period of simulation (in ms)
 * @see Neuron::updatestate()
 * @see Neuron::receive()
 */
void Simulation::simule(double t_stop) {
	while (globalclock<(t_stop/neurons[0]->h)){
		for(unsigned int i(0);i<neurons.size();++i){
			neurons[i]->spike=neurons[i]->update_state(1);
			if (neurons[i]->spike) {
				//assert que V de neuronsi est bien superieur a vthr
				for (unsigned int j(0);j<neurons.size();++j){
					if(connexions[i][j]){
					neurons[j]->receive(globalclock+(neurons[i]->delaystep),neurons[i]->J);}
				}
			}
		}
	}
	++globalclock;
}

/* creates a new connexion between two identified neurons 
 * @param Neuron* n1 : pointer on preconnexion neuron;
 * @param Neuron* n2 : pointer on postconnexion neuron;
 */ 
void Simulation::newconnexion(Neuron* n1, Neuron* n2){//faire retourner un message d erreur si il ne trouve pas n1 et ou n2 dans la liste de neurones
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
		

/* creates connexions in the neuron network (connexions with excitatory and inhibitory neurons from the network)
 * modifies the matrix of connexions
 */ 
void Simulation::initialconnexions(){		
for (unsigned int n(0);n<neurons.size();++n){	

	for (unsigned int e(0);e<CE;++e){
		unsigned int pre_excitatory (0); //pre_excitatory est le numero de la case pris au hasard parmis les numeros de case de excitatory neurons
		pre_excitatory = rand() % nb_excitatory; 
		assert(neurons[pre_excitatory]->isexcitatory);
		assert (pre_excitatory<nb_excitatory);
		++connexions[pre_excitatory][n];
	}
	for (unsigned int i(0);i<CI;++i){
		unsigned int pre_inhibitory (0);
		pre_inhibitory = rand() %  nb_inhibitory +(nb_excitatory+1); 
		assert(! neurons[pre_inhibitory]->isexcitatory);
		assert(pre_inhibitory>= nb_excitatory and pre_inhibitory<neurons.size());
		++connexions[pre_inhibitory][n];
	}	
	
}

}
		
/* select which neurons of the network are excitatory and inhibitory
 */ 		
void Simulation::setexcitatoryneurons(){
	for (unsigned int i(0);i<nb_excitatory;++i){
		neurons[i]->setexcitatory(true);
		neurons[i]->J=JE;
		assert(neurons[i]->J==JE and neurons[i]->isexcitatory);	
	}
	for (unsigned int i(nb_excitatory);i<neurons.size(); ++i){
		neurons[i]->J=JI;
		assert(neurons[i]->J==JI and !neurons[i]->isexcitatory);
	}
	
}



/*
///pour la suite quand je pourrais afficher
void Simulation::save(string graphfile){
	ofstream out(graphfile);
	//get spiketime + get spikeid
	graphfile<<(spikelist)<<'/t'<<(spikeid)<<'/n';
	
	
		}*/
		


