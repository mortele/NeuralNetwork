#pragma once
#include "Networks/network.h"

class SinglePerceptron : public Network {
public:
    using Network::evaluate;

    SinglePerceptron(class System* system);
};

