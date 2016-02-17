#pragma once
#include <vector>

class ErrorFunction {
public:
    virtual std::vector<double> computeError(std::vector<double> networkOutput) = 0;
};
