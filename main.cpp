#include <iostream>
#include "system.h"

using namespace std;

int main() {

    int hiddenLayers        = 3;
    int neuronsInEachLayer  = 5;
    int inputs              = 2;
    int outputs             = 1;

    System* system = new System(hiddenLayers,neuronsInEachLayer,inputs,outputs);

    return 0;
}
