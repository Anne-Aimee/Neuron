#include "Neuron.hpp"

TEST(NeuronTest, SpikeTimes) {
	Neuron neuron;
	neuron.update_state(); // renvoie un bool -> pas utilise 
	EXPECT_EQ(0, neuron.get_s());
	neuron.update_state();
	EXPECT_EQ(0,)
	
}

TEST(TwoNeuron,...PSSpike) {
	Neuron neuron1(1.01), neuron2(0.0);
	int delay = 15;
	for (auto ....) {
		if (neuron1.update_state())
			{ neuron2.receive(i+delaystep,J);
			  EXPECT_EQ(0.0, neuron1.get_V());
		  }
		  
	  }
}


//J ARRRIIIIIIIIIIIIIIIIIIIVE PAAS
