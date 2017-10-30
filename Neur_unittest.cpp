#include "Neuron.hpp"
#include "Simulation.hpp"
#include "gtest/gtest.h"


TEST(NeuronTest, CorrectV){
	Neuron neuron(1.01);
	bool spiketest;
	
	spiketest=neuron.update_state(924);
	
	
	//EXPECT_EQ(???,neuron.get_V());
	EXPECT_FALSE(spiketest);
	spiketest=neuron.update_state(1);
	EXPECT_TRUE(spiketest);
	EXPECT_EQ(0,neuron.get_V());
}




TEST(NeuronTest, SpikeTimes) {
	Neuron neuron(1.01);
	bool spiketest;
	//We know that the spikes times are at 92.4ms, 186.8 ms...
	
	//Waiting for first spike
	spiketest= neuron.update_state(1);
	EXPECT_EQ(0, neuron.get_s());
	EXPECT_FALSE(spiketest);
	
	
	spiketest=neuron.update_state(924);
	EXPECT_EQ(1,neuron.get_s());
	EXPECT_TRUE(spiketest);
	
	//Waiting for second spike
	spiketest=neuron.update_state(1);
	EXPECT_EQ(1,neuron.get_s());
	EXPECT_FALSE(spiketest);
	
	spiketest=neuron.update_state(943);
	EXPECT_EQ(2,neuron.get_s());
	EXPECT_TRUE(spiketest);
	
}

TEST(TwoNeuron,SendofJ) {
	Neuron neuron1(1.01), neuron2(0.0);
	int delaytest = 5;
	
	//We wait for the first spike in neuron1 to see the impact on neuron2
	for (int i=0;i<925+delaytest;++i) {
		if (neuron1.update_state(1)){ 
			neuron2.receive(i+delaytest,neuron1.J);
			EXPECT_EQ(0.0, neuron1.get_V());//suis pas sure de cette ligne pq si il spike il sera egal a 0 au tour suivant nan ?
		}
		neuron2.update_state(1);
	}
	EXPECT_EQ(0.1, neuron2.get_V());
}

TEST(TwoNeuron, DelayofJ){
	Neuron neuron1(1.0), neuron2(0.0);
	int delaytest = 5;
	int impact =-1; //nb of steps before the impact on neuron2
	//We wait for the first spike in neuron1 and see when it impacts neuron2
	for (int i=0;i<925+delaytest;++i) {
		if (neuron1.update_state(1)){ 
			neuron2.receive(i+delaytest,neuron1.J);
			++impact;
		}
		neuron2.update_state(1);
		if(impact>=0) ++impact;
	}
	EXPECT_EQ(0.1, neuron2.get_V());
	EXPECT_EQ(delaytest,impact);
}
/*
TEST(Network, simulation){
	Simulation sim;
	sim.simule(3);
	
}*/

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



/// tests fail et creer nouveau tests
