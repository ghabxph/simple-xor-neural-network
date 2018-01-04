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
    void backPropagate(double targetValue);

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
        return this;
    }

    /// Returns the value of the neuron
    double getValue()
    {
        return this->value;
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
        value += source->getValue() * weight;
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
};
