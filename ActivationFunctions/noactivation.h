#include "ActivationFunctions/activationfunction.h"

class NoActivation : public ActivationFunction {
public:
    NoActivation(class System* system);
    double evaluate(double input) { return input; }
};

