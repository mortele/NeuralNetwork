#include "supervisederrorcorrection.h"
#include <iostream>
#include <cmath>
#include "neuron.h"
#include "Networks/network.h"
#include "ExampleGenerators/examplegenerator.h"
#include "ErrorFunctions/errorfunction.h"
#include "vectorlookup.h"

using std::cout;
using std::endl;

SupervisedErrorCorrection::SupervisedErrorCorrection() :
    SupervisedErrorCorrection(0.5) {
}

SupervisedErrorCorrection::SupervisedErrorCorrection(double rho) {
    m_rho = rho;
}

void SupervisedErrorCorrection::learn(int numberOfExamples) {
    learn(numberOfExamples, false);
}

void SupervisedErrorCorrection::learn(int numberOfExamples, bool testing) {
    std::vector<double> example;
    std::vector<double> networkOutput;
    std::vector<double> expectedOutput;

    if (testing) {
        cout << "--Running tests: # 1e+" << std::log10(numberOfExamples) << endl;
    } else {
        cout << "--Training network: # 1e+" << std::log10(numberOfExamples) << endl;
    }
    double correctClassified = 0;

    for (int i=0; i<numberOfExamples; i++) {
        example = m_exampleGenerator->generateExample();
        networkOutput = m_network->evaluate(example);
        expectedOutput = m_errorFunction->computeError(example);


        if (testing) {
            correctClassified += at(networkOutput,0)==at(expectedOutput,0);
        } else {
            for (int j=0; j<m_network->getNumberOfInputs(); j++) {
                Neuron* neuron = at(m_network->getLayer(0), j);
                neuron->adjustWeight(m_rho * (at(expectedOutput, 0) - at(networkOutput, 0)) * at(example, j), 0);
            }
        }
    }
    if (testing) {
        cout << "Testing complete. Accuracy: " << 100.0*correctClassified / ((double) numberOfExamples) << endl;
    } else {
        cout << "Training complete." << endl;
    }
    cout << endl;
}

void SupervisedErrorCorrection::runTests(int numberOfExamples) {
    learn(numberOfExamples, true);
}
