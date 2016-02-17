#pragma once
#include <vector>

using std::vector;

class Neuron {
public:
    Neuron(class System* system, int neuronsInNextLayer);

    void addInput(double input);
    void computeTransferFunction();
    void clear();
    void randomizeWeights();
    void propagateLastLayer();
    void setWeight(double weight, int index);
    void setActivationFunction(class ActivationFunction*);
    double propagateToNextLayer(int index);
    double getInput()  { return m_totalInput; }
    double getOutput() { return m_output; }
    vector<double>& getWeights() { return m_weights; }

private:
    int                         m_neuronsInNextLayer    = 0;
    double                      m_totalInput            = 0;
    double                      m_output                = 0;
    class System*               m_system                = nullptr;
    class ActivationFunction*   m_activationFunction    = nullptr;
    vector<double>              m_weights;
};

