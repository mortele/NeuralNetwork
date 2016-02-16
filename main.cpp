#include <iostream>
#include <vector>
#include "system.h"
#include "vectorlookup.h"

using namespace std;

int main() {
    int hiddenLayers        = 1;
    int neuronsInEachLayer  = 2;
    int inputs              = 1;
    int outputs             = 1;

    vector<double> input    = {0.5};

    System* system = new System(hiddenLayers,neuronsInEachLayer,inputs,outputs);
    system->compute(input);
    system->printNetwork();
    return 0;
}
