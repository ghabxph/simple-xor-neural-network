#include "neuron.h"

/// --------------------------
/// Public Methods
/// ``````````````````````````

/// Retrieves the neuron's value
double Neuron::getValue()
{
    return value
}

/// Sets the neuron's value
void Neuron::setValue(double value)
{
    this->value = value;
}

/// Clears the neuron
void Neuron::clearNeuron()
{
    value = 0;
}

/// Adds an input to the neuron
void Neuron::addInput(Neuron neuron, double weight)
{
    value += neuron.getValue() * weight;
}

/// Activates the neuron (using sigmoid function)
void Neuron::activate()
{
    value = sigmoid(value);
}
/// --------------------------


/// --------------------------
/// Private methods
/// ``````````````````````````

/// Sigmoid function
double Neuron::sigmoid(double value)
{
    return 1 / (1 + (exp(-value)));
}
/// --------------------------
