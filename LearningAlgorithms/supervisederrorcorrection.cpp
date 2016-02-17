#include "supervisederrorcorrection.h"
#include <iostream>
#include "neuron.h"
#include "Networks/network.h"
#include "ExampleGenerators/examplegenerator.h"
#include "ErrorFunctions/errorfunction.h"
#include "vectorlookup.h"

using std::cout;
using std::endl;

SupervisedErrorCorrection::SupervisedErrorCorrection() :
        SupervisedErrorCorrection(0.1) {
}

SupervisedErrorCorrection::SupervisedErrorCorrection(double rho) {
    m_rho = rho;
}

void SupervisedErrorCorrection::learn(int numberOfExamples) {

    std::vector<double> example;
    std::vector<double> networkOutput;
    std::vector<double> expectedOutput;

    for (int i=0; i<numberOfExamples; i++) {
        example = m_exampleGenerator->generateExample();
        networkOutput = m_network->evaluate(example);
        expectedOutput = m_errorFunction->computeError(example);


        for (int j=0; j<m_network->getNumberOfInputs(); j++) {
            Neuron* neuron = at(m_network->getLayer(0), j);
            neuron->adjustWeight(m_rho * (at(expectedOutput, 0) - at(networkOutput, 0)) * at(example, j), 0);
        }
    }
}
