#ifndef NEURON_H
#define NEURON_H


#include <vector>
#include <cmath>
using namespace std;
//#include <iostream>


class Neuron {
	
	public :
	
	Neuron(double V_=0.0, int t_=0.0, int s_=0);
	Neuron(const Neuron&); //constructeur de copie
	
	void update_state();
	void update_V();
	void update_RT();
	
	int get_t() const;
	double get_V() const;
	int get_s() const;
	
	
	private :
	double V; // membrane potential
	int s; //number of spikes
	int t; //times when the spikes occured (duree = t*h)
	int RT;
	vector<double> spike_times ;
	
	static constexpr int RTI=1;// refractor time (multiple of h)
	static constexpr double VTHR=20.0;// Vseuil (for spikes)
	static constexpr double Vreset=0.0;/// non utilisé+ je sais pas a quoi ca correspond
	static constexpr double tau=20.0;//correspond a des millisecondes = constante de temps
	static constexpr double h=1.0;//correspond a des millisecondes = pas de temps
	static constexpr double Iext=10.0;///entrée de courant, correspond a qqch plus tard, initialisé au pif
	static constexpr double R=0.02;//membrane resistance
	static constexpr double C1=exp(-h/tau);
	static constexpr double C2=Iext*R*(1-C1);
    //pour mettre a jour V, ne pas oublier que quand spike pendant duree definie, il peut pas y avoir respike
    //from documentation (dont know the correspondance with the course formula) θ =20mV;Vr =10mV;τrp =2ms.
};


#endif

