#include "examples.h"
#include <iostream>
#include <vector>
#include "system.h"
#include "Networks/network.h"
#include "Networks/singleperceptron.h"
#include "LearningAlgorithms/learningalgorithm.h"
#include "LearningAlgorithms/supervisederrorcorrection.h"
#include "ErrorFunctions/errorfunction.h"
#include "ErrorFunctions/stepfunction.h"
#include "ExampleGenerators/examplegenerator.h"
#include "ExampleGenerators/randomuniform.h"
#include "RandomNumberGenerator/random.h"

using std::vector;
using std::cout;
using std::endl;


int Examples::singlePerceptron() {
    int numberOfInputs = 1;

    System* system = new System(1);
    system->setNetwork(new SinglePerceptron(system, numberOfInputs));
    system->setLearningAlgorithm(new SupervisedErrorCorrection());
    system->setErrorFunction(new StepFunction());
    system->setExampleGenerator(new RandomUniform(numberOfInputs,-1,1));
    system->compute(Random::nextDoubleVector(numberOfInputs, -1, 1));
    system->printNetwork();
    system->runTests((int) 1e3);
    system->learn((int) 1e3);
    system->runTests((int) 1e3);
    system->compute(Random::nextDoubleVector(numberOfInputs, -1, 1));
    system->printNetwork();
    return 0;
}


