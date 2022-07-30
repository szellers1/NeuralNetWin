#pragma comment (lib, "User32.lib")
#pragma comment (lib, "kernel32.lib")
#pragma comment (lib, "advapi32.lib")
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <winuser.h>
#include <conio.h>

#include<Windows.h>
#include<iostream>
#include <string>
#include "Defs.h"
#include "Form2.h"

extern int outboundArray[];
extern int numIterations;

    void scanoutput() {
        int k;

        using namespace NeuronNetWin;

            NeuronNetWin::Form2 myForm;
            NeuronNetWin::CheckBox O1;
            for (k = 0; k < OUTPUT_NEURONS; k++) {
                if (outboundArray[k] > numIterations) {
                    k = k + 1;
                    switch (k) {
                    case 1: 
                        myForm.O1->Checked = true;
                        break;
                    case 2:
                        myForm.O2->Checked = true;
                        break;
                    case 3:
                        myForm.O3->Checked = true;
                        break;
                    case 4:
                        myForm.O4->Checked = true;
                        break;
                    case 5:
                        myForm.O5->Checked = true;
                        break;
                    case 6:
                        myForm.O6->Checked = true;
                        break;
                    case 7:
                        myForm.O7->Checked = true;
                        break;
                    case 8:
                        myForm.O8->Checked = true;
                        break;
                    case 9:
                        myForm.O9->Checked = true;
                        break;
                    case 10:
                        myForm.O10->Checked = true;
                        break;
                    case 11:
                        myForm.O11->Checked = true;
                        break;
                    case 12:
                        myForm.O12->Checked = true;
                        break;
                    case 13:
                        myForm.O13->Checked = true;
                        break;
                    case 14:
                        myForm.O14->Checked = true;
                        break;
                    case 15:
                        myForm.O15->Checked = true;
                        break;
                    case 16:
                        myForm.O16->Checked = true;
                        break;
                    case 17:
                        myForm.O17->Checked = true;
                        break;
                    case 18:
                        myForm.O18->Checked = true;
                        break;
                    case 19:
                        myForm.O19->Checked = true;
                        break;
                    case 20:
                        myForm.O20->Checked = true;
                        break;
                    case 21:
                        myForm.O21->Checked = true;
                        break;
                    case 22:
                        myForm.O22->Checked = true;
                        break;
                    case 23:
                        myForm.O23->Checked = true;
                        break;
                    case 24:
                        myForm.O24->Checked = true;
                        break;
                    case 25:
                        myForm.O25->Checked = true;
                        break;
                    case 26:
                        myForm.O26->Checked = true;
                        break;
                    case 27:
                        myForm.O27->Checked = true;
                        break;
                    case 28:
                        myForm.O28->Checked = true;
                        break;
                    case 29:
                        myForm.O29->Checked = true;
                        break;
                    case 30:
                        myForm.O30->Checked = true;
                        break;
                    case 31:
                        myForm.O31->Checked = true;
                        break;
                    case 32:
                        myForm.O32->Checked = true;
                        break;
                    case 33:      
                        myForm.O33->Checked = true;
                        break;
                    case 34:
                        myForm.O34->Checked = true;
                        break;
                    case 35:
                        myForm.O35->Checked = true;
                        break;
                    case 36:
                        myForm.O36->Checked = true;
                        break;
                    case 37:
                        myForm.O37->Checked = true;
                        break;
                    case 38:
                        myForm.O38->Checked = true;
                        break;
                    case 39:
                        myForm.O39->Checked = true;
                        break;
                    case 40:
                        myForm.O40->Checked = true;
                        break;
                    case 41:
                        myForm.O41->Checked = true;
                        break;
                    case 42:
                        myForm.O42->Checked = true;
                        break;
                    case 43:
                        myForm.O43->Checked = true;
                        break;
                    case 44:
                        myForm.O44->Checked = true;
                        break;
                    case 45:
                        myForm.O45->Checked = true;
                        break;
                    case 46:
                        myForm.O46->Checked = true;
                        break;
                    case 47:
                        myForm.O47->Checked = true;
                        break;
                    case 48:
                        myForm.O48->Checked = true;
                        break;
                    case 49:
                        myForm.O49->Checked = true;
                        break;
                    case 50:
                        myForm.O50->Checked = true;
                        break;
                    case 51:
                        myForm.O51->Checked = true;
                        break;
                    case 52:
                        myForm.O52->Checked = true;
                        break;
                    case 53:
                        myForm.O53->Checked = true;
                        break;
                    case 54:
                        myForm.O54->Checked = true;
                        break;
                    case 55:
                        myForm.O55->Checked = true;
                        break;
                    case 56:
                        myForm.O56->Checked = true;
                        break;
                    case 57:
                        myForm.O57->Checked = true;
                        break;
                    case 58:
                        myForm.O58->Checked = true;
                        break;
                    case 59:
                        myForm.O59->Checked = true;
                        break;
                    case 60:
                        myForm.O60->Checked = true;
                        break;
                    case 61:
                        myForm.O61->Checked = true;
                        break;
                    case 62:
                        myForm.O62->Checked = true;
                        break;
                    case 63:
                        myForm.O63->Checked = true;
                        break;
                    case 64:
                        myForm.O64->Checked = true;
                        break;
                    default:
                        break;
                    
                    }
                }

            }

    }