#include "system.h"
#include "RandomNumberGenerator/random.h"
#include "neuron.h"
#include "vectorlookup.h"

using std::vector;
using std::endl;
using std::cout;


System::System(int hiddenLayers,
               int neuronsInEachLayer,
               int inputs,
               int outputs) {

    m_neuronsInEachLayer    = neuronsInEachLayer;
    m_hiddenLayers          = hiddenLayers;
    m_inputs                = inputs;
    m_outputs               = outputs;
    Random::seed(m_seed);
    setupLayers();
    randomizeAllWeights();
    clearNeurons();
}

void System::setupLayers() {
    m_layers.resize(m_hiddenLayers+2, vector<Neuron*>());

    for (int j=0; j<m_inputs; j++) {
        at(m_layers, 0).push_back(new Neuron(m_neuronsInEachLayer));
    }
    for (int i=1; i<m_hiddenLayers; i++) {
        for (int j=0; j<m_neuronsInEachLayer; j++) {
            at(m_layers, i).push_back(new Neuron(m_neuronsInEachLayer));
        }
    }
    for (int j=0; j<m_neuronsInEachLayer; j++) {
        at(m_layers, m_hiddenLayers).push_back(new Neuron(m_outputs));
    }
    for (int j=0; j<m_outputs; j++) {
        at(m_layers, m_hiddenLayers+1).push_back(new Neuron(0));
    }
}

void System::randomizeAllWeights() {
    for (int i=0; i<m_layers.size(); i++) {
        for (int j=0; j<at(m_layers, i).size(); j++) {
            at(at(m_layers, i), j)->randomizeWeights();
        }
    }
}

void System::clearNeurons() {
    for (int i=0; i<m_layers.size(); i++) {
        for (int j=0; j<at(m_layers, i).size(); j++) {
            at(at(m_layers, i), j)->clear();
        }
    }
}

void System::propagateLayer(int index) {
    for (int j=0; j<at(m_layers, index-1).size(); j++) {
        at(at(m_layers, index-1), j)->propagateToNextLayer();
    }
    for (int j=0; j<at(m_layers, index).size(); j++) {
        at(at(m_layers, index), j)->computeTransferFunction();
    }
}

void System::setInput(vector<double> input) {
    for (int j=0; j<m_inputs; j++) {
        at(at(m_layers, 0), j)->addInput(at(input, j));
        at(at(m_layers, 0), j)->computeTransferFunction();
    }
}

vector<double> System::computeOutput() {
    m_output.reserve(m_outputs);
    const int index = m_layers.size();
    for (int j=0; j<at(m_layers, index-1).size(); j++) {
        at(at(m_layers, index-1), j)->propagateToNextLayer();
    }
    for (int j=0; j<m_outputs; j++) {
        m_output.push_back(at(at(m_layers, index), j)->getOutput());
    }
    return m_output;
}

vector<double> System::compute(vector<double> input) {
    clearNeurons();
    setInput(input);
    for (int i=1; m_layers.size()-1; i++) {
        propagateLayer(i);
    }
    return computeOutput();
}



