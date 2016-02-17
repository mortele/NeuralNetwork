#pragma once

class LearningAlgorithm {
public:
    virtual void learn(int numberOfExamples) = 0;
    virtual void runTests(int numberOfExamples) = 0;
    void setNetwork(class Network* network);
    void setErrorFunction(class ErrorFunction* errorFunction);
    void setExampleGenerator(class ExampleGenerator* exampleGenerator);

protected:
    class Network*          m_network           = nullptr;
    class ExampleGenerator* m_exampleGenerator  = nullptr;
    class ErrorFunction*    m_errorFunction     = nullptr; // Used for error correction methods.
    class CostFunction*     m_costFunction      = nullptr; // Used for gradient descent methods.
};

