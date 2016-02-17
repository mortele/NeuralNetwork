#include "learningalgorithm.h"
#include "../Networks/network.h"

void LearningAlgorithm::setNetwork(Network* network) {
    m_network = network;
}

void LearningAlgorithm::setErrorFunction(ErrorFunction* errorFunction) {
    m_errorFunction = errorFunction;
}

void LearningAlgorithm::setExampleGenerator(ExampleGenerator* exampleGenerator) {
    m_exampleGenerator = exampleGenerator;
}

