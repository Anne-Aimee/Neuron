#include "Neuron.hpp"
#include <vector>

void simulation(Neuron n, double tstop) {
	while (n.get_t()<(tstop/n.h))
	n.update_state();
	cout<<"simulation finie :)"<<endl;
}

int main(){
	Neuron n;
	simulation(n, 100);
	
	return 0;
}

