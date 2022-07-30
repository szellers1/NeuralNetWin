#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <ios>
#include <cstdlib>
#include <algorithm>
#include "windows.h"
#include <errno.h>
#include <sys/stat.h>
#include "Defs.h"
#define MAX_LINES 50
#define BUFFSIZE 1024

//Steve's NeuronNet Configurator Simulator
//Support Functions
//@2022 Veridical, LLC

void fprintStructure(void);
void printStructure(void);
void printStructureReverse(struct neuronNode*);
int instantiateOutboundNeuron(int);
int instantiateFireNeurons(int);
struct neuronNode* findNeuron(int);
struct neuronNode* deleteNeuron();
bool isEmpty(void);
int initializeinboundNeuron(int);
int connectinboundNeuron(int);
float calculatePulse(struct neuronNode*);
void strengthenNeuron(int);
void weakenNeuron(int);
void fprintStructure(void);
void SweepNet(void);
void SweepIO(void);
int SaveBuild(void);
struct neuronNode* LoadBuild(void);
int createConnection(int);
float SigmoidCall(int);
void saveOutputarray(void);
void loadOutputarray(void);
int reverseFileLines(const char*, const char*);

//Steve's Neural Net Core Class Functions

struct NeuralNetwork* brain = NULL;
struct neuronNode* top = NULL;
struct neuronNode* head = NULL;
struct neuronNode* found = NULL;
struct neuronNode* link = NULL;
struct neuronNode* tail = NULL;
struct neuronNode* node = NULL;
struct neuronNode* current = NULL;

extern int inputArray[];
extern int outboundArray[];
extern int numIterations;
extern int traceroute_count;
extern bool mainLD;

/* Print all the elements in the linked list */
void fprintStructure(void) {
	FILE* fp = fopen("BrainBuild.txt", "w");

	struct neuronNode* current_node = top;
	printf("Printing neuronNet Structures\n");
	do {
		fprintf(fp,"Key = %d ", current_node->key);
		fprintf(fp,"Fire pulse = %.1f ", current_node->electricPulse);
		fprintf(fp,"Fire threshold = %.1f ", current_node->fireThreshold);
		fprintf(fp,"Fire impedance = %.1f ", current_node->impedance);
		fprintf(fp,"Fire status = %d ", current_node->fire);
		fprintf(fp,"Next neuron = %d\n", current_node->next->key);
		current_node = current_node->next;
	} while (current_node->key > 0);
}

void printStructure(void) {

	struct neuronNode* current_node = top;
	printf("Printing neuronNet Structures\n");
	do {
		printf("Key = %d ", current_node->key);
		printf("Fire pulse = %.1f ", current_node->electricPulse);
		printf("Fire threshold = %.1f ", current_node->fireThreshold);
		printf("Fire impedance = %.1f ", current_node->impedance);
		printf("Fire status = %d ", current_node->fire);
		printf("Next neuron = %d\n", current_node->next->key);
		current_node = current_node->next;
	} while (current_node->key > 1);
}

/* Print all the elements in the linked list */
void printStructureReverse(struct neuronNode* revstruct) {
	struct neuronNode* current_node = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));

	current_node = revstruct;
	printf("Printing reverse neuronNet structures\n");
	do {
		printf("Key = %d ", current_node->key);
		printf("Fire pulse = %.1f ", current_node->electricPulse);
		printf("Fire threshold = %.1f ", current_node->fireThreshold);
		printf("Fire impedance = %.1f ", current_node->impedance);
		printf("Fire status = %d ", current_node->fire);
		if (current_node->key >= 1) {
			printf("Next neuron = %d\n", current_node->next->key);
			return;
		}
		else {
			printf("Next neuron = %d\n", 0);
		}
		current_node = current_node->next;
		head = current_node;
	} while (current_node->key > 0);
}

int instantiateFireNeurons(int neuron) {
	int i, j;
	node = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));

	node->key = neuron;
	node->electricPulse = 1.0;
	node->fireThreshold = 0;
	node->impedance = 1.0;
	node->fire = false;
	//Set inbound connections to zero
	for (i = 0; i < FIRE_CONNECTIONS; i++) {
		node->FireConnections[i].inboundNeuron = -1;
		node->FireConnections[i].outboundNeuron = (int)(rand() % (BRAIN_SIZE - OUTPUT_NEURONS - INPUT_NEURONS)) + INPUT_NEURONS + 1;
	}
