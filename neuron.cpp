#include "neuron.h"

/// Connects a neuron to another neuron
void Neuron::connect(Neuron *neuron, double weight)
{
    synapses.push_back(new Synapse(this, neuron, weight));
}

/// Inform this instance of neuron that some synapse is connecting to it
void Neuron::addConnectedSynapse(Synapse* synapse)
{
    connectedSynapses.push_back(synapse);
}

/// Propagates the value up to the last neuron
void Neuron::propagate()
{
    for (unsigned int i = 0; i < synapses.size(); i++) {
        synapses[i]->stimulate();
    }
}

/// Performs a back propagation
void Neuron::backPropagate(double targetValue)
{
    double marginOfError = targetValue - value;
    deltaValue = sigmoidDerivative(valueBeforeActivation) * marginOfError;
    cout << "Sum: " << valueBeforeActivation << endl;
    cout << "Margin of error: " << marginOfError << endl;
    cout << "Delta Output: " << deltaValue << endl;
    for (int i = 0; i < connectedSynapses.size(); i++) {
        connectedSynapses[i]->updateWeight(deltaValue);
        double sourceDeltaValue = connectedSynapses[i]->getDestination()->getDeltaValue();
    }
}
