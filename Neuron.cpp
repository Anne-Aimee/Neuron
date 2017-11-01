#include "Neuron.hpp"
#include <cassert>
#include <random>
#include <iomanip>



	/* constructor
	 */
Neuron::Neuron(double Iext_,double V_) {
	
	C1=exp(-h/tau);
	C2=R*(1.0-C1);
	V=V_;
	Vreset=0.0;
	J=0.1;
	RTstep=RT/h;
	spiketime= -RTstep;
	Iext=Iext_;
	spike=false;
	assert(spikebuff.size()==delaystep+1);
	t=0;
	
	for(auto& element: spikebuff){element=0;}
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

double Neuron::getexternalnoise(){
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> poisson_gen(Vext*h/(JE*tau));
	return poisson_gen(gen);
	
	}

	/* update the membrane tension value 
	 * associated with the last tension value and with spikes of neighbours and external current
	 */
void Neuron::update_V(){
	double S(spikebuff[t%(delaystep+1)]/*+getexternalnoise()*/);
	cerr<<"index of reading "<< t%(delaystep+1)<< endl;
	if ((t-spiketime)<RTstep){
		V=0.0;}
	else {
		
		V=C1*V+Iext*C2+S;} 
		cerr<<"spike buff t "<<spikebuff[t%(delaystep+1)]<< endl;
	spikebuff[t%(delaystep+1)]=0;
}

	/* update the state of the neuron a certain number of times (to make it spike or not)
	 * @param unsigned int : number of steps for updating
	 * @see update_V()
	 * @return spike (true pour existence d'un spike false sinon)
	 */
bool Neuron::update_state(unsigned int nbsteps){
	
	spike=false;
	for (unsigned int i(0);i<nbsteps;++i){
		
		
		
		
		if (V>=VTHR){
			spike=true;
			spiketime=t;
			
			++s;
			//cerr<<"DEBUG : time " << t << endl;
		}
		
		update_V(); //le buffer est remis a 0 a cet endroit precis
		//cerr<<"DEBUG : membrane pote " << get_V() << endl;
		++t;
		cerr<<"DEBUG : time " << t << endl;
	}
	return spike;
}

	/* receives the spike from neighbours and put it (write) in the corresponding place in the buffer
	 * (with the delay)
	 */
void Neuron::receive(int td, double J_){
	const unsigned int tout = td%(delaystep+1);//-1
	assert(tout<spikebuff.size());
	spikebuff[tout]+=J_;
	cerr<<"DEBUG : receive J " << J_ << endl;
	cerr<<"BEBUG : index of writing "<<tout<<endl;
}
	/* setter
	 * @param bool : true to set the neuron as excitatory and false to set it as inhibitory
	 * modifies the boolean isexcitatory
	 */

void Neuron::setexcitatory(bool b){
	isexcitatory=b;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
