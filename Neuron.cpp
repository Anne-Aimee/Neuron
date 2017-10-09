#include "Neuron.hpp"

Neuron::Neuron(double V_, int t_, int s_) {
	V=V_;
	t=t_;
	s=s_;
	RT=0;
}

int Neuron::get_t() const {
	return t;
}
int Neuron::get_s() const {
	return s;
}
double Neuron::get_V() const {
	return V;
}
double Neuron::get_h() const {
	return h;
}

void Neuron::update_V(){
	if (RT>1){
		V=0;}
	if (RT==1){
		V=Vreset;}
	else {
		int nbJ(0);
		for (auto neigh : neighbours){
			if (neigh->spike()){
			++nbJ;}	
			V=C1*V+C2+nbJ*J;
		}
	}
}

void Neuron::update_RT(){
	if (RT>0)
	--RT;
}

bool Neuron::spike(){
	
	if (V>VTHR) {
	return true ;}   
	return false ; 
}

void Neuron::update_state(){
	
	if (spike()){
		spike_times.push_back(t);
		RT=RTI+1; }
	update_V();
	update_RT();
	++t;
}
