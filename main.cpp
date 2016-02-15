#include <iostream>
#include <vector>
#include "system.h"
#include "vectorlookup.h"

using namespace std;

int main() {
    int hiddenLayers        = 3;
    int neuronsInEachLayer  = 5;
    int inputs              = 2;
    int outputs             = 1;

    vector<double> input    = {1,0};
    vector<double> output   = {0};

    System* system = new System(hiddenLayers,neuronsInEachLayer,inputs,outputs);
    output = system->compute(input);
    cout << at(output, 0) << endl;
    return 0;
}
