#include "singleperceptron.h"
#include <vector>
#include "system.h"
#include "neuron.h"
#include "ActivationFunctions/perceptron.h"
#include "ActivationFunctions/noactivation.h"

using std::vector;

SinglePerceptron::SinglePerceptron(System* system) :
        SinglePerceptron(system, 2) {
}

SinglePerceptron::SinglePerceptron(System* system, int numberOfInputs) :
    Network(system, numberOfInputs, 1, 0, 0) {

    for (int i=0; i<m_layers.size(); i++) {
        for (int j=0; j<at(m_layers, i).size(); j++) {
            if (i==0) {
                at(at(m_layers, i), j)->setActivationFunction(
                            new NoActivation(m_system));
            } else {
                at(at(m_layers, i), j)->setActivationFunction(
                            new Perceptron(m_system));
            }
        }
    }
}


