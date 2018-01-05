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
void Neuron::backPropagate()
{
    Neuron *sourceNeuron;
    double oldWeight = 0;
    for (unsigned int i = 0; i < connectedSynapses.size(); i++) {
        connectedSynapses[i]->updateWeight(deltaValue);
        oldWeight = connectedSynapses[i]->getOldWeight();
        sourceNeuron = connectedSynapses[i]->getSource();
        sourceNeuron->backPropagateByMargin(deltaValue / oldWeight);
    }
}
