#pragma once
#include <vector>

class ExampleGenerator {
public:
    ExampleGenerator(int inputs);
    virtual std::vector<double> generateExample() = 0;

protected:
    int m_inputs = 0;
};

