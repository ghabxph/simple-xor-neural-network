#pragma once
#include <math.h>

class Neuron {
private:
    double value;

    /// Sigmoid function
    double sigmoid(double value);

public:
    /// Retrieves the neuron's value
    double getValue();

    /// Sets the neuron's value
    void setValue(double value);

    /// Clears the neuron
    void clearNeuron();

    /// Adds an input to the neuron
    void addInput(Neuron neuron, double weight);

    /// Activates the neuron (using sigmoid function)
    void activate();
};
