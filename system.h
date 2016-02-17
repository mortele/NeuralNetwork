#pragma once
#include <vector>
#include <iostream>
#include <iomanip>


class System {
public:
    System();
    System(int seed);
    void printNetwork();
    void learn(int numberOfExamples);
    void runTests(int numberOfExamples);
    void setNetwork(class Network* network);
    void setLearningAlgorithm(class LearningAlgorithm* learningAlgorithm);
    void setErrorFunction(class ErrorFunction* errorFunction);
    void setExampleGenerator(class ExampleGenerator* exampleGenerator);
    std::vector<double> compute(std::vector<double> input);

private:
    int                         m_seed              = 1;
    class ErrorFunction*        m_errorFunction     = nullptr;
    class Network*              m_network           = nullptr;
    class LearningAlgorithm*    m_learningAlgorithm = nullptr;
    class ExampleGenerator*     m_exampleGenerator  = nullptr;
};

