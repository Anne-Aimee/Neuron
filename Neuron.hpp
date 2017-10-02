#ifndef NEURON_H
#define NEURON_H


#include <vector>
#include <cmath>
//#include <iostream>



class Neuron {
	
	public :
	
	Neuron(double V_=0.0, double t_=0.0, int s_=0);
	Neuron(const Neuron&); //constructeur de copie
	~Neuron();
	
	void update_state();
	void update_V();
	bool refractory();
	
	int get_t();
	
	
	private :
	double V; // membrane potential
	int s; //number of spikes
	int t; //times when the spikes occured (duree = t*tau)
 // a initialiser plutot dans constructeur ? (en valeur par défaut) == pour tous les elements de private...
	vector<double> spike_times ;
	
	static const double VTH(10); // a initialiser !
	static const double tau(20);//correspond a des millisecondes = pas de temps
	static const double Iext(10);//a initialiser + je sais pas a quoi ca correspond
	static const double R(10);//a initialiser + je sais pas a quoi ca correspond
	static const double C0(10); //a initialiser + je sais pas a quoi ca correspond
	static const double C1(exp(-tau/C0));
	static const double C2(Iext*R(1-C1));
	
};


#endif

