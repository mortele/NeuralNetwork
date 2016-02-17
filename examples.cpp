#include "examples.h"
#include <iostream>
#include <vector>
#include "system.h"
#include "Networks/network.h"
#include "Networks/singleperceptron.h"

using std::vector;
using std::cout;
using std::endl;


int Examples::singlePerceptron() {
    System* system = new System(10);
    system->setNetwork(new SinglePerceptron(system));
    vector<double> output = system->compute(vector<double>{1,2});
    system->printNetwork();
    return 0;
}
