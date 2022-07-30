//#include "pch.h"
// Steve's MultiThreaded Neural Network Program
// compile with: /c
//
#include "pch.h"
#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <conio.h>
#include <process.h>
#include <time.h>
#include <math.h>
#include "Defs.h"
#include "Form2.h"

#define MAX_THREADS 16

// The function getrandom returns a random number between
// min and max, which must be in integer range.
#define getrandom( min, max ) (SHORT)((rand() % (int)(((max) + 1) - \
                               (min))) + (min))

int MainBuild(void);
int MainLoad(void);
void FireNeuronThrd(void);                // Keyboard input, thread dispatch
void FireNeuron(void*);       // Threads 2 to n: display
float calculatePulse(struct neuronNode*);

int PropagateFire(unsigned int);
void ClearScreen(void);            // Screen clear
void ShutDown(void);               // Program shutdown
void WriteTitle(int);              // Display title bar information
extern struct neuronNode* findNeuron(int);
extern void SweepNet(void);
extern void SweepIO(void);
extern int SaveBuild(void);
extern void saveOutputarray(void);
extern void loadOutputarray(void);

HANDLE  hConsoleOut;                 // Handle to the console
HANDLE  hRunMutex;                   // "Keep Running" mutex
HANDLE  hScreenMutex;                // "Screen update" mutex
HWND    UIWin;
int     ThreadNr;                    // Number of threads started
CONSOLE_SCREEN_BUFFER_INFO csbiInfo; // Console information
COORD   consoleSize;
CRITICAL_SECTION cs;
BOOL    bTrails;
int     Traceroute = 1;
int     line_count = 1;
int     pulse_count = 0;
int     Ncount;
int     GUISetVal;
FILE* f_out = fopen("Traceroute.txt", "w");
bool    guisetall = false;
int     offSet = BRAIN_SIZE - OUTPUT_NEURONS;
BOOL    firing = true;
int     rc;
BOOL    gsfound = false;

extern struct NeuralNetwork* Brain;
extern struct neuronNode* head;
extern struct neuronNode* top;
extern struct neuronNode* tail;
extern struct neuronNode* current;
extern struct neuronNode* found;
struct neuronNode* fireNode = NULL;
int numIterations = 1;

int inputArray[INPUT_NEURONS+1];
int outboundArray[OUTPUT_NEURONS+1];
extern bool mainLD;

using namespace std;
using namespace System::Windows::Forms;

int MainLoad() // Thread One
{
    using namespace NeuronNetWin;

    int i;
   
    unsigned int seed = 48;
    srand(unsigned(seed));

    //If no input Neurons set for Input, set all Neurons for fire
    //for (i = 1; i < INPUT_NEURONS; i++) {
    //    if (findNeuron(i)->fire == true ) {
    //        gsfound = true;
    //    }
    //}

    //if (!gsfound) {
    //    printf("FIRING ALL INPUT NEURONS BY DEFAULT\n");
    //    for (i = 1; i < INPUT_NEURONS; i++) {
    //        findNeuron(i)->fire = true;
    //    }
    //}

    // Get display screen information & clear the screen.
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    consoleSize.X = csbiInfo.srWindow.Right;
    consoleSize.Y = csbiInfo.srWindow.Bottom;
    WriteTitle(0);

    // Create the mutexes and reset thread count.
    hScreenMutex = CreateMutexW(NULL, FALSE, NULL);  // Cleared
    hRunMutex = CreateMutexW(NULL, TRUE, NULL);      // Set
    ThreadNr = 0;
    bTrails = FALSE;

    //Set the firing Neuron thread
    if (firing) {
        FireNeuronThrd();
    }
    if (hScreenMutex) CloseHandle(hScreenMutex);
    if (hRunMutex) CloseHandle(hRunMutex);
    if (hConsoleOut) CloseHandle(hConsoleOut);

    return (0);
}

int PropagateFire(unsigned int neuron) {

    using namespace NeuronNetWin;
    int i, j, k;
    fireNode = NULL;

    int outbound;
    int next;
    int offset = BRAIN_SIZE - OUTPUT_NEURONS;
    int rc = 0;
    float flr;

    //stop when firing false
        //stop when firing false
    if (firing) {
        fireNode = findNeuron(neuron);
        if (fireNode != nullptr) {
            fireNode->fire = true;
            if (fireNode->key <= INPUT_NEURONS) {
                printf("FIRED INPUT NEURON =%d\n", fireNode->key);
                fprintf(f_out, "%d ", fireNode->key);
                for (i = 0; i < FIRE_CONNECTIONS; i++) {
                    j = (int)(rand() % (FIRE_CONNECTIONS));
                    if (fireNode->FireConnections[j].outboundNeuron != NULL) {
                        outbound = fireNode->FireConnections[j].outboundNeuron;
                        Sleep(50);
                        rc = PropagateFire(outbound); //Broad spray fire
                    }
                    else { return(0); }
                }
            }
            else if ((fireNode->key >= INPUT_NEURONS+1) && (fireNode->key <= offset)) {
                if (fireNode->electricPulse > fireNode->fireThreshold) {
                    fprintf(f_out, "%d ", fireNode->key);
                    Traceroute++;
                    for (i = 0; i < OUTBOUND_CONNECTIONS; i++) {
                        j = (int)(rand() % (OUTBOUND_CONNECTIONS));
                        if (fireNode->OutboundConnections[j].outboundNeuron != NULL) {
                            outbound = fireNode->OutboundConnections[j].outboundNeuron;
                            printf("Neuron %d with Pulse = %.1f and Threshold = %.1f Outbound Neuron %d\n",
                                fireNode->key, fireNode->electricPulse, fireNode->fireThreshold, outbound);
                            Sleep(50);
                            rc = PropagateFire(outbound);
                        }
                        else { return(0); }
                    }
                }
                //            else { return(0); }
            }
            else { //neuron > offset+1
                line_count = line_count + 1;
                fprintf(f_out, "\n%d\n", fireNode->key - (offset+1));
                fprintf(f_out, "%d\n", line_count - 1);
                printf("FIRED INTO OUTPUT MANIFOLD NEURON \n", fireNode->key - (offset+1));
                //Set flag in tracking array
                flr = (OUTPUT_NEURONS / 4);
                Sleep(50);
                if (line_count >= (int)flr) {
                    printf("NEURON OUTPUT LIMIT REACHED\n");
                    printf("Traceroute = %d\n", Traceroute);
                    fclose(f_out);
                    firing = false;
                    Form2^ form2 = gcnew Form2;
                    form2->ShowDialog();
                    return(0);
                }
            }
        }
    }
    return(rc);
}

