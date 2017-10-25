#ifndef NEURON_H
#define NEURON_H

#include <cassert>
#include <vector>
#include <array>
#include <cmath>
#include <iostream>
using namespace std;

class Neuron {
	
	public :
	
	Neuron(double Iext_=1.2,double V_=0.0, int t_=0.0, int s_=0);
	
	//=====CONSTANTES=====//
	
	const double VTHR=20.0;				//spike threshold
	const double tau=20.0;				//membrane time constant
	static constexpr double h=0.1;		//integration stepsize
	const double RT=2.0;				//refractory time (ms)
	const double R=20.0;				//membrane resistance
	static constexpr double delay=1.5;
	static const int delaystep=delay/h;
	//const double poisson_gen ;
	
	double Iext;						//external current
	double Vreset;				//V apres le refractory
	double C1;
	double C2;
	double RTstep;						//refractory steps 
	double J; // correspond a ce qu'on rajoute au V quand un des voisins a un spike
	//===================//
	
	
	//===== GETTERS========//
	int get_t() const;
	double get_V() const;
	int get_s() const;
	double get_h() const;
	//=====================//
	
	
	
	bool spike;							//existence of spike
	array<int,delaystep+1> spikebuff ;   ///a remettre ensuite dans private !!! juste uitle pour les tests
	bool update_state();
	void update_V();
	void receive(int td, double J_);
	///bool excitatory;
	
	
	private :
	
	double V; 							//membrane potential
	int s; 								//number of spikes
	int t; 								//times when the spikes occured (duree = t*h)
	int spiketime; //indique le pas du dernier spike apparu
	
};


#endif


































