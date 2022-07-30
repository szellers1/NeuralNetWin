#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>
#include "Defs.h"

extern int instantiateOutboundNeuron(int);
extern int instantiateFireNeurons(int);
extern struct neuronNode* findNeuron(int);
extern struct neuronNode* deleteNeuron();
extern int initializeinboundNeuron(int);
extern int connectinboundNeuron(int);
extern float calculatePulse(struct neuronNode*);
extern void fprintStructure(void);
extern void printStructure(void);
extern int SaveBuild(void);
extern struct neuronNode* LoadBuild(void);
extern void SweepNet(void);

extern struct neuronNode* head;
extern struct neuronNode* current; 
extern struct neuronNode* link;
extern struct neuronNode* tail;
extern struct neuronNode* top;

extern int inputArray[];
bool mainBLD = true;

int MainBuild() {

	int i, j, k;
	int offSet = BRAIN_SIZE - OUTPUT_NEURONS;
	float pulse;
	unsigned int seed = 24;
	HANDLE  hConsoleOut;

	
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//Set Console font color
	SetConsoleTextAttribute(hConsoleOut, 14);
	if (!mainBLD) {
		return(0);
	}

	printf("Building Firing neurons\n");
//	srand((unsigned)seed); //A better method to make it truly random
	srand(time(NULL));
	for (i = 1; i <= INPUT_NEURONS; i++) {
		instantiateFireNeurons(i);
	}

	printf("Building Outbound neurons\n");
	//Seed the random number generator
	srand(time(NULL)); //A better method to make it truly random
	for (i = INPUT_NEURONS+1; i <= BRAIN_SIZE; i++) {
		instantiateOutboundNeuron(i);
	}

	top = head;

	printf("Begin initializing inbound Neurons\n");
	for (i = INPUT_NEURONS+1; i <= BRAIN_SIZE; i++) {
		initializeinboundNeuron(i);
	}
	printf("Done initializing inbound Neurons\n");

	//Order N2 procedure follows
	printf("Begin connecting inbound neurons\n");
	for (i = INPUT_NEURONS+1; i <= BRAIN_SIZE; i++) {
		connectinboundNeuron(i);
	}

	printf("Begin revising Electric pulses\n");
	struct neuronNode* neuron = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));
	for (i = INPUT_NEURONS+1; i <= offSet; i++) {
		neuron = findNeuron(i);
		if (neuron != NULL) {
			pulse = calculatePulse(neuron);
			neuron->electricPulse = pulse;
		}
	}
	printf("Resetting Input Registers\n");
	for (i = 1; i <= INPUT_NEURONS; i++) {
		inputArray[i] = 0;
	}

	//Switch all body and output neurons firing off
	printf("Sweeping the Network to Disable All Fire...\n");
	SweepNet();

	printStructure();

	return(0);
}