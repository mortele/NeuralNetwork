#pragma once
#include <vector>
#include <iostream>



class System {
public:
    System(int numberOfLayers, int neuronsInEachLayer, int numberOfInputs, int numberOfOutputs);

private:
    int m_hiddenLayers          = 0;
    int m_neuronsInEachLayer    = 0;
    int m_inputs                = 0;
    int m_outputs               = 0;
    std::vector<std::vector<class Neuron*>> m_layers;
};

