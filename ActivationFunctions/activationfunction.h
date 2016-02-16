#pragma once

class ActivationFunction {
public:
    ActivationFunction(class System* system);
    virtual double evaluate(double input) = 0;

protected:
    double          m_bias      = 0;
    class System*   m_system    = nullptr;
};

