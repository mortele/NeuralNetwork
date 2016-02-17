#include "system.h"
#include "RandomNumberGenerator/random.h"
#include "neuron.h"
#include "vectorlookup.h"
#include "Networks/network.h"
#include "LearningAlgorithms/learningalgorithm.h"

using std::vector;
using std::endl;
using std::cout;
using std::setw;
using std::setprecision;


System::System() :
        System(m_seed) {
}

System::System(int seed) {
    m_seed = seed;
    Random::seed(m_seed);
}

void System::printNetwork() {
    m_network->printNetwork();
}

void System::learn(int numberOfExamples) {
    m_learningAlgorithm->learn(numberOfExamples);
}

void System::runTests(int numberOfExamples) {
}

void System::setNetwork(Network* network) {
    m_network = network;
}

void System::setLearningAlgorithm(LearningAlgorithm* learningAlgorithm) {
    m_learningAlgorithm = learningAlgorithm;
    m_learningAlgorithm->setNetwork(m_network);
}

void System::setErrorFunction(ErrorFunction* errorFunction) {
    m_errorFunction = errorFunction;
    m_learningAlgorithm->setErrorFunction(errorFunction);
}

void System::setExampleGenerator(ExampleGenerator* exampleGenerator){
    m_exampleGenerator = exampleGenerator;
    m_learningAlgorithm->setExampleGenerator(exampleGenerator);
}

std::vector<double> System::compute(std::vector<double> input) {
    return m_network->evaluate(input);
}