node->next = head;
head = node;
return 0;
}

int instantiateOutboundNeuron(int neuron) {

	node = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));
	int i, j;
	int outbound;
	//set random seed to same repeatable value
	unsigned int seed = 25;
	
	int pulse1, sigmoidrand1;
	float pulse2, sigmoidrand2;
	int rc;
	int offset = BRAIN_SIZE - OUTPUT_NEURONS;

	node->key = neuron;
	node->fire = false;
	//create link in list

	if ((neuron >= INPUT_NEURONS) && (neuron < offset)) {
		//Sigmoindal domain must be between -50 and 50
		sigmoidrand1 = (int)(rand() % (10 * DENDRITE_STRENGTH_LEVELS)) - 50;
		if (sigmoidrand1 != 0) {
			sigmoidrand2 = (float)SigmoidCall(sigmoidrand1);
		}
		else {
			sigmoidrand2 = 0;
		}
		node->fireThreshold = sigmoidrand2;
		//These steps should be taken to get the random number generator to work
		pulse1 = (int)(rand() % DENDRITE_STRENGTH_LEVELS) + 1;
		pulse2 = (float)pulse1 / DENDRITE_STRENGTH_LEVELS;
		node->electricPulse = pulse2;
//		if (node->electricPulse >= node->fireThreshold) {
//			node->fire = true;
//		}
		node->impedance = 1.0;
		//shut off all Neuron firing
		node->fire == false;
		//This logic creates the outbound neurons
		for (i = 0; i < OUTBOUND_CONNECTIONS; i++) {
			node->OutboundConnections[i].outboundNeuron = (int)(rand() % (BRAIN_SIZE - INPUT_NEURONS)) + INPUT_NEURONS + 1;
//			printf("Neuron = %d Pulse = %.2f Threshold = %.2f Connection = %d Outbound =%d\n",
//				node->key, node->electricPulse, node->fireThreshold, i, node->OutboundConnections[i].outboundNeuron);
		}
	}
	else { // in OUTPUT_NEURONS
		node->key = neuron;
		node->fireThreshold = 0.0;
		node->electricPulse = 1.0;
		node->impedance = 1.0;
		node->fire = false;
	}
	node->next = head;
	head = node;
return(0);
}


struct neuronNode* findNeuron(int key) {

	//start from the first link
	
	struct neuronNode *curr = top;

	//if list is empty
	if (curr == NULL) {
		return NULL;
	}
	
	//navigate through list
	while (curr->key != key) {
		//if it is the last node
//		printf("current->key =%d\n", current->key);
		if (curr->next == NULL) {
			return NULL;
		}
		else {
			//go to the next link
			curr = curr->next;
		}
	}
	//if data found, return the current link

	return curr;
}

//struct neuronNode* findNeuron(int key) {
//	
//	//start from the first link
//	 struct neuronNode* current = head;
//	
//	//current = head;
//
//	//if list is empty
//	if (head == NULL) {
//		return NULL;
//	}
//	//navigate through list
//	while (current->key != key) {
//		//if it is the last node
//		if (current->next == NULL) {
//			return NULL;
//		}
//		else {
//			//go to the next link
//			current = current->next;
//		}
//	}
//	//if data found, return the currrent link
//
//	return current;
//}

//delete first neuron
struct neuronNode* deleteNeuron() {
	//save reference to first link
	struct neuronNode* templink = head;
	//mark next to first link as first
	head = head->next;
	//return the deleted link
	return templink;
}

//is list empty
bool isEmpty() {
	return head == NULL;
}

//int length() {
//	int length = 0;
//	struct Neuronptr current;

//	for (current = head; current != NULL; current = current->next) {
//		length++;
//	}

//	return(length);
//}

int initializeinboundNeuron(int key) {
	//start from the first link
	int i;
	struct neuronNode* node = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));
	//Find the neuron
	
	node = findNeuron(key);
	if (node != NULL) {
		for (i = 0; i < INBOUND_CONNECTIONS; i++) {
			node->InboundConnections[i].inboundNeuron = -1;
		}
	}
	return 1;
}

