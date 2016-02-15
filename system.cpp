#include "system.h"
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



