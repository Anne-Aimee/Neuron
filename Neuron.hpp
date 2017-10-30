#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <array>
#include <cmath>
#include <iostream>
using namespace std;

class Neuron {
	
	public :
	
	Neuron(double Iext_=1.2,double V_=0.0);
	
	//=====CONSTANTES=====//
	
	static constexpr double VTHR=20.0;	//spike threshold
	static constexpr double Vext=2*VTHR;
	const double tau=20.0;				//membrane time constant
	static constexpr double h=0.1;		//integration stepsize
	const double RT=2.0;				//refractory time (ms)
	const double R=20.0;				//membrane resistance
	static constexpr double delay=1.5;	//delay for sending J between connexions
	static const int delaystep=delay/h;	//delay in time steps
	const double JE =0.1; 				//current given to neighbours when excitatory neuron spikes
	
	double Iext;						//external current
	double Vreset;						//V after refractory time
	double C1;							//constant used in update_V formula
	double C2;							//constant used in update_V formula
	double RTstep;						//refractory steps 
	double J; 							//current given to neighbours when neuron spikes								
	//===================//
	
	
	//===== GETTERS========//
	int get_t() const;
	double get_V() const;
	int get_s() const;
	double get_h() const;
	double getexternalnoise();			//external noise (in mV)
	//=====================//
	
	//===== SETTERS========//
	///void askIext();
	void setexcitatory(bool b);
	//=====================//
	
	bool spike;							//existence of spike
	bool isexcitatory;					//type of neuron (excitatory=true, inhibitory=false)
	
	bool update_state(unsigned int nbsteps);
	void update_V();
	void receive(int td, double J_);
	
	private :
	
	double V; 							//membrane potential
	int s; 								//number of spikes
	int t; 								//times when the spikes occured (duree = t*h)
	int spiketime; 						//step of time of the last spike
	array<int,delaystep+1> spikebuff ;  //buffer where incoming J from neighbours' spikes are stocked to be read after delay 
	
};


#endif


































