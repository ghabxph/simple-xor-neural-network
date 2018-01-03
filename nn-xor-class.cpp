#include "nn-xor-class.h"

NeuralNetworkXor::NeuralNetworkXor()
{
    /// Initial output
    output = 0;

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
void NeuralNetworkXor::trainNetwork(int input1, int input2, double expectedOutput)
{
    double sum = 0;
    for (int i = 0; i < HIDDEN_NEURON_LAYER_1_COUNT; i++) {
        hiddenNeuron[i] = sigmoid(input1 * inputNeuronWeight[0][i] + input2 * inputNeuronWeight[1][i]);
        cout << "Hidden Neuron #" << i + 1 << ": " << hiddenNeuron[i] << endl;
        sum += hiddenNeuron[i] * hiddenNeuronWeight[i];
    }
    output = sigmoid(sum);
    cout << "Output: " << output << endl;
    double marginOfError = expectedOutput - output;
    cout << "Margin of error: " << marginOfError << endl;
    double deltaOutput = sigmoidDerivative(sum) * marginOfError;
    cout << "Delta Output: " << deltaOutput << endl;

    for (int i = 0; i < HIDDEN_NEURON_LAYER_1_COUNT; i++) {
        inputNeuronWeight[1][i] = inputNeuronWeight[1][i] + (deltaOutput / hiddenNeuron[i]);
        cout << "New input neuron weight #" << i + 1 << ": " << inputNeuronWeight[1][i] << endl;
    }
}

double NeuralNetworkXor::performXor(int input1, int input2)
{
    double sum = 0;
    for (int i = 0; i < HIDDEN_NEURON_LAYER_1_COUNT; i++) {
        hiddenNeuron[i] = sigmoid(input1 * inputNeuronWeight[0][i] + input2 * inputNeuronWeight[1][i]);
        cout << "Hidden Neuron #" << i + 1 << ": " << hiddenNeuron[i] << endl;
        sum += hiddenNeuron[i] * hiddenNeuronWeight[i];
    }
    output = sigmoid(sum);
    return output;
}


/// Utility method that performs sigmoid function
double NeuralNetworkXor::sigmoid(double value)
{
    return 1 / (1 + (exp(-value)));
}

/// Utility method that performs the derivative of sigmoid function
/// Implemented using the following formula: f'(x) = f(x) * (1 - f(x))
/// https://math.stackexchange.com/questions/78575/derivative-of-sigmoid-function-sigma-x-frac11e-x
double NeuralNetworkXor::sigmoidDerivative(double value)
{
    return sigmoid(value) * (1 - sigmoid(value));
}
