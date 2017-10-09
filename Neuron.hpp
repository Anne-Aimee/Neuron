#ifndef NEURON_H
#define NEURON_H


#include <vector>
#include <cmath>
using namespace std;
#include <iostream>


class Neuron {
	
	public :
	
	Neuron(double V_=0.0, int t_=0.0, int s_=0);

	
	void update_state();
	bool spike();
	void update_V();
	void update_RT();
	
	int get_t() const;
	double get_V() const;
	int get_s() const;
	double get_h() const;
	
	//=====CONSTANTES=====//
	static constexpr int RTI=1;// refractor time (multiple of h)
	static constexpr double VTHR=20.0;// Vseuil (for spikes)
	static constexpr double Vreset=0.0;//V apres le refractory
	static constexpr double tau=20.0;//correspond a des millisecondes = constante de temps
	static constexpr double h=1.0;//correspond a des millisecondes = pas de temps
	static constexpr double Iext=1.2;///entrée de courant, correspond a qqch plus tard, initialisé au pif
	static constexpr double R=20;//membrane resistance
	static constexpr double C1=exp(-h/tau);
	static constexpr double C2=Iext*R*(1-C1);
	static constexpr double J=1.0; // correspond a ce qu'on rajoute au V quand un des voisins a un spike
	//===================//
	
	private :
	double V; // membrane potential
	int s; //number of spikes
	int t; //times when the spikes occured (duree = t*h)
	int RT;
	vector<double> spike_times ;
	vector<Neuron*> neighbours ;
	
    //from documentation (dont know the correspondance with the course formula) θ =20mV;Vr =10mV;τrp =2ms.
};


#endif