//connect the inbound Neurons
int connectinboundNeuron(int neuron) {

	int i, j, k, l;
	float pulse;
	struct neuronNode* found = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));
	struct neuronNode* tfound = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));
	int offset = BRAIN_SIZE - OUTPUT_NEURONS;

	//Now find the current 

	found = findNeuron(neuron);
	k = 0;
	for (i = INPUT_NEURONS + 1; i <= BRAIN_SIZE; i++) {
		tfound = findNeuron(i);
		if (tfound != NULL) {
			if (found->key != tfound->key) {
				for (j = 0; j < OUTBOUND_CONNECTIONS; j++) {
					if (k < INBOUND_CONNECTIONS) {
						if (tfound->OutboundConnections[j].outboundNeuron == found->key) {
							found->InboundConnections[k].inboundNeuron = tfound->key;
							k++;
						}
					}
				}
			}
		}
	}
//	free(tfound);
//	free(found);
	return(0);
}

float calculatePulse(struct neuronNode* node) {

	int i, j, k;

	struct neuronNode* current_node = node;
	struct neuronNode* temp = NULL;
	Connection stem[INBOUND_CONNECTIONS];
	int inbound;
	float pulse;
	float numerator;
	float result;

	pulse = 0;
	result = 0;
	numerator = 0;

	current_node = node;
	for (i = 0; i < INBOUND_CONNECTIONS; i++) {
		if (current_node != NULL) {
			temp = findNeuron(current_node->InboundConnections[i].inboundNeuron);
		}
		if ( temp != NULL) 
		{ 
			numerator = temp->electricPulse;
			pulse = pulse + numerator;
		} else {
			numerator = (rand() % DENDRITE_STRENGTH_LEVELS);
			pulse = pulse + (float)(numerator / DENDRITE_STRENGTH_LEVELS);
		}
	}
	result = (float)(pulse / INBOUND_CONNECTIONS);
	return(result);
}

//Switch off all neurons and let them be switched at run time
void SweepNet(void) {
	int offSet = BRAIN_SIZE - OUTPUT_NEURONS;
	int i;
	struct neuronNode* find = NULL;
	for (i = 1; i <= (BRAIN_SIZE - OUTPUT_NEURONS); i++) {
		find = findNeuron(i);
		if (find != NULL) {
			findNeuron(i)->fire = false;
		}
	}
}

void SweepIO(void) {

	int i;
	int offSet;
	
	offSet = BRAIN_SIZE - OUTPUT_NEURONS;
	struct neuronNode* find = NULL;
	//for (i = 1; i < INPUT_NEURONS; i++) {
	//	find = findNeuron(i);
	//	if (find != NULL) {
	//		find->fire = false;
	//	}
	//}
	for (i = offSet+1; i <= BRAIN_SIZE; i++) {
		find = findNeuron(i);
		if (find != NULL) {
			findNeuron(i)->fire = false;
		}
	}
}

int SaveBuild(void) {

	int i, j;
	int offset = BRAIN_SIZE - OUTPUT_NEURONS;
	struct neuronNode* ptr = head;
	FILE* fp;

fp = fopen("BrainBuild.txt", "w");

printf("Saving neuronNet Build\n");
while (ptr->key >= 2) {
	fprintf(fp, "%d ", ptr->key);
	fprintf(fp, "%.1f ", ptr->electricPulse);
	fprintf(fp, "%.1f ", ptr->fireThreshold);
	fprintf(fp, "%.1f ", ptr->impedance);
	fprintf(fp, "%d ", ptr->fire);
	fprintf(fp, "%d", ptr->next->key);
	fprintf(fp, "\n");

	if (ptr->key <= INPUT_NEURONS) {
		for (i = 0; i < INBOUND_CONNECTIONS; i++) {
			fprintf(fp, "0 ");
		}
		fprintf(fp, "\n");
		for (j = 0; j < FIRE_CONNECTIONS; j++) {
			fprintf(fp, "%d ", ptr->FireConnections[j].outboundNeuron);
		}
		fprintf(fp, "\n");
	}
	else if ((ptr->key >= INPUT_NEURONS+1) && (ptr->key <= offset)) {
		for (i = 0; i < INBOUND_CONNECTIONS; i++) {
			fprintf(fp, "%d ", ptr->InboundConnections[i].inboundNeuron);
		}
		fprintf(fp, "\n");
		for (j = 0; j < OUTBOUND_CONNECTIONS; j++) {
			fprintf(fp, "%d ", ptr->OutboundConnections[j].outboundNeuron);
		}
		fprintf(fp, "\n");
	}
	else if (ptr->key >= offset+1) {
		for (i = 0; i < INBOUND_CONNECTIONS; i++) {
			fprintf(fp, "%d ", ptr->InboundConnections[i].inboundNeuron);
		}
		fprintf(fp, "\n");
		for (j = 0; j < OUTBOUND_CONNECTIONS; j++) {
			fprintf(fp, "0 ");
		}
		fprintf(fp, "\n");
	}
	ptr = ptr->next;
}
fclose(fp);
return(0);
}

