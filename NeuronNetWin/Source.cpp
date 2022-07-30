#include "pch.h"
#include "Defs.h"
#include <stdio.h>

extern "C" int MainBuild();
extern "C" void fprintStructure(void);
extern "C" void printStructureReverse(struct neuronNode*);
extern "C" int WeightRoute(int);
extern "C" struct neuronNode* LoadBuild(void);
extern "C" int SaveBuild(void);
extern "C" int MainLoad();
extern "C" void FireNeuronThrd(void);
extern "C" struct neuronNode* findNeuron(int);
extern "C" float calculatePulse(struct neuronNode*);
extern "C" void SweepNet(void);
extern "C" void SweepIO(void);
extern "C" int PropagateFire(unsigned int);
extern "C" void ClearScreen(void);            // Screen clear
extern "C" void ShutDown(void);               // Program shutdown
extern "C" void WriteTitle(int);
extern "C" int instantiateOutboundNeuron(int);
extern "C" int instantiateFireNeurons(int);
extern "C" struct neuronNode* deleteNeuron();
extern "C" bool isEmpty();
extern "C" int initializeinboundNeuron(int);
extern "C" int connectinboundNeuron(int);
extern "C" void fprintStructure(void);
extern "C" float calculatePulse(struct neuronNode*);
extern "C" void scanoutput(void);
extern "C" void strengthenNeuron(int);
extern "C" void weakenNeuron(int);
extern "C" int createConnection(int);
extern "C" float SigmoidCall(int);
extern "C" void saveOutputarray(void);
extern "C" void loadOutputarray(void);
extern "C" void resetOutputs(void);
extern "C" int reverseFileLines(const char*, const char*);