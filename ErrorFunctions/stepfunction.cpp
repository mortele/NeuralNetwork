#include "stepfunction.h"
#include "../vectorlookup.h"

using std::vector;

StepFunction::StepFunction() :
        StepFunction(0) {
}


StepFunction::StepFunction(double cut) {
    m_cut = cut;
}

vector<double> StepFunction::computeError(vector<double> networkOutput) {
    double outputSum = 0;
    for (int i=0; i<networkOutput.size(); i++) {
        outputSum += at(networkOutput, i);
    }
    return vector<double>{(outputSum > m_cut ? 1.0 : -1.0)};
}
