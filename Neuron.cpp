#include "Neuron.hpp"

Neuron::Neuron(double Iext_,double V_, int t_, int s_) {
	
	C1=exp(-h/tau);
	C2=R*(1.0-C1);
	V=V_;
	Vreset=0.0;
	Vext=VTHR*2;
	J=VTHR/2;
	t=t_;
	s=s_;
	RTstep=RT/h;
	Iext=Iext_;
	spike=false;
	assert(spikebuff.size()==delaystep+1);
	//poisson_gen
	///pas bien compris comment fonctionnait le truc avec poisson
}


	/* getters
	 * s : number of spikes
	 * V : membrane potential 
	 * h : integration stepsize
	 */ 
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


	/* update the membrane tension value 
	 * associated with the last tension value and with spikes of neighbours and external current
	 */
void Neuron::update_V(){
	double S(spikebuff[t%(delaystep+1)]);
	if ((t-spiketime)<RTstep){
		V=0.0;}
	else {
		V=C1*V+Iext*C2+S;}
	spikebuff[t%(delaystep+1)]=0;
}

	/* update the state of the neuron (if it spikes or not)
	 * @return spike (true pour existence d'un spike false sinon)
	 */
bool Neuron::update_state(){
	spike=false;
	if (V>VTHR){
		spike=true;
		spiketime=t;
	}
	update_V(); //le buffer est remis a 0 a cet endroit precis
	++t;
	return spike;
}

	/* receive the spike from neighbours and put it in the corresponding place in the buffer
	 * (with the delay)
	 */
void Neuron::receive(int td, double J_){
	const unsigned int tout = td%(delaystep+1);
	assert(tout<spikebuff.size());
	spikebuff[tout]+=J_;
}
	

void Neuron::setexcitatory(bool b){
	isexcitatory=b;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
