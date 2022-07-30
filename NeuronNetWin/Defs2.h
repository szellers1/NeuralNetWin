#ifndef _HEADERFILE_H
#define _HEADERFILE_H
#define BRAIN_SIZE 1024
#define OUTBOUND_CONNECTIONS 48
#define INBOUND_CONNECTIONS 24
#define FIRE_CONNECTIONS 16
#define DENDRITE_STRENGTH_LEVELS 10
#define INPUT_NEURONS 16
#define OUTPUT_NEURONS 64
#define STRENGTHEN .25
#define TRACE_LEN 72

typedef struct connectNode {
	int outboundNeuron;
	int inboundNeuron;
} Connection;

struct neuronNode *Neuronptr;

struct neuronNode {
	int key;
	float electricPulse;
	float fireThreshold;
	float impedance;
	bool fire;
	Connection OutboundConnections[OUTBOUND_CONNECTIONS];
	Connection InboundConnections[INBOUND_CONNECTIONS];
	Connection FireConnections[FIRE_CONNECTIONS];
	struct neuronNode* next;
};
#endif


