#include "singleperceptron.h"
#include <vector>
#include "../system.h"
#include "../neuron.h"
#include "../ActivationFunctions/perceptron.h"

using std::vector;

SinglePerceptron::SinglePerceptron(System* system) :
    Network(system, 2, 1, 0, 0) {

    for (int i=0; i<m_layers.size(); i++) {
        for (int j=0; j<at(m_layers, i).size(); j++) {
            at(at(m_layers, i), j)->setActivationFunction(
                        new Perceptron(m_system));
        }
    }
}

vector<double> SinglePerceptron::evaluate(vector<double> input) {

}

