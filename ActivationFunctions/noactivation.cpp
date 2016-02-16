#include "noactivation.h"
#include "../system.h"

NoActivation::NoActivation(System* system) :
        ActivationFunction(system) {
    m_bias = 0;
}

