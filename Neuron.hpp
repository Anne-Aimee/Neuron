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
	bool refractory();
	
	int get_t() const;
	double get_V() const;
	int get_s() const;
	
	
	private :
	double V; // membrane potential
	int s; //number of spikes
	int t; //times when the spikes occured (duree = t*tau)
	vector<double> spike_times ;
	
	static constexpr double VTH=10.0; // a initialiser !
	static constexpr double tau=20.0;//correspond a des millisecondes = pas de temps
	static constexpr double Iext=10.0;//a initialiser + je sais pas a quoi ca correspond
	static constexpr double R=10.0;//a initialiser + je sais pas a quoi ca correspond
	static constexpr double C0=10.0; //a initialiser + je sais pas a quoi ca correspond
	static constexpr double C1=exp(-tau/C0);
	static constexpr double C2=Iext*R*(1-C1);
	
};


#endif

