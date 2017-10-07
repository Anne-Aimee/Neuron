#include "Neuron.hpp"

Neuron::Neuron(double V_=0.0, int t_=0, int s_=0) {
	V=V_;
	t=t_;
	s=s_;
	RT=0;
}

int Neuron::get_t() {
	return t;
}

void Neuron::update_V(){
	if RT>0
	V=0;
	else V=C1*V+C2;
}

void Neuron::update_RT(){
	if RT>0
	--RT;
}


void Neuron::update_state(){
	 if (V>VTHR) {
		spike_times.push_back(t);//attention : ici on stocke le nb de h depuis le debut (pour connaitre la duree en ms, multiplier par h)
		RT=RTI;
}  
	update_V();
	update_RT();
	++t;
}
