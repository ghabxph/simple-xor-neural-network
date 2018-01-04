#pragma once
#include "neuron.h"

class Neuron;
class Synapse
{
private:
    /// Synapse weight
    double weight;

    /// Old synapse weight
    double oldWeight;

    /// Source neuron
    Neuron *source;

    /// Destination neuron
    Neuron *destination;

public:
    /// Constructor
    Synapse(Neuron *source, Neuron *destination, double weight);

    /// Destructor
    ~Synapse();

    /// Stimulates the destination neuron
    void stimulate();

    /// Updates weight from delta output
    void updateWeight(double deltaOutput);

    /// Gets old weight (before updateWeight is applied)
    double getOldWeight()
    {
        return oldWeight;
    }

    /// Returns the source neuron
    Neuron *getSource()
    {
        return source;
    }

    /// Returns the destination neuron
    Neuron *getDestination()
    {
        return destination;
    }
};
