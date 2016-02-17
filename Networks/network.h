#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include "../vectorlookup.h"

using std::vector;


class Network {
public:
    Network(class System*, int, int, int, int);

    vector<double>                  evaluate(vector<double>);
    void                            setWeightsForAllNeurons();
    void                            printNetwork();
    void                            setInput(vector<double> input);
    void                            clearAllNeurons();
    void                            setupLayers();
    void                            propagateLayer(int index);
    vector<double>                  computeOutput();
    vector<class Neuron*>           getLayer(int index) { return at(m_layers, index); }
    vector<vector<class Neuron*>>   getNeurons()        { return m_layers; }

protected:
    int                             m_outputs           = 0;
    int                             m_inputs            = 0;
    int                             m_neuronsPerLayer   = 0;
    int                             m_hiddenLayers      = 0;
    class System*                   m_system            = nullptr;
    vector<double>                  m_output;
    vector<vector<class Neuron*>>   m_layers;
};

