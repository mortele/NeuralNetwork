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

using std::vector;
using std::cout;
using std::endl;


int Examples::singlePerceptron() {
    System* system = new System(10);
    system->setNetwork(new SinglePerceptron(system));
    system->setLearningAlgorithm(new SupervisedErrorCorrection());
    system->setErrorFunction(new StepFunction());
    system->setExampleGenerator(new RandomUniform(2,-1,1));
    system->compute(std::vector<double>{-1.0, 1.5});
    system->printNetwork();
    system->runTests((int) 1e3);
    system->learn((int) 1e4);
    system->runTests((int) 1e3);
    return 0;
}


