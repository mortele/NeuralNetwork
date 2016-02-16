#pragma once
#include "Networks/network.h"

class SinglePerceptron : public Network {
public:
    SinglePerceptron(class System*);
    std::vector<double> evaluate(std::vector<double> input);

};

