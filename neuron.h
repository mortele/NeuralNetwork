#pragma once
#include <vector>

using std::vector;

class Neuron {
public:
    Neuron(class System* system);
    void addInput(double input);
    void computeTransferFunction();
    void clearNeuron();
    void setActivationFunction(class ActivationFunction*);
    double getInput()  { return m_totalInput; }
    double getOutput() { return m_output; }

private:
    double                      m_totalInput            = 0;
    double                      m_output                = 0;
    class System*               m_system                = nullptr;
    class ActivationFunction*   m_activationFunction    = nullptr;
};

