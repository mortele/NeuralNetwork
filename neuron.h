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
    double propagateToNextLayer();
    double getOutput();

private:
    int                 m_neuronsInNextLayer    = 0;
    double              m_totalInput            = 0;
    double              m_output                = 0;
    vector<double>      m_weights;
};

