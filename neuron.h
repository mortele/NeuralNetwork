#pragma once
#include <vector>

using std::vector;

class Neuron {
public:
    Neuron(int numberOfNeuronsInNextLayer);

    void addInput(double input);
    void computeTransferFunction();
    void propagateToNextLayer();

private:
    int                 m_numberOfNeuronsInNextLayer    = 0;
    double              m_totalInput                    = 0;
    double              m_output                        = 0;
    vector<double>      m_weights;
    vector<Neuron*>     m_connectedNeurons;
};

