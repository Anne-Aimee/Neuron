#include "Neuron.hpp"
#include "Simulation.hpp"
#include "gtest/gtest.h"

TEST(OneNeuron, oneStep)
{
	Neuron neuron(1.0);
	bool spiketest;
	spiketest=neuron.update_state(1);
	EXPECT_NEAR(0.0997504,neuron.get_V(),0.001);
}

TEST(NeuronTest, CorrectV){
	Neuron neuron(1.01);
	bool spiketest;
	spiketest=neuron.update_state(924);
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


TEST(TwoNeuron,SendDelayofJ) {
	Neuron neuron1(1.01), neuron2(0.0);
	int delaytest = 15;
	
	//We wait for the first spike in neuron1 to see the impact on neuron2
	for (int i=0;i<925+delaytest;++i) {
		if (neuron1.update_state(1)){ 
			neuron2.receive(i+delaytest,neuron1.J);
			EXPECT_EQ(0.0, neuron1.get_V());
		}
		neuron2.update_state(1);
		cerr<<"neuron 2 V "<<neuron2.get_V()<<endl;
	}
	EXPECT_NEAR(0.1, neuron2.get_V(),0.001);
	
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



/// tous les tests de 1 ou 2 neurones fonctionnent 
