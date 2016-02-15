TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS_RELEASE  -= -O2
QMAKE_CXXFLAGS_RELEASE  += -O3 -xHost -fno-alias -ansi-alias -restrict -override-limits -vec-report2

SOURCES += \
    main.cpp \
    neuron.cpp \
    system.cpp

INCLUDEPATH += /usr/local/Cellar/armadillo/6.200.4/include
LIBS += -lblas -llapack

HEADERS += \
    neuron.h \
    vectorlookup.h \
    system.h \
    RandomNumberGenerator/random.h
