#include "examples.h"
#include "system.h"
#include "Networks/network.h"
#include "Networks/singleperceptron.h"

int Examples::singlePerceptron() {
//    int hiddenLayers        = 1;
//    int neuronsInEachLayer  = 2;
//    int inputs              = 1;
//    int outputs             = 1;
//    vector<double> input    = {0.5};

    System* system = new System();
    system->setNetwork(new SinglePerceptron(system));
    return 0;
}
