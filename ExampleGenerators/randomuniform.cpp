#include "randomuniform.h"
#include "RandomNumberGenerator/random.h"

RandomUniform::RandomUniform() :
        RandomUniform(1, 0, 1) {
}


RandomUniform::RandomUniform(int inputs, double lowerLimit, double upperLimit) :
        ExampleGenerator(inputs) {
    m_lowerLimit = lowerLimit;
    m_upperLimit = upperLimit;
}

std::vector<double> RandomUniform::generateExample() {
    std::vector<double> example;
    example.reserve(m_inputs);
    for (int i=0; i<m_inputs; i++) {
        example.push_back(Random::nextDouble(m_lowerLimit, m_upperLimit));
    }
    return example;
}