struct neuronNode* LoadBuild(void) {
	int i, j;

	int linkey;
	int offset = BRAIN_SIZE - OUTPUT_NEURONS;
	int firsttime = true;
	char buff[BRAIN_SIZE];
	char tbuff[BRAIN_SIZE];
	char* str;
	const char* delimiter = " \n\t";
	struct neuronNode* link = NULL;
	struct neuronNode* position = NULL;
	char* string[BRAIN_SIZE];
	FILE* pLoad;
	head = NULL;

	HANDLE  hConsoleOut;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//Set Console font color
	SetConsoleTextAttribute(hConsoleOut, 14);
	printf("Loading NeuronNet Custom Build\n");

	pLoad = fopen("BrainBuildReverse.txt", "r");
	linkey = 1;

	while (linkey < BRAIN_SIZE) {
		link = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));
		if (linkey <= INPUT_NEURONS) {
			i = 1;
			while (fgets(buff, BRAIN_SIZE, pLoad) != '\0') {
				string[0] = strtok(buff, " ");
				link->OutboundConnections[0].outboundNeuron = atoi(string[0]);
				while (i < FIRE_CONNECTIONS)
				{
					string[i] = strtok(NULL, " ");
					link->OutboundConnections[i].outboundNeuron = atoi(string[i]);
					i++;
				}
				break;
			}
			i = 1;
			while (fgets(buff, BRAIN_SIZE, pLoad) != '\0') {
				string[0] = strtok(buff, " ");
				link->InboundConnections[0].inboundNeuron = atoi(string[0]);
				while (i < FIRE_CONNECTIONS)
				{
					string[i] = strtok(NULL, " ");
					link->InboundConnections[i].inboundNeuron = atoi(string[i]);
					i++;
				}
				break;
			}
		}
		else if (linkey > INPUT_NEURONS) {
			i = 1;
			while (fgets(buff, BRAIN_SIZE, pLoad) != '\0') {
				string[0] = strtok(buff, " ");
				link->OutboundConnections[0].outboundNeuron = atoi(string[0]);
				while (i < OUTBOUND_CONNECTIONS)
				{
					string[i] = strtok(NULL, " ");
					link->OutboundConnections[i].outboundNeuron = atoi(string[i]);
					i++;
				}
				break;
			}
			i = 1;
			while (fgets(buff, BRAIN_SIZE, pLoad) != '\0') {
				string[0] = strtok(buff, " ");
				link->InboundConnections[0].inboundNeuron = atoi(string[0]);
				while (i < INBOUND_CONNECTIONS)
				{
					string[i] = strtok(NULL, " ");
					link->InboundConnections[i].inboundNeuron = atoi(string[i]);
					i++;
				}
				break;
			}
		}
		fgets(buff, BRAIN_SIZE, pLoad);
		string[0] = strtok(buff, delimiter);
		link->key = atoi(string[0]);
		string[1] = strtok(NULL, delimiter);
		sprintf(tbuff, "%s", string[1]);
		link->electricPulse = atoi(tbuff);
		string[2] = strtok(NULL, delimiter);
		sprintf(tbuff, "%s", string[2]);
		link->fireThreshold = atoi(tbuff);
		string[3] = strtok(NULL, delimiter);
		sprintf(tbuff, "%s", string[3]);
		link->impedance = atoi(tbuff);
		string[4] = strtok(NULL, " ");
		link->fire = atoi(string[4]);
		string[5] = strtok(NULL, " \n");
		linkey = atoi(string[5]);

		link->next = head;
		head = link;
		linkey++;
	}
	printf("Done Loading...\n");
	fclose(pLoad);
	return(head);
}


