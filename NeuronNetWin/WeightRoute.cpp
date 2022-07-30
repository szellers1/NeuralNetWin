#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
# include <string.h>
#include <sys/stat.h>
#include "Defs.h"
#include "Form2.h"

int WeightRoute(int);
extern void strengthenNeuron(int);
extern void weakenNeuron(int);
extern int createConnection(int);
extern struct neuronNode* findNeuron(int);
extern int reverseFileLines(const char*, const char*);

extern int numIterations;

using namespace NeuronNetWin;

int WeightRoute(int strengthen) {

    int   i, j, k, l, m;
    int   strengthenNode = strengthen;
    unsigned int   uIn;
    int   trace_node;
    int   output_neuron, trace_count;
    int   offset = BRAIN_SIZE - OUTPUT_NEURONS;
    int   rc;
    float randomNode;
    bool  found = false;
    char* p = NULL;
    char* prev = NULL;
    const char* filename = "Reverseroute.txt";
    const char* token = "%[^\n] ";
    FILE* in_file = fopen(filename, "r");
    struct stat sb;
    char first_char[5];
    int terminus;
    struct neuronNode* discon;
    struct neuronNode* Nfirst = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));
    struct neuronNode* Nfound;

    //Traceroute needs to be reversed first
    rc = reverseFileLines("Traceroute.txt", "Reverseroute.txt");

    printf("Which Output Neuron do you want to process (Number in Red)?\n");
    do {
        scanf("%d", &uIn);
    } while (uIn < 1 || uIn > 64);
    printf("You entered %d\n", uIn);
    if (!in_file) {
        perror("No Traceroute file found");
        exit(EXIT_FAILURE);
    }

    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    char* file_contents = (char*)malloc(sb.st_size);

    while (!(feof(in_file))) {
        fscanf(in_file, "%[^\n] ", file_contents);
        fscanf(in_file, "%d\n", &output_neuron);
        fscanf(in_file, "%d\n", &trace_count);

        if (uIn == output_neuron) {
            if ((p = strtok(file_contents, token)) != NULL) {
                if (strengthenNode == 1) {
                    printf("Strengthening connections to output Neuron %d:\n", uIn);
                    strengthenNeuron(atoi(p));
                }
                if (strengthenNode == 2) {
                    printf("Weakening connections to output Neuron %d:\n", uIn);
                    weakenNeuron(atoi(p));
                }
                printf("%d ", atoi(p));
                while ((p = strtok(NULL, token)) != NULL) {
                    if (strengthenNode == 1) {
                        strengthenNeuron(atoi(p));
                    }
                    if (strengthenNode == 2) {
                        weakenNeuron(atoi(p));
                    }
                    printf("%d ", atoi(p));
                    prev = p;
                }                 //prevent hard crash if only 1 connecting neuron
                printf("\n");
                //Hard disconnect fire on last Neuron
                if (strengthenNode == 2) {
                    randomNode = (rand() % 50);
                    Nfound = findNeuron(atoi(prev));
                    Nfound->fireThreshold = Nfound->fireThreshold * (1 - randomNode * STRENGTHEN * 0.01);
                    for (i = 1; i <= OUTBOUND_CONNECTIONS; i++) {
                        terminus = Nfound->OutboundConnections[i].outboundNeuron;
                        if (terminus == (uIn + offset)) {
                            Nfound->OutboundConnections[i].outboundNeuron =
                                (int)(rand() % (OUTPUT_NEURONS - INPUT_NEURONS)) + INPUT_NEURONS + 1;
                            continue;
                        }
                    }
                }
            }
            printf("\n");
            found = true;
        }
        //Hard connect selected neuron
        else {
            if (strengthenNode == 1) {
                for (i = INPUT_NEURONS+1; i <= offset; i++) {
                    if (findNeuron(i) != NULL) {
                        if (findNeuron(i)->fire == true) {  
                            Nfound = findNeuron(i);
                            break;
                        }
                    }
                    else { return(0); }
                }
                Nfound->electricPulse = 1.0;
                Nfound->fireThreshold = 0.0;
                Nfound->fire = true;
                /*Create first Neuron*/
                for (i = 1; i <= INPUT_NEURONS; i++) {
                    if (findNeuron(i)->fire == true) {
                        Nfirst = findNeuron(i);
                        break;
                    }
                }
                j = (rand() % FIRE_CONNECTIONS);
                Nfirst->FireConnections[j].outboundNeuron = Nfound->key;
                k = (rand() % INBOUND_CONNECTIONS);
                Nfound->InboundConnections[k].inboundNeuron = Nfirst->key;
                terminus = (uIn + offset);
                l = (rand() % OUTBOUND_CONNECTIONS);
                Nfound->OutboundConnections[l].outboundNeuron = terminus;
                m = (rand() % INBOUND_CONNECTIONS);
                findNeuron(terminus)->InboundConnections[m].inboundNeuron = Nfound->key;
                findNeuron(terminus)->electricPulse = 1.0;
                findNeuron(terminus)->fireThreshold = 0.0;
                findNeuron(terminus)->fire = true;
            }
        }
    }
    if (!found) {
        if (p == NULL) {
            if (strengthenNode == 1) {
                createConnection(uIn);
            }
            if (strengthenNode == 2) {
                printf("Cannot weaken disconnected Neuron\n");
            }
        }
    }
    fclose(in_file);
    free(file_contents);
    return(0);
}