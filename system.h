#pragma once
#include <vector>
#include <iostream>
#include <iomanip>


class System {
public:
    System();
    System(int seed);
    void printNetwork();
    void setNetwork(class Network* network);
    void setLearningAlgorithm(class LearningAlgorithm* learningAlgorithm);
    std::vector<double> compute(std::vector<double> input);

private:
    int                         m_seed              = 1;
    class Network*              m_network           = nullptr;
    class LearningAlgorithm*    m_learningAlgorithm = nullptr;
};

