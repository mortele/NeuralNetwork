#pragma once
#include "ActivationFunctions/activationfunction.h"

class Perceptron : public ActivationFunction {
public:
    Perceptron(class System* system);
    double evaluate(double input) { return ((input+m_bias)>0 ? 1 : -1); }
};

