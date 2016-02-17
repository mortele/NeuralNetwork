#pragma once
#include "LearningAlgorithms/learningalgorithm.h"

class SupervisedErrorCorrection : public LearningAlgorithm {
public:
    SupervisedErrorCorrection();
    SupervisedErrorCorrection(double rho);
    void learn(int numberOfExamples);
    void learn(int numberOfExamples, bool testing);
    void runTests(int numberOfExamples);

private:
    double m_rho = 0;
};
