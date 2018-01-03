#include "nn-xor-class.h"

NeuralNetworkXor::NeuralNetworkXor()
{
    /// Initial input (just dummy)
    inputNeuron[0] = 1;
    inputNeuron[1] = 1;

    /// Initial input neuron weights to hidden layer neurons
    inputNeuronWeight[0][0] = 0.8;
    inputNeuronWeight[0][1] = 0.4;
    inputNeuronWeight[0][2] = 0.3;
    inputNeuronWeight[1][0] = 0.2;
    inputNeuronWeight[1][1] = 0.9;
    inputNeuronWeight[1][2] = 0.5;

    /// Initial hidden neuron weights to output neuron
    hiddenNeuronWeight[0] = 0.3;
    hiddenNeuronWeight[1] = 0.5;
    hiddenNeuronWeight[2] = 0.9;
}

/// Trains the neural network
void NeuralNetworkXor::trainNetwork()
{
    for (int i = 0; i < HIDDEN_NEURON_LAYER_1_COUNT; i++) {
        hiddenNeuron[i] = 0;
        for (int j = 0; j < INPUT_NEURON_COUNT; j++) {
            hiddenNeuron[i] += inputNeuron[j] * inputNeuronWeight[j][i];
        }
        hiddenNeuron[i] = sigmoid(hiddenNeuron[i]);
        int count = i + 1;
        cout << "Hidden Neuron #" << count << ": " << hiddenNeuron[i] << endl;
    }

    for (int i = 0; i < HIDDEN_NEURON_LAYER_1_COUNT; i++) {
        output += hiddenNeuron[i] * hiddenNeuronWeight[i];
    }
    output = sigmoid(output);

    cout << "Output: " << output << endl;
}

int NeuralNetworkXor::performXor(int input1, int input2)
{
    return 0;
}


/// Utility method that performs sigmoid function
double NeuralNetworkXor::sigmoid(double value)
{
    return 1 / (1 + (exp(-value)));
}
