#pragma once
#include "Networks/network.h"

class SinglePerceptron : public Network {
public:
    SinglePerceptron(class System* system);
    SinglePerceptron(class System* system, int numberOfInputs);
};

