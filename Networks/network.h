#pragma once
#include <vector>
#include "../vectorlookup.h"

using std::vector;


class Network {
public:
    Network(class System*, int, int, int, int);

    virtual vector<double>          evaluate(vector<double>) = 0;
    vector<class Neuron*>           getLayer(int index) { return at(m_layers, index); }
    vector<vector<class Neuron*>>   getNeurons()        { return m_layers; }

private:
    int                             m_outputs           = 0;
    int                             m_inputs            = 0;
    int                             m_neuronsPerLayer   = 0;
    int                             m_hiddenLayers      = 0;
    class System*                   m_system            = nullptr;
    vector<vector<class Neuron*>>   m_layers;
};

