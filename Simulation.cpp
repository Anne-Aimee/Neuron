#include "Simulation.hpp"
#include <string>
#include <random>
#include <cassert>
#include <iostream>
using namespace std;



/**
 * A constructor.
 * */


Simulation::Simulation(){
	
	for(unsigned int i(0);i<neurons.size();++i){
		neurons[i]=new Neuron;
	}
	assert(neurons.size()==nb_excitatory+nb_inhibitory);
	globalclock=0;
	cerr<<"avant tout"<< endl;
	setexcitatoryneurons();
		cerr<<"milieu"<< endl;
	initialconnexions();
		cerr<<"fin "<< endl;

}
	
	
/**
 * simulation : simulates the activity of the neuron network during a certain period
 * @param double : period of simulation (in ms)
 */
void Simulation::simule(double t_stop) {
	while (globalclock<(t_stop/neurons[0]->h)){
		for(unsigned int i(0);i<neurons.size();++i){
			neurons[i]->spike=neurons[i]->update_state(1);
			if (neurons[i]->spike) {
				for (auto target : neurons[i]->targets){
					target->receive(globalclock+(neurons[i]->delaystep),neurons[i]->J);
				}
			}
		}
	}
	++globalclock;
}

/**
 * creates a new connexion between two identified neurons 
 * @param Neuron* n1 : pointer on preconnexion neuron;
 * @param Neuron* n2 : pointer on postconnexion neuron;
 * @see initialconnexions
 */ 
void Simulation::newconnexion(Neuron* n1, Neuron* n2){
	(n1->targets).push_back(n2);
}
		

/**
 * creates random connexions in the neuron network (connexions with excitatory and inhibitory neurons from the network)
 * with defined number of excitatory connexions and inhibitory connexions
 */ 
void Simulation::initialconnexions(){		
for (unsigned int n(0);n<neurons.size();++n){	

	for (unsigned int e(0);e<CE;++e){
		unsigned int pre_excitatory (0); //pre_excitatory est le numero de la case pris au hasard parmis les numeros de case de excitatory neurons
		cout << " a" << endl; 
		pre_excitatory = rand() % nb_excitatory; 
		cout << " b" << endl;
		assert(neurons[pre_excitatory]->isexcitatory);
		cout << " c" << endl;
		assert (pre_excitatory<nb_excitatory);
		cout << " d" << endl;
		newconnexion(neurons[pre_excitatory],neurons[n]);
	}
	for (unsigned int i(0);i<CI;++i){
		unsigned int pre_inhibitory (0);
		cout << " g" << endl;
		pre_inhibitory = rand() %  nb_inhibitory +(nb_excitatory+1); 
		cout << " i" << endl;
		assert(! neurons[pre_inhibitory]->isexcitatory);
		assert(pre_inhibitory>= nb_excitatory and pre_inhibitory<neurons.size());
		newconnexion(neurons[pre_inhibitory],neurons[n]);
		///segmentation fault ici apres quelques tours de cette boucle (ca doit prendre trop de memoire ??)
		cout << " kkkkkkkk" << endl;
	}
	cout << " k" << endl;

}
cout << " fin boucle " << endl;
}
		
/**
 * select which neurons of the network are excitatory and inhibitory
 * @see Simulation
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

/**
 * save all the times and neuron identifier in another file 
 * save date for the graph
 */ 

void Simulation::save(const string& graphfile){
	/*ofstream out(graphfile);
	for(unsigned int i=0; i<neurons.size();++i){
		for(auto spiket : neurons[i]->spiketime){
			graphfile<<spiket<<'\t'<<i<<'\n';
		}
	}*/
}

		//pb lie a l initialisation de ofstream et  erreur suivante meme quand je commente l in terieur du save :
		///usr/bin/ld: cannot open output file Neuron: Text file busy



