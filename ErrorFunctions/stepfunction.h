#pragma once
#include "ErrorFunctions/errorfunction.h"
#include <vector>

class StepFunction : public ErrorFunction {
public:
    StepFunction();
    StepFunction(double x);

    std::vector<double> computeError(std::vector<double> networkOutput);

private:
    double m_cut = 0;
};

