#pragma once
#include <vector>

using std::vector;

class Neuron {
public:
    Neuron(int neuronsInNextLayer);

    void addInput(double input);
    void computeTransferFunction();
    void clear();
    void randomizeWeights();
    void propagateLastLayer();
    double propagateToNextLayer(int index);
    double getInput()  { return m_totalInput; }
    double getOutput() { return m_output; }
    vector<double>& getWeights() { return m_weights; }

private:
    int                 m_neuronsInNextLayer    = 0;
    double              m_totalInput            = 0;
    double              m_output                = 0;
    vector<double>      m_weights;
};

