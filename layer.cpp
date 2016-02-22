#include "layer.h"
#include <iostream>
#include "vectorlookup.h"
#include "system.h"
#include "neuron.h"
#include "RandomNumberGenerator/random.h"

Layer::Layer(System* system, bool input, bool output) {
    m_system    = system;
    m_isInput   = input;
    m_isOutput  = output;
}

Layer::Layer(System* system) :
    Layer(system, false, false) {
}

void Layer::addNeuron(Neuron* neuron) {
    m_neurons.push_back(neuron);
    m_numberOfNeurons++;
}

void Layer::setupWeights(Layer* nextLayer) {
    m_nextLayer = nextLayer;
    m_weights.resize(m_numberOfNeurons, std::vector<double>());
    for (int i=0; i<m_numberOfNeurons; i++) {
        const int neuronsInNextLayer = m_nextLayer->getNumberOfNeurons();
        m_weights.resize(neuronsInNextLayer);
        for (int j=0; j<neuronsInNextLayer; j++) {
            at(at(m_weight, i), j) = Random::nextGaussian(0,1);
        }
    }
}

void Layer::propagate() {
    if (m_isInput==false) {
        for (int i=0; i<m_numberOfNeurons; i++) {
            at(m_neurons, i)->computeTransferFunction();
        }
    }
    if (m_isOutput==false) {
        for (int j=0; j<m_nextLayer->getNeurons().size(); j++) {
            for (int i=0; j<m_numberOfNeurons; i++) {
                const double output = at(m_neurons, i)->getOutput() *
                                      at(m_weights, j);
                if (m_isOutput==false) {
                    at(m_nextLayer->getNeurons(), j)->addInput(output);
                }
            }
        }
    }
}

void Layer::clearLayer() {
    for (int i=0; i<m_numberOfNeurons; i++) {
        at(m_neurons, i)->clear();
    }
}

std::vector<double>&Layer::getOutput() {
    if (m_isOutput==false) {
        std::cout << "Warning: Getting output from non-output layer." << std::endl;
    }
    m_output.reserve(m_numberOfNeurons);
    for (int i=0; i<m_numberOfNeurons; i++) {
        m_output.push_back(at(m_neurons, i)->getOutput);
    }
    return m_output;
}

















