/**
 * Copyright 2017 ghabxph(c)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once
#include "utils.h"
#include "neuron.h"

#define INPUT_NEURON_COUNT 2
#define HIDDEN_NEURON_COUNT 3

class NeuralNetworkXor
{
private:
    /// Input neurons
    Neuron *input[INPUT_NEURON_COUNT];

    /// Hidden layer neurons
    Neuron *hidden[HIDDEN_NEURON_COUNT];

    /// Output neuron
    Neuron *output;

    /// Creates instances of neurons (input, hidden, output)
    void createNeurons()
    {
        /// Creates new input neurons
        for (int i = 0; i < INPUT_NEURON_COUNT; i++) {
            input[i] = new Neuron();
        }
        /// Creates new hidden neurons
        for (int i = 0; i < HIDDEN_NEURON_COUNT; i++) {
            hidden[i] = new Neuron();
        }
        /// Creates an output neuron
        output = new Neuron();
    }

public:
    /// Constructor
    NeuralNetworkXor()
    {
        /// Weight declarations for each layers (input, hidden output)
        double inputToHiddenWeights[2][3];
        double hiddenToOutputWeights[3];

        /// Weight initialization for each layers.
        inputToHiddenWeights[0][0] = 0.8;
        inputToHiddenWeights[0][1] = 0.4;
        inputToHiddenWeights[0][2] = 0.3;
        inputToHiddenWeights[1][0] = 0.2;
        inputToHiddenWeights[1][1] = 0.9;
        inputToHiddenWeights[1][2] = 0.5;
        hiddenToOutputWeights[0]   = 0.3;
        hiddenToOutputWeights[1]   = 0.5;
        hiddenToOutputWeights[2]   = 0.9;

        /// Creates a new instance of neurons
        createNeurons();

        /// Connecting input neurons to hidden neurons
        for (int i = 0; i < INPUT_NEURON_COUNT; i++) {
            for (int j = 0; j < HIDDEN_NEURON_COUNT; j++) {
                input[i]->connect(hidden[j], inputToHiddenWeights[i][j]);
            }
        }

        /// Connecting hidden neurons to output neuron
        for (int i = 0; i < HIDDEN_NEURON_COUNT; i++) {
            hidden[i]->connect(output, hiddenToOutputWeights[i]);
        }
    }

    /// Trains the neural network
    void trainNetwork(double input1, double input2, double expectedOutput) {
        performXor(input1, input2);
        output->backPropagateByTargetValue(expectedOutput);
    }

    /// Perform neural network using XOR
    double performXor(int input1, int input2) {
        input[0]->setValue(input1)->propagate();
        input[1]->setValue(input2)->propagate();
        return output->getValue();
    }
};
