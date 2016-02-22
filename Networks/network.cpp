#include "network.h"
#include "../neuron.h"
#include "../layer.h"
#include "../ActivationFunctions/activationfunction.h"

using std::vector;
using std::endl;
using std::cout;
using std::setw;
using std::setprecision;


Network::Network(System* system) {
    m_system            = system;
}

vector<double> Network::evaluate(vector<double> input) {
    if (m_isReady==false) {
        setup();
        m_isReady = true;
    }
    clearNetwork();
    setInput(input);
    for (int i=1; i<m_layers.size()-1; i++) {
        at(m_layers, i)->propagate();
    }
    return computeOutput();
}

void Network::randomizeAllWeights() {

}

void Network::clearNetwork() {
    for (int i=0; i<m_layers.size(); i++) {
        at(m_layers, i)->clearLayer();
    }
}

void Network::setup() {
    cout << "network::setup" << endl;
}

void Network::addInputLayer(int inputs) {
    if (m_inputLayerSet==true) {
        cout << "Error: Trying to set multiple input layers." << endl;
        std::exit(1);
    } else if (m_numberOfLayers==0) {
        m_layers.push_back(new Layer(m_system, 1, 0));
    } else if (m_numberOfLayers!=0) {
        at(m_layers, 0) = new Layer(m_system, 1, 0);
    }
}

void Network::addLayer(int neurons) {
    if (m_inputLayerSet==false) {
        m_layers.push_back(nullptr);    // Placeholder for future input layer.
        m_layers.push_back(new Layer(m_system));
    } else {
        m_layers.push_back(new Layer(m_system));
    }
}

void Network::addOutputLayer(int outputs) {
    if (m_inputLayerSet==false) {
        m_layers.push_back(nullptr);
        m_layers.push_back(new Layer(m_system, 0, 1));
    } else {
        m_layers.push_back(new Layer(m_system, 0, 1));
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
    return at(m_layers, m_hiddenLayers+1)->getOutput();
}
















