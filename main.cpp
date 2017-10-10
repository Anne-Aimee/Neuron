#include "Neuron.hpp"
#include <vector>

void simulation(Neuron n1,Neuron n2, double tstop) {
	while (n2.get_t()<(tstop/n2.h)){
		std::cout<<"t " <<n2.get_t()<< std::endl;
	n1.update_state();
	n2.update_state();
}
	cout<<"simulation finie :)"<<endl;
}
void create_neighborhood(Neuron n1, Neuron n2 ){
	
	n2.add_neighbor(&n1);
}

int main(){
	
	Neuron n1;
	Neuron n2 (0.0);
	create_neighborhood(n1, n2);
	simulation(n1,n2, 100);
	
	return 0;
}


///gérer les vecteurs (pour eviter les segfault)
