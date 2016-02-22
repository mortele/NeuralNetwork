#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include "../vectorlookup.h"

class Network {
public:
    Network(class System*);

    virtual std::vector<double>     evaluate(std::vector<double>);
    void                            randomizeAllWeights();
    void                            printNetwork();
    void                            setInput(std::vector<double> input);
    void                            clearNetwork();
    void                            setup();
    void                            addInputLayer(int inputs);
    void                            addLayer(int neurons);
    void                            addOutputLayer(int outputs);
    int                             getNumberOfInputs()     { return m_inputs; }
    int                             getNumberOfOutputs()    { return m_outputs; }
    std::vector<double>&            computeOutput();

protected:
    bool                            m_isReady           = false;
    bool                            m_inputLayerSet     = false;
    bool                            m_outputLayerSet    = false;
    int                             m_outputs           = 0;
    int                             m_inputs            = 0;
    int                             m_neuronsPerLayer   = 0;
    int                             m_numberOfLayers    = 0;
    class System*                   m_system            = nullptr;
    std::vector<class Layer*>       m_layers;
    std::vector<double>             m_output;
};

