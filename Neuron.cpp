#include "Neuron.hpp"

Neuron::Neuron(double V_=0.0, int t_=0, int s_=0) {
	V=V_;
	t=t_;
	s=s_;
}

int Neuron::get_t() {
	return t;
}


bool Neuron::refractory() {
	return V<=VTH;
}

void Neuron::update_V(){
	V=C1*V+C2;
}


void Neuron::update_state(){
	if refractory()
	V=0;
	else { 
		spike_times.push_back(t);//attention : ici on stocke le nb de tau depuis le debut (pour connaitre la duree, multiplier par tau)
		update_V();
}  
	++t;
}