int createConnection(int userIn) {

	int i, j, k, l;
	struct neuronNode* fireNeuron;
	int nextNeuron1;
	struct neuronNode* nextNeuron2;
	int outNeuron;
	int offSet;
	Connection stem[OUTBOUND_CONNECTIONS];

	printf("Creating a connection to Neuron %d\n", userIn+1);
	offSet = BRAIN_SIZE - OUTPUT_NEURONS;

	for (i = 1; i <= INPUT_NEURONS; i++) {
		if ( findNeuron(i)->fire = true ) {
			j = (int)(rand() % FIRE_CONNECTIONS);
			nextNeuron1 = findNeuron(i)->FireConnections[j].outboundNeuron;
			findNeuron(nextNeuron1)->fireThreshold = (1 - STRENGTHEN) * findNeuron(nextNeuron1)->electricPulse;
			findNeuron(nextNeuron1)->fire = true;
			k = (int)(rand() % INBOUND_CONNECTIONS);
			findNeuron(nextNeuron1)->InboundConnections[k].inboundNeuron = i;
			nextNeuron2 = findNeuron(offSet + userIn);
			findNeuron(nextNeuron1)->OutboundConnections[k].outboundNeuron = nextNeuron2->key;
			l = (int)(rand() % INBOUND_CONNECTIONS);
			findNeuron(nextNeuron2->key)->InboundConnections[l].inboundNeuron = nextNeuron1;
			nextNeuron2->fire = true;
		}
	}

	return(0);
}

void strengthenNeuron(int cell) {
	
	int nNode = cell;
	struct neuronNode* nCell = findNeuron(nNode);
	float randomNode;

	randomNode = (rand() % 50);
	if (nCell != NULL) {
		nCell->fireThreshold = nCell->fireThreshold * (1 - randomNode * STRENGTHEN * 0.1);
	}
}
void weakenNeuron(int cell) {

	int nNode = cell;
	float randomNode;

	struct neuronNode* nCell = findNeuron(nNode);
	if (nCell != NULL) {
		randomNode = (rand() % 50);
		if (nCell != NULL) {
			nCell->fireThreshold = nCell->fireThreshold * (1 + randomNode * STRENGTHEN * 0.1);
		}
	}
}

float SigmoidCall(int x) {
	float alpha = .1;
	float range;
	range = 0.5 * (x * alpha / (1 + sqrt((x * alpha)*(x * alpha)))) + 0.5;
	return( range );
}

void saveOutputarray(void) {

	int i;
	FILE* fp = fopen("temp2.txt", "w");

	for (i = 0; i < OUTPUT_NEURONS; i++) {
		fprintf(fp, "%d\n", outboundArray[i]);
	}
	fclose(fp);
}

void loadOutputarray(void) {

	int i;
	struct stat sb;
	char* file_contents = (char*)malloc(sb.st_size);
	FILE* fp2;
	
	if (fp2 = fopen("Temp2.txt", "r")) {

		for (i = 1; i < INPUT_NEURONS; i++) {
			if (fscanf(fp2, "%[^\n] ", file_contents) != NULL) {
				outboundArray[i] = outboundArray[i] + atoi(file_contents);
			}
			else { printf("Temp2.txt corrupt or not found\n"); }
		}
		fclose(fp2);
	}
}

int reverseFileLines(const char* input, const char* output)
{
		typedef long int li;
		int _count = 100, count = 0;
		size_t size = (sizeof(li) * _count), clearSize = size;
		li* lines = (li*)memset(malloc(size), 0, size);
		FILE* oldFile = fopen(input, "r");
		FILE* curFile = fopen(output, "w");
		char buff[BUFFSIZE] = { 0 };
		bool firsttime = true;
		while (!feof(oldFile))
		{
			lines[count] = ftell(oldFile);
			fgets(buff, BUFFSIZE, oldFile);
			if ((++count) == _count)
			{
				lines = ( li *)realloc(lines, (size += clearSize));
				memset(&lines[count], 0, clearSize);
				_count += 100;
			}
		}
		while (count > 0)
		{
			fseek(oldFile, lines[--count], SEEK_SET);
			fgets(buff, BUFFSIZE, oldFile);
			if (firsttime) {
				firsttime = false;
			}
			else {
				fputs(buff, curFile);
			}
		}
		free(lines);
		fclose(oldFile);
		fflush(curFile);
		fclose(curFile);
		return 0;
}