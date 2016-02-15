#include "neuron.h"
#include <cmath>
#include "vectorlookup.h"

using std::exp;

Neuron::Neuron(int numberOfNeuronsInNextLayer) {
    m_numberOfNeuronsInNextLayer = numberOfNeuronsInNextLayer;
}

void Neuron::addInput(double input) {
    m_totalInput += input;
}

void Neuron::computeTransferFunction() {
    m_output = 1.0 / (1 + exp(-m_totalInput));
}

void Neuron::propagateToNextLayer() {
    for (int i=0; i<m_numberOfNeuronsInNextLayer; i++) {
        at(m_connectedNeurons,i)->addInput(at(m_weights,i) * m_output);
    }
}

