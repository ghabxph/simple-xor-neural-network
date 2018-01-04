#include "synapse.h"

/// Constructor
Synapse::Synapse(Neuron *source, Neuron *destination, double weight)
{
    this->source = source;
    this->destination = destination;
    this->weight = weight;
    this->oldWeight = weight;

    /// Increment the count of parent of destination
    this->destination->incrementParentCount();

    /// Informs destination neuron that this synapse is connecting to it
    this->destination->addConnectedSynapse(this);
}

/// Destructor
Synapse::~Synapse()
{
    delete this->source;
    delete this->destination;
}

/// Stimulates the destination neuron
void Synapse::stimulate()
{
    destination->stimulate(source, destination, weight);
}

/// Updates weight from delta output
void Synapse::updateWeight(double deltaOutput)
{
    oldWeight = weight;
    weight += (deltaOutput / source->getValue());
}
