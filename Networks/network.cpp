#include "network.h"
#include "../neuron.h"

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

