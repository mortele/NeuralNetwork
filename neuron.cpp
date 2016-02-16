#include "neuron.h"
#include <cmath>
#include "vectorlookup.h"
#include "RandomNumberGenerator/random.h"

using std::exp;

Neuron::Neuron(int neuronsInNextLayer) {
    m_neuronsInNextLayer = neuronsInNextLayer;
    m_weights.reserve(m_neuronsInNextLayer);
}

void Neuron::addInput(double input) {
    m_totalInput += input;
}

void Neuron::computeTransferFunction() {
    m_output = 1.0 / (1 + exp(-m_totalInput));
}

double Neuron::propagateToNextLayer(int index) {
    return m_output * at(m_weights, index);
}

void Neuron::clear() {
    m_totalInput = 0;
    m_output = 0;
}

void Neuron::randomizeWeights() {
    m_weights.clear();
    for (int i=0; i<m_neuronsInNextLayer; i++) {
        m_weights.push_back(Random::nextGaussian(0.0, 1.0));
    }
}

void Neuron::propagateLastLayer() {
    m_output = m_totalInput;
}

