TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS_RELEASE  -= -O2
QMAKE_CXXFLAGS_RELEASE  += -O3 -xHost -fno-alias -ansi-alias -restrict -override-limits -vec-report2

SOURCES += \
    main.cpp \
    neuron.cpp \
    system.cpp \
    Networks/network.cpp \
    examples.cpp \
    Networks/singleperceptron.cpp \
    ActivationFunctions/activationfunction.cpp \
    ActivationFunctions/noactivation.cpp \
    ActivationFunctions/perceptron.cpp \
    LearningAlgorithms/learningalgorithm.cpp \
    LearningAlgorithms/supervisederrorcorrection.cpp \
    ErrorFunctions/errorfunction.cpp \
    ErrorFunctions/stepfunction.cpp \
    ExampleGenerators/examplegenerator.cpp \
    ExampleGenerators/randomuniform.cpp

INCLUDEPATH += /usr/local/Cellar/armadillo/6.200.4/include
LIBS += -lblas -llapack

HEADERS += \
    neuron.h \
    vectorlookup.h \
    system.h \
    RandomNumberGenerator/random.h \
    Networks/network.h \
    examples.h \
    Networks/singleperceptron.h \
    ActivationFunctions/activationfunction.h \
    ActivationFunctions/noactivation.h \
    ActivationFunctions/perceptron.h \
    LearningAlgorithms/learningalgorithm.h \
    LearningAlgorithms/supervisederrorcorrection.h \
    ErrorFunctions/errorfunction.h \
    ErrorFunctions/stepfunction.h \
    ExampleGenerators/examplegenerator.h \
    ExampleGenerators/randomuniform.h
