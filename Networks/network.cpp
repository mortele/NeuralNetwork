#include "network.h"
#include "../neuron.h"
#include "../ActivationFunctions/activationfunction.h"

using std::vector;
using std::endl;
using std::cout;
using std::setw;
using std::setprecision;


Network::Network(System* system,
                 int inputs,
                 int outputs,
                 int layers,
                 int neuronsPerLayer) {

    m_system            = system;
    m_inputs            = inputs;
    m_outputs           = outputs;
    m_hiddenLayers      = layers;
    m_neuronsPerLayer   = neuronsPerLayer;

    setupLayers();
    setWeightsForAllNeurons();
}

vector<double> Network::evaluate(vector<double> input) {
    clearAllNeurons();
    setInput(input);
    for (int i=1; i<m_layers.size()-1; i++) {
        propagateLayer(i);
    }
    return computeOutput();
}

void Network::clearAllNeurons() {
    for (int i=0; i<m_layers.size(); i++) {
        for (int j=0; j<at(m_layers, i).size(); j++) {
            at(at(m_layers, i), j)->clear();
        }
    }
}

void Network::setupLayers() {
    m_layers.resize(m_hiddenLayers+2);
    for (int i=0; i<m_hiddenLayers+2; i++) {
        int jMax, neuronsInNextLayer;
        if (i==0) {
            jMax = m_inputs;
            if (m_hiddenLayers==0) {
                neuronsInNextLayer = m_outputs;
            } else {
                neuronsInNextLayer = m_neuronsPerLayer;
            }
        } else if (i==m_hiddenLayers+1) {
            jMax                = m_outputs;
            neuronsInNextLayer  = 0;
        } else {
            jMax                = m_neuronsPerLayer;
            neuronsInNextLayer  = m_neuronsPerLayer;
        }

        for (int j=0; j<jMax; j++) {
            at(m_layers, i).push_back(new Neuron(m_system, neuronsInNextLayer));
        }
    }
}

void Network::propagateLayer(int index) {
    for (int j=0; j<at(m_layers, index-1).size(); j++) {
        for (int k=0; k<at(m_layers, index).size(); k++) {
            at(at(m_layers, index), k)->addInput(
                        at(at(m_layers, index-1), j)->propagateToNextLayer(k));
        }
    }
    for (int j=0; j<at(m_layers, index).size(); j++) {
        at(at(m_layers, index), j)->computeTransferFunction();
    }
}

void Network::setWeightsForAllNeurons() {
    for (int i=0; i<m_layers.size(); i++) {
        for (int j=0; j<(at(m_layers, i).size()); j++) {
            if (i==0) {
                for (int k=0; k<at(at(m_layers, i), j)->getWeights().size(); k++) {
                    at(at(m_layers, i) ,j)->setWeight(1.0, k);
                }
            } else {
                at(at(m_layers, i), j)->randomizeWeights();
            }
        }
    }
}

void Network::printNetwork() {
    cout << " -- NETWORK --" << endl << endl;
    for (int i=0; i<m_layers.size(); i++) {
        cout << "Layer #" << i << endl;
        for (int j=0; j<at(m_layers, i).size(); j++) {
            Neuron* neuron = at(at(m_layers, i), j);
            cout << "   Neuron #(" << i << ", " << j << ") ";
            cout << "   input:  " << setw(6) << setprecision(4) << neuron->getInput();
            cout << "   output: " << setw(6) << setprecision(4) << neuron->getOutput() << endl;
            for (int k=0; k<neuron->getWeights().size(); k++) {
                cout << "          weight (" << i << ", " << j << ")->("
                     << i+1 << ", " << k << "): " << at(neuron->getWeights(), k) << endl;
            }
        }
    }
    cout << endl;
}

void Network::setInput(vector<double> input) {
    for (int j=0; j<at(m_layers, 0).size(); j++) {
        at(at(m_layers, 0), j)->addInput(at(input, j));
    }
    for (int j=0; j<at(m_layers, 0).size(); j++) {
        at(at(m_layers, 0), j)->computeTransferFunction();
    }
}

vector<double>& Network::computeOutput() {
    m_output.reserve(m_outputs);
    const int index = m_layers.size();
    for (int j=0; j<at(m_layers, index-2).size(); j++) {
        Neuron* penultimateNeuron = at(at(m_layers, index-2), j);
        for (int k=0; k<at(m_layers, index-1).size(); k++) {
            Neuron* ultimateNeuron = at(at(m_layers, index-1), k);
            ultimateNeuron->addInput(penultimateNeuron->propagateToNextLayer(k));
        }
    }
    for (int j=0; j<m_outputs; j++) {
        at(at(m_layers, index-1), j)->propagateLastLayer();
        m_output.push_back(at(at(m_layers, index-1), j)->getOutput());
    }
    return m_output;
}
