void ShutDown(void) // Shut down threads
{
    using namespace NeuronNetWin;

    while (ThreadNr > 0)
    {
        // Tell thread to die and record its death.
        Console::Read();
        ReleaseMutex(hRunMutex);
        ReleaseMutex(hScreenMutex);
        ThreadNr--;
    }
       //hRunMutex = false;

    // Clean up display when done
    WaitForSingleObject(hScreenMutex, INFINITE);
    WaitForSingleObject(hRunMutex, INFINITE);
//    Form2^ form2 = gcnew Form2;
//    form2->ShowDialog();
 
}    

void FireNeuronThrd(void) // Dispatch and count threads.
{
   do {
       if (ThreadNr < MAX_THREADS)
       {
            ThreadNr++;
            _beginthread(FireNeuron, 0, &ThreadNr);
            WriteTitle(ThreadNr);
       }
   } while (firing);
   ShutDown();
}

void FireNeuron(void* pMyID)
{
    wchar_t MyCell, OldCell;
    WORD    MyAttrib, OldAttrib = 0;
    wchar_t BlankCell = 0x20;
    COORD   Coords, Delta;
    COORD   Old = { 0,0 };
    DWORD   Dummy;
    char* MyID = (char*)pMyID;
    CRITICAL_SECTION CriticalSection;
    struct neuronNode* fired = (struct neuronNode*)calloc(1, sizeof(struct neuronNode));

    int     firenode;
    const char* myarg = NULL;
    unsigned int i;

    // Generate update increments and initial
    // display coordinates.
    srand((unsigned int)*MyID * 3);

    Coords.X = getrandom(0, consoleSize.X - 1);
    Coords.Y = getrandom(0, consoleSize.Y - 1);
    Delta.X = getrandom(-3, 3);
    Delta.Y = getrandom(-3, 3);

    // Set up character & generate color
    // attribute from thread number.
    if (*MyID > 16)
        MyCell = 0x60 + *MyID - 16; // lower case
    else
        MyCell = 0x40 + *MyID;      // upper case
    MyAttrib = *MyID & 0x0f;   // force black background

    do
    {
        //Wait for display to be available, then lock it.
        WaitForSingleObject(hScreenMutex, INFINITE);

        // Increment the coordinates for next placement of the block.
        Old.X = Coords.X;
        Old.Y = Coords.Y;
        Coords.X += Delta.X;
        Coords.Y += Delta.Y;

        // If we are about to go off the screen, reverse direction
        if (Coords.X < 0 || Coords.X >= consoleSize.X)
        {
            Delta.X = -Delta.X;
            Beep(400, 50);
        }
        if (Coords.Y < 0 || Coords.Y > consoleSize.Y)
        {
            Delta.Y = -Delta.Y;
            Beep(600, 50);
        }

        Traceroute = 0;

        for (i = 1; i <= INPUT_NEURONS; i++) {
            if ( inputArray[i] == 1) {
                PropagateFire(i);   
            }
        }

        ReleaseMutex(hScreenMutex);

        //Fire each Neuron that has received a check mark on Form1
    }
    // Repeat while RunMutex is still taken.
    while (WaitForSingleObject(hRunMutex, 75L) == WAIT_TIMEOUT);
}

void WriteTitle(int ThreadNum)
{
    enum
    {
        sizeOfNThreadMsg = 120
    };
    wchar_t    NThreadMsg[sizeOfNThreadMsg] = { L"" };

    swprintf_s(NThreadMsg, sizeOfNThreadMsg,
        L"Threads running: %02d.", ThreadNum);
    SetConsoleTitleW(NThreadMsg);
}

void ClearScreen(void)
{
    DWORD    dummy = 0;
    COORD    Home = { 0, 0 };
    FillConsoleOutputCharacterW(hConsoleOut, L' ',
        consoleSize.X * consoleSize.Y,
        Home, &dummy);
}




