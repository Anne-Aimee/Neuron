
#include <array>
#include "Neuron.hpp"
#include "Simulation.hpp"
#include <vector>




int main(){
	Simulation sim;
	cerr<<"creation ok"<<endl;
	//t en ms 1s=1000ms
	sim.simule(1000);
	cerr<<"simulation ok"<<endl;
	return 0;
}





