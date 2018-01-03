#pragma once
#include "utils.h"
#include "neuron.h"

#define INPUT_NEURON_COUNT 2
#define HIDDEN_LAYER_1_NEURON_COUNT 3

class NeuralNetworkXor {
private:
    /// Input neurons
    Neuron inputNeuron[INPUT_NEURON_COUNT];

    /// Hidden layer neurons
    Neuron hiddenLayer1Neuron[HIDDEN_LAYER_1_NEURON_COUNT];

    /// Output neuron
    Neuron outputNeuron;

    /// Input Neuron weights to each neuron in hidden layer
    double inputNeuronWeight[INPUT_NEURON_COUNT][HIDDEN_NEURON_LAYER_1_COUNT];

    /// Hidden Layer Neuron Weights to output
    double hiddenNeuronWeight[HIDDEN_NEURON_LAYER_1_COUNT];

    /// Utility method that performs sigmoid function
    double sigmoid(double value);

    /// Utility method that performs the derivative of sigmoid function
    /// Implemented using the following formula: f'(x) = f(x) * (1 - f(x))
    /// https://math.stackexchange.com/questions/78575/derivative-of-sigmoid-function-sigma-x-frac11e-x
    double sigmoidDerivative(double value);

public:
    NeuralNetworkXor();

    /// Trains the neural network
    void trainNetwork(int input1, int input2, double expectedOutput);

    /// Perform neural network using XOR
    double performXor(int input1, int input2);
};
