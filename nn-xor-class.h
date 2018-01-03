#pragma once
#include "utils.h"

#define INPUT_NEURON_COUNT 2
#define HIDDEN_NEURON_LAYER_1_COUNT 3

class NeuralNetworkXor {
private:
    /// Input Neurons
    double inputNeuron[INPUT_NEURON_COUNT];

    /// Input Neuron weights to each neuron in hidden layer
    double inputNeuronWeight[INPUT_NEURON_COUNT][HIDDEN_NEURON_LAYER_1_COUNT];

    /// Hidden Layer Neurons
    double hiddenNeuron[HIDDEN_NEURON_LAYER_1_COUNT];

    /// Hidden Layer Neuron Weights to output
    double hiddenNeuronWeight[HIDDEN_NEURON_LAYER_1_COUNT];

    /// Our precious output
    double output;

    /// Utility method that performs sigmoid function
    double sigmoid(double value);

public:
    NeuralNetworkXor();

    /// Trains the neural network
    void trainNetwork();

    /// Perform neural network using XOR
    int performXor(int input1, int input2);
};
