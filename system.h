#pragma once
#include <vector>
#include <iostream>


class System {
public:
    System(int, int, int, int);
    void setupLayers();
    void randomizeAllWeights();
    void clearNeurons();
    void propagateLayer(int index);
    void setInput(std::vector<double> input);
    std::vector<double> computeOutput();
    std::vector<double> compute(std::vector<double> input);

private:
    int m_seed                  = 1;
    int m_hiddenLayers          = 0;
    int m_neuronsInEachLayer    = 0;
    int m_inputs                = 0;
    int m_outputs               = 0;
    std::vector<double> m_output;
    std::vector<std::vector<class Neuron*>> m_layers;
};

