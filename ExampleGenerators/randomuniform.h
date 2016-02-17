#pragma once
#include "ExampleGenerators/examplegenerator.h"
#include <vector>

class RandomUniform : public ExampleGenerator {
public:
    RandomUniform();
    RandomUniform(int inputs, double lowerLimit, double upperLimit);

    std::vector<double> generateExample();

private:
    double m_lowerLimit = 0;
    double m_upperLimit = 0;
};

