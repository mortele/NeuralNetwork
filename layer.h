#pragma once
#include <vector>

class Layer {
public:
    Layer(class System* system);
    Layer(class System* system, bool input, bool output);
    void addNeuron(class Neuron* neuron);
    void setupWeights(Layer* nextLayer);
    void propagate();
    void clearLayer();
    int  getNumberOfNeurons() { return m_numberOfNeurons; }
    std::vector<double>&                getOutput();
    std::vector<class Neuron*>&         getNeurons() { return m_neurons; }
    std::vector<std::vector<double>>&   getWeights() { return m_weights; }

private:
    bool                             m_isInput           = false;
    bool                             m_isOutput          = false;
    int                              m_numberOfNeurons   = 0;
    class System*                    m_system            = nullptr;
    class Layer*                     m_nextLayer         = nullptr;
    std::vector<class Neuron*>       m_neurons;
    std::vector<double>              m_output;
    std::vector<std::vector<double>> m_weights;
};

