#include "system.h"
#include "RandomNumberGenerator/random.h"
#include "neuron.h"
#include "vectorlookup.h"

using std::vector;
using std::endl;
using std::cout;
using std::setw;
using std::setprecision;

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
        for (int k=0; k<at(m_layers, index).size(); k++) {
            at(at(m_layers, index), k)->addInput(
                        at(at(m_layers, index-1), j)->propagateToNextLayer(k));
        }
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

void System::printNetwork() {
    cout << " -- NETWORK WEIGHTS --" << endl << endl;
    for (int i=0; i<m_layers.size(); i++) {
        cout << "Layer #" << i << endl;
        for (int j=0; j<at(m_layers, i).size(); j++) {
            Neuron* neuron = at(at(m_layers, i), j);
            cout << "   Neuron #(" << i << ", " << j << ") ";
            cout << "   input:  " << setw(6) << setprecision(4) << neuron->getInput();
            cout << "   output: " << setw(6) << setprecision(4) << neuron->getOutput() << endl;
            for (int k=0; k<neuron->getWeights().size(); k++) {
                cout << "     " << k << " : " << at(neuron->getWeights(), k) << endl;
            }
        }
    }
}

vector<double> System::computeOutput() {
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

vector<double> System::compute(vector<double> input) {
    clearNeurons();
    setInput(input);
    for (int i=1; i<m_layers.size()-1; i++) {
        propagateLayer(i);
    }
    return computeOutput();
}



