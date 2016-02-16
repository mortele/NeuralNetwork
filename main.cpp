#include <iostream>
#include <vector>
#include "system.h"
#include "vectorlookup.h"
#include "Networks/network.h"
#include "examples.h"

using namespace std;

int main() {
    int r = Examples::singlePerceptron();

    cout << r << endl;
    return r;
}
