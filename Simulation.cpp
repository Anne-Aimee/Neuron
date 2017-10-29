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
	setexcitatoryneurons();
	initialconnexions();
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
		
	//a mettre dans une fonction ou qqpart	
	
void Simulation::initialconnexions(){		
for (unsigned int n(0);n<neurons.size();++n){	

	for (unsigned int e(0);e<CE;++e){
		unsigned int pre_excitatory (0); //pre_excitatory est le numero de la case pris au hasard parmis les numeros de case de excitatory neurons
		pre_excitatory = rand() % nb_excitatory; 
		//assert(neurons[pre_excitatory]->isexcitatory);
		//assert (pre_excitatory<nb_excitatory);
		++connexions[pre_excitatory][n];
	}
	for (unsigned int i(0);i<CI;++i){
		unsigned int pre_inhibitory (0);
		pre_inhibitory = rand() %  nb_inhibitory +(nb_excitatory+1); 
		//assert(! neurons[pre_inhibitory]->isexcitatory);
		//assert(pre_inhibitory>= nb_excitatory and pre_inhibitory<neurons.size());
		++connexions[pre_inhibitory][n];
	}	
///normalement les excitatory et inhibitory ne font pas le meme J ? quels J ?
	/*for (unsigned int ext(0);ext<CEXT;++ext){
		unsigned int pre_inhibitory (0);
	}*/
/// j'ai pas bien compris si les ext ils existaient ou pas 
	
}

}
		
void Simulation::setexcitatoryneurons(){
	for (i(0);i<nb_excitatory;++i){
		neurons[i]->setexcitatory(true);
	}
}
		
		
		///creer fonction isexcitatory dans le neuron
		
		


