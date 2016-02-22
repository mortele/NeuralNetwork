#include "neuron.h"
#include <cmath>
#include "vectorlookup.h"
#include "system.h"
#include "RandomNumberGenerator/random.h"
#include "ActivationFunctions/activationfunction.h"

using std::exp;

Neuron::Neuron(System* system) {
    m_system = system;
}

void Neuron::addInput(double input) {
    m_totalInput += input;
}

void Neuron::computeTransferFunction() {
    m_output = m_activationFunction->evaluate(m_totalInput);
}

void Neuron::clearNeuron() {
    m_totalInput = 0;
    m_output = 0;
}

void Neuron::setActivationFunction(ActivationFunction* activationFunction) {
    m_activationFunction = activationFunction;
}

