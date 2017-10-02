

void simulation(Neuron n, double tstop) {
	while (n.get_t()<tstop)
	n.update_state();
}

int main(){
	Neuron n;
	simulation(n, 100);
	
	return 0;
}

