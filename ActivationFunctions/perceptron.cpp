#include "perceptron.h"
#include "../system.h"

Perceptron::Perceptron(System* system) :
        ActivationFunction(system) {
    m_bias = 0;
}


