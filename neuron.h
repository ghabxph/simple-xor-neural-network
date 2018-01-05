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
#include <math.h>
#include <vector>
#include "synapse.h"

// delete please
#include <iostream>

using namespace std;

class Synapse;
class Neuron
{
private:
    /// Synapses connecting to its destination neurons
    vector<Synapse*> synapses;

    /// Connected synapse from parent neurons
    vector<Synapse*> connectedSynapses;

    /// Total number of parents who referenced this instance
    int parentCount;

    /// This count will be updated when a neuron sends a message through the synapse
    int senderCount;

    /// Neuron's value
    double value;

    /// Neuron's value before activation
    double valueBeforeActivation;

    /// Delta value
    double deltaValue;

    /// Utility method that computes the sigmoid function
    double sigmoid(double value)
    {
        return 1 / (1 + (exp(-value)));
    }

    /// Utility method that performs the derivative of sigmoid function
    /// Implemented using the following formula: f'(x) = f(x) * (1 - f(x))
    /// https://math.stackexchange.com/questions/78575/derivative-of-sigmoid-function-sigma-x-frac11e-x
    double sigmoidDerivative(double value)
    {
        return sigmoid(value) * (1 - sigmoid(value));
    }
public:

    /// Connects a neuron to another neuron
    void connect(Neuron *neuron, double weight);

    /// Inform this instance of neuron that some synapse is connecting to it
    void addConnectedSynapse(Synapse* synapse);

    /// Propagates the value up to the last neuron
    void propagate();

    /// Performs a back propagation
    void backPropagate();

    /// Constructor
    Neuron()
    {
        parentCount           = 0;
        senderCount           = 0;
        value                 = 0;
        valueBeforeActivation = 0;
        deltaValue            = 0;
    }

    /// Destructor
    ~Neuron()
    {
        for (unsigned int i = 0; i < synapses.size(); i++) {
            delete synapses[i];
        }
    }

    /// Adds +1 to parent count
    void incrementParentCount()
    {
        parentCount++;
    }

    /// Sets a value for our neuron
    Neuron *setValue(double value)
    {
        this->value = value;
        this->valueBeforeActivation = value;
        return this;
    }

    /// Returns the value of the neuron
    double getValue()
    {
        return value;
    }

    /// Activates the neuron
    ///   - uses sigmoid function
    void activate()
    {
        value = sigmoid(value);
        propagate();
    }

    /// Stimulates the neuron
    void stimulate(Neuron *source, Neuron *destination, double weight)
    {
        double tempValue = source->getValue() * weight;
        value = (senderCount == 0) ? tempValue : value + tempValue;
        valueBeforeActivation = value;
        senderCount++;
        if (senderCount >= parentCount) {
            activate();
            senderCount = 0;
        }
    }

    /// Gets the delta value
    double getDeltaValue() {
        return deltaValue;
    }

    /// Perform back propagation by target value
    void backPropagateByTargetValue(double targetValue)
    {
        double marginOfError = targetValue - value;
        backPropagateByMargin(marginOfError);
    }

    /// Performs a back propagation by margin value
    void backPropagateByMargin(double marginValue)
    {
        deltaValue = sigmoidDerivative(valueBeforeActivation) * marginValue;
        backPropagate();
    }
};
