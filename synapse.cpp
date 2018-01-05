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
    cout << "Weight: " << weight << endl;
}
