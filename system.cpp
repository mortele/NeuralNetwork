#include "system.h"
#include "RandomNumberGenerator/random.h"
#include "neuron.h"
#include "vectorlookup.h"
#include "Networks/network.h"

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

void System::setNetwork(Network* network) {
    m_network = network;
}

void System::setLearningAlgorithm(LearningAlgorithm* learningAlgorithm) {
    m_learningAlgorithm = learningAlgorithm;
}

std::vector<double> System::compute(std::vector<double> input) {
    return m_network->evaluate(input);
}



