#include "singleperceptron.h"
#include <vector>
#include "../system.h"

using std::vector;

SinglePerceptron::SinglePerceptron(System* system) :
    Network(system, 2, 1, 0, 0) {
}

vector<double> SinglePerceptron::evaluate(vector<double> input) {
    return vector<double>{1};
}

