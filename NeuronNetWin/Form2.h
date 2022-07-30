#pragma once
#pragma comment (lib, "User32.lib")
#pragma comment (lib, "kernel32.lib")
#pragma comment (lib, "advapi32.lib")
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#ifndef _HEADERFILE_H
#include "Defs.h"
#endif

extern struct neuronNode* findNeuron(int);
extern int WeightRoute(int);
extern void GUISet(int);
extern int SaveBuild(void);
extern struct neuronNode* LoadBuild(void);
extern void SweepIO(void);
extern int PropagateFire(unsigned int);
extern void resetOutputs(void);
extern void SweepNet(void);
extern bool reverseLines(char*, char *);

extern int outboundArray[];
extern int offSet;

namespace NeuronNetWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			struct neuronNode* switchNode = NULL;
			//
			//TODO: Add the constructor code here
			//
			int k;
			for (k = 0; k < OUTPUT_NEURONS; k++) {
				switchNode = findNeuron(offSet + k);
				if (switchNode != NULL) {
					if (switchNode->fire == true) {
						switch (k) {
						case 0:
							O1->Checked = true;
							O1->BackColor = Color::Red;
							break;
						case 1:
							O2->Checked = true;
							O2->BackColor = Color::Red;
							break;
						case 2:
							O3->Checked = true;
							O3->BackColor = Color::Red;
							break;
						case 3:
							O4->Checked = true;
							O4->BackColor = Color::Red;
							break;
						case 4:
							O5->Checked = true;
							O5->BackColor = Color::Red;
							break;
						case 5:
							O6->Checked = true;
							O6->BackColor = Color::Red;
							break;
						case 6:
							O7->Checked = true;
							O7->BackColor = Color::Red;
							break;
						case 7:
							O8->Checked = true;
							O8->BackColor = Color::Red;
							break;
						case 8:
							O9->Checked = true;
							O9->BackColor = Color::Red;
							break;
						case 9:
							O10->Checked = true;
							O10->BackColor = Color::Red;
							break;
						case 10:
							O11->Checked = true;
							O11->BackColor = Color::Red;
							break;
						case 11:
							O12->Checked = true;
							O12->BackColor = Color::Red;
							break;
						case 12:
							O13->Checked = true;
							O13->BackColor = Color::Red;
							break;
						case 13:
							O14->Checked = true;
							O14->BackColor = Color::Red;
							break;
						case 14:
							O15->Checked = true;
							O15->BackColor = Color::Red;
							break;
						case 15:
							O16->Checked = true;
							O16->BackColor = Color::Red;
							break;
						case 16:
							O17->Checked = true;
							O17->BackColor = Color::Red;
							break;
						case 17:
							O18->Checked = true;
							O18->BackColor = Color::Red;
							break;
						case 18:
							O19->Checked = true;
							O19->BackColor = Color::Red;
							break;
						case 19:
							O20->Checked = true;
							O20->BackColor = Color::Red;
							break;
						case 20:
							O21->Checked = true;
							O21->BackColor = Color::Red;
							break;
						case 21:
							O22->Checked = true;
							O22->BackColor = Color::Red;
							break;
						case 22:
							O23->Checked = true;
							O23->BackColor = Color::Red;
							break;
						case 23:
							O24->Checked = true;
							O24->BackColor = Color::Red;
							break;
						case 24:
							O25->Checked = true;
							O25->BackColor = Color::Red;
							break;
						case 25:
							O26->Checked = true;
							O26->BackColor = Color::Red;
							break;
						case 26:
							O27->Checked = true;
							O27->BackColor = Color::Red;
							break;
						case 27:
							O28->Checked = true;
							O28->BackColor = Color::Red;
							break;
						case 28:
							O29->Checked = true;
							O29->BackColor = Color::Red;
							break;
						case 29:
							O30->Checked = true;
							O30->BackColor = Color::Red;
							break;
						case 30:
							O31->Checked = true;
							O31->BackColor = Color::Red;
							break;
						case 31:
							O32->Checked = true;
							O32->BackColor = Color::Red;
							break;
						case 32:
							O33->Checked = true;
							O33->BackColor = Color::Red;
							break;
						case 33:
							O34->Checked = true;
							O34->BackColor = Color::Red;
							break;
						case 34:
							O35->Checked = true;
							O35->BackColor = Color::Red;
							break;
						case 35:
							O36->Checked = true;
							O36->BackColor = Color::Red;
							break;
						case 36:
							O37->Checked = true;
							O37->BackColor = Color::Red;
							break;
						case 37:
							O38->Checked = true;
							O38->BackColor = Color::Red;
							break;
						case 38:
							O39->Checked = true;
							O39->BackColor = Color::Red;
							break;
						case 39:
							O40->Checked = true;
							O40->BackColor = Color::Red;
							break;
						case 40:
							O41->Checked = true;
							O41->BackColor = Color::Red;
							break;
						case 41:
							O42->Checked = true;
							O42->BackColor = Color::Red;
							break;
						case 42:
							O43->Checked = true;
							O43->BackColor = Color::Red;
							break;
						case 43:
							O44->Checked = true;
							O44->BackColor = Color::Red;
							break;
						case 44:
							O45->Checked = true;
							O45->BackColor = Color::Red;
							break;
						case 45:
							O46->Checked = true;
							O46->BackColor = Color::Red;
							break;
						case 46:
							O47->Checked = true;
							O47->BackColor = Color::Red;
							break;
						case 47:
							O48->Checked = true;
							O48->BackColor = Color::Red;
							break;
						case 48:
							O49->Checked = true;
							O49->BackColor = Color::Red;
							break;
						case 49:
							O50->Checked = true;
							O50->BackColor = Color::Red;
							break;
						case 50:
							O51->Checked = true;
							O51->BackColor = Color::Red;
							break;
						case 51:
							O52->Checked = true;
							O52->BackColor = Color::Red;
							break;
						case 52:
							O53->Checked = true;
							O53->BackColor = Color::Red;
							break;
						case 53:
							O54->Checked = true;
							O54->BackColor = Color::Red;
							break;
						case 54:
							O55->Checked = true;
							O55->BackColor = Color::Red;
							break;
						case 55:
							O56->Checked = true;
							O56->BackColor = Color::Red;
							break;
						case 56:
							O57->Checked = true;
							O57->BackColor = Color::Red;
							break;
						case 57:
							O58->Checked = true;
							O58->BackColor = Color::Red;
							break;
						case 58:
							O59->Checked = true;
							O59->BackColor = Color::Red;
							break;
						case 59:
							O60->Checked = true;
							O60->BackColor = Color::Red;
							break;
						case 60:
							O61->Checked = true;
							O61->BackColor = Color::Red;
							break;
						case 61:
							O62->Checked = true;
							O62->BackColor = Color::Red;
							break;
						case 62:
							O63->Checked = true;
							O63->BackColor = Color::Red;
							break;
						case 63:
							O64->Checked = true;
							O64->BackColor = Color::Red;
							break;
						default:
							break;
						}
					}
				}

			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::CheckBox^ O64;
	protected:
	public: System::Windows::Forms::CheckBox^ O63;
	public: System::Windows::Forms::CheckBox^ O62;
	public: System::Windows::Forms::CheckBox^ O61;
	public: System::Windows::Forms::CheckBox^ O56;
	public: System::Windows::Forms::CheckBox^ O55;
	public: System::Windows::Forms::CheckBox^ O54;
	public: System::Windows::Forms::CheckBox^ O53;
	public: System::Windows::Forms::CheckBox^ O48;
	public: System::Windows::Forms::CheckBox^ O47;
	public: System::Windows::Forms::CheckBox^ O46;
	public: System::Windows::Forms::CheckBox^ O45;
	public: System::Windows::Forms::CheckBox^ O40;
	public: System::Windows::Forms::CheckBox^ O39;
	public: System::Windows::Forms::CheckBox^ O38;
	public: System::Windows::Forms::CheckBox^ O37;
	public: System::Windows::Forms::CheckBox^ O60;
	public: System::Windows::Forms::CheckBox^ O59;
	public: System::Windows::Forms::CheckBox^ O58;
	public: System::Windows::Forms::CheckBox^ O57;
	public: System::Windows::Forms::CheckBox^ O52;
	public: System::Windows::Forms::CheckBox^ O51;
	public: System::Windows::Forms::CheckBox^ O50;
	public: System::Windows::Forms::CheckBox^ O49;
	public: System::Windows::Forms::CheckBox^ O44;
	public: System::Windows::Forms::CheckBox^ O43;
	public: System::Windows::Forms::CheckBox^ O42;
	public: System::Windows::Forms::CheckBox^ O41;
	public: System::Windows::Forms::CheckBox^ O36;
	public: System::Windows::Forms::CheckBox^ O35;
	public: System::Windows::Forms::CheckBox^ O34;
	public: System::Windows::Forms::CheckBox^ O33;
	public: System::Windows::Forms::CheckBox^ O32;
	public: System::Windows::Forms::CheckBox^ O31;
	public: System::Windows::Forms::CheckBox^ O30;
	public: System::Windows::Forms::CheckBox^ O29;
	public: System::Windows::Forms::CheckBox^ O24;
	public: System::Windows::Forms::CheckBox^ O23;
	public: System::Windows::Forms::CheckBox^ O22;
	public: System::Windows::Forms::CheckBox^ O21;
	public: System::Windows::Forms::CheckBox^ O16;
	public: System::Windows::Forms::CheckBox^ O15;
	public: System::Windows::Forms::CheckBox^ O14;
	public: System::Windows::Forms::CheckBox^ O13;
	public: System::Windows::Forms::CheckBox^ O8;
	public: System::Windows::Forms::CheckBox^ O7;
	public: System::Windows::Forms::CheckBox^ O6;
	public: System::Windows::Forms::CheckBox^ O5;
	public: System::Windows::Forms::CheckBox^ O28;
	public: System::Windows::Forms::CheckBox^ O27;
	public: System::Windows::Forms::CheckBox^ O26;
	public: System::Windows::Forms::CheckBox^ O25;
	public: System::Windows::Forms::CheckBox^ O20;
	public: System::Windows::Forms::CheckBox^ O19;
	public: System::Windows::Forms::CheckBox^ O18;
	public: System::Windows::Forms::CheckBox^ O17;
	public: System::Windows::Forms::CheckBox^ O12;
	public: System::Windows::Forms::CheckBox^ O11;
	public: System::Windows::Forms::CheckBox^ O10;
	public: System::Windows::Forms::CheckBox^ O9;
	public: System::Windows::Forms::CheckBox^ O4;
	private:
	public: System::Windows::Forms::CheckBox^ O3;
	public: System::Windows::Forms::CheckBox^ O2;
	public: System::Windows::Forms::CheckBox^ O1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Button^ button4;
public:

	protected:




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->O64 = (gcnew System::Windows::Forms::CheckBox());
			this->O63 = (gcnew System::Windows::Forms::CheckBox());
			this->O62 = (gcnew System::Windows::Forms::CheckBox());
			this->O61 = (gcnew System::Windows::Forms::CheckBox());
			this->O56 = (gcnew System::Windows::Forms::CheckBox());
			this->O55 = (gcnew System::Windows::Forms::CheckBox());
			this->O54 = (gcnew System::Windows::Forms::CheckBox());
			this->O53 = (gcnew System::Windows::Forms::CheckBox());
			this->O48 = (gcnew System::Windows::Forms::CheckBox());
			this->O47 = (gcnew System::Windows::Forms::CheckBox());
			this->O46 = (gcnew System::Windows::Forms::CheckBox());
			this->O45 = (gcnew System::Windows::Forms::CheckBox());
			this->O40 = (gcnew System::Windows::Forms::CheckBox());
			this->O39 = (gcnew System::Windows::Forms::CheckBox());
			this->O38 = (gcnew System::Windows::Forms::CheckBox());
			this->O37 = (gcnew System::Windows::Forms::CheckBox());
			this->O60 = (gcnew System::Windows::Forms::CheckBox());
			this->O59 = (gcnew System::Windows::Forms::CheckBox());
			this->O58 = (gcnew System::Windows::Forms::CheckBox());
			this->O57 = (gcnew System::Windows::Forms::CheckBox());
			this->O52 = (gcnew System::Windows::Forms::CheckBox());
			this->O51 = (gcnew System::Windows::Forms::CheckBox());
			this->O50 = (gcnew System::Windows::Forms::CheckBox());
			this->O49 = (gcnew System::Windows::Forms::CheckBox());
			this->O44 = (gcnew System::Windows::Forms::CheckBox());
			this->O43 = (gcnew System::Windows::Forms::CheckBox());
			this->O42 = (gcnew System::Windows::Forms::CheckBox());
			this->O41 = (gcnew System::Windows::Forms::CheckBox());
			this->O36 = (gcnew System::Windows::Forms::CheckBox());
			this->O35 = (gcnew System::Windows::Forms::CheckBox());
			this->O34 = (gcnew System::Windows::Forms::CheckBox());
			this->O33 = (gcnew System::Windows::Forms::CheckBox());
			this->O32 = (gcnew System::Windows::Forms::CheckBox());
			this->O31 = (gcnew System::Windows::Forms::CheckBox());
			this->O30 = (gcnew System::Windows::Forms::CheckBox());
			this->O29 = (gcnew System::Windows::Forms::CheckBox());
			this->O24 = (gcnew System::Windows::Forms::CheckBox());
			this->O23 = (gcnew System::Windows::Forms::CheckBox());
			this->O22 = (gcnew System::Windows::Forms::CheckBox());
			this->O21 = (gcnew System::Windows::Forms::CheckBox());
			this->O16 = (gcnew System::Windows::Forms::CheckBox());
			this->O15 = (gcnew System::Windows::Forms::CheckBox());
			this->O14 = (gcnew System::Windows::Forms::CheckBox());
			this->O13 = (gcnew System::Windows::Forms::CheckBox());
			this->O8 = (gcnew System::Windows::Forms::CheckBox());
			this->O7 = (gcnew System::Windows::Forms::CheckBox());
			this->O6 = (gcnew System::Windows::Forms::CheckBox());
			this->O5 = (gcnew System::Windows::Forms::CheckBox());
			this->O28 = (gcnew System::Windows::Forms::CheckBox());
			this->O27 = (gcnew System::Windows::Forms::CheckBox());
			this->O26 = (gcnew System::Windows::Forms::CheckBox());
			this->O25 = (gcnew System::Windows::Forms::CheckBox());
			this->O20 = (gcnew System::Windows::Forms::CheckBox());
			this->O19 = (gcnew System::Windows::Forms::CheckBox());
			this->O18 = (gcnew System::Windows::Forms::CheckBox());
			this->O17 = (gcnew System::Windows::Forms::CheckBox());
			this->O12 = (gcnew System::Windows::Forms::CheckBox());
			this->O11 = (gcnew System::Windows::Forms::CheckBox());
			this->O10 = (gcnew System::Windows::Forms::CheckBox());
			this->O9 = (gcnew System::Windows::Forms::CheckBox());
			this->O4 = (gcnew System::Windows::Forms::CheckBox());
			this->O3 = (gcnew System::Windows::Forms::CheckBox());
			this->O2 = (gcnew System::Windows::Forms::CheckBox());
			this->O1 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// O64
			// 
			this->O64->AutoSize = true;
			this->O64->Location = System::Drawing::Point(494, 264);
			this->O64->Name = L"O64";
			this->O64->Size = System::Drawing::Size(46, 17);
			this->O64->TabIndex = 233;
			this->O64->Text = L"O64";
			this->O64->UseVisualStyleBackColor = true;
			// 
			// O63
			// 
			this->O63->AutoSize = true;
			this->O63->Location = System::Drawing::Point(494, 241);
			this->O63->Name = L"O63";
			this->O63->Size = System::Drawing::Size(46, 17);
			this->O63->TabIndex = 232;
			this->O63->Text = L"O63";
			this->O63->UseVisualStyleBackColor = true;
			// 
			// O62
			// 
			this->O62->AutoSize = true;
			this->O62->Location = System::Drawing::Point(494, 218);
			this->O62->Name = L"O62";
			this->O62->Size = System::Drawing::Size(46, 17);
			this->O62->TabIndex = 231;
			this->O62->Text = L"O62";
			this->O62->UseVisualStyleBackColor = true;
			// 
			// O61
			// 
			this->O61->AutoSize = true;
			this->O61->Location = System::Drawing::Point(494, 196);
			this->O61->Name = L"O61";
			this->O61->Size = System::Drawing::Size(46, 17);
			this->O61->TabIndex = 230;
			this->O61->Text = L"O61";
			this->O61->UseVisualStyleBackColor = true;
			// 
			// O56
			// 
			this->O56->AutoSize = true;
			this->O56->Location = System::Drawing::Point(453, 263);
			this->O56->Name = L"O56";
			this->O56->Size = System::Drawing::Size(46, 17);
			this->O56->TabIndex = 229;
			this->O56->Text = L"O56";
			this->O56->UseVisualStyleBackColor = true;
			// 
			// O55
			// 
			this->O55->AutoSize = true;
			this->O55->Location = System::Drawing::Point(453, 241);
			this->O55->Name = L"O55";
			this->O55->Size = System::Drawing::Size(46, 17);
			this->O55->TabIndex = 228;
			this->O55->Text = L"O55";
			this->O55->UseVisualStyleBackColor = true;
			// 
			// O54
			// 
			this->O54->AutoSize = true;
			this->O54->Location = System::Drawing::Point(453, 218);
			this->O54->Name = L"O54";
			this->O54->Size = System::Drawing::Size(46, 17);
			this->O54->TabIndex = 227;
			this->O54->Text = L"O54";
			this->O54->UseVisualStyleBackColor = true;
			// 
			// O53
			// 
			this->O53->AutoSize = true;
			this->O53->Location = System::Drawing::Point(453, 196);
			this->O53->Name = L"O53";
			this->O53->Size = System::Drawing::Size(46, 17);
			this->O53->TabIndex = 226;
			this->O53->Text = L"O53";
			this->O53->UseVisualStyleBackColor = true;
			// 
			// O48
			// 
			this->O48->AutoSize = true;
			this->O48->Location = System::Drawing::Point(412, 263);
			this->O48->Name = L"O48";
			this->O48->Size = System::Drawing::Size(46, 17);
			this->O48->TabIndex = 225;
			this->O48->Text = L"O48";
			this->O48->UseVisualStyleBackColor = true;
			// 
			// O47
			// 
			this->O47->AutoSize = true;
			this->O47->Location = System::Drawing::Point(412, 241);
			this->O47->Name = L"O47";
			this->O47->Size = System::Drawing::Size(46, 17);
			this->O47->TabIndex = 224;
			this->O47->Text = L"O47";
			this->O47->UseVisualStyleBackColor = true;
			// 
			// O46
			// 
			this->O46->AutoSize = true;
			this->O46->Location = System::Drawing::Point(412, 218);
			this->O46->Name = L"O46";
			this->O46->Size = System::Drawing::Size(46, 17);
			this->O46->TabIndex = 223;
			this->O46->Text = L"O46";
			this->O46->UseVisualStyleBackColor = true;
			// 
			// O45
			// 
			this->O45->AutoSize = true;
			this->O45->Location = System::Drawing::Point(412, 196);
			this->O45->Name = L"O45";
			this->O45->Size = System::Drawing::Size(46, 17);
			this->O45->TabIndex = 222;
			this->O45->Text = L"O45";
			this->O45->UseVisualStyleBackColor = true;
			// 
			// O40
			// 
			this->O40->AutoSize = true;
			this->O40->Location = System::Drawing::Point(373, 263);
			this->O40->Name = L"O40";
			this->O40->Size = System::Drawing::Size(46, 17);
			this->O40->TabIndex = 221;
			this->O40->Text = L"O40";
			this->O40->UseVisualStyleBackColor = true;
			// 
			// O39
			// 
			this->O39->AutoSize = true;
			this->O39->Location = System::Drawing::Point(373, 241);
			this->O39->Name = L"O39";
			this->O39->Size = System::Drawing::Size(46, 17);
			this->O39->TabIndex = 220;
			this->O39->Text = L"O39";
			this->O39->UseVisualStyleBackColor = true;
			// 
			// O38
			// 
			this->O38->AutoSize = true;
			this->O38->Location = System::Drawing::Point(373, 218);
			this->O38->Name = L"O38";
			this->O38->Size = System::Drawing::Size(46, 17);
			this->O38->TabIndex = 219;
			this->O38->Text = L"O38";
			this->O38->UseVisualStyleBackColor = true;
			// 
			// O37
			// 
			this->O37->AutoSize = true;
			this->O37->Location = System::Drawing::Point(373, 196);
			this->O37->Name = L"O37";
			this->O37->Size = System::Drawing::Size(46, 17);
			this->O37->TabIndex = 218;
			this->O37->Text = L"O37";
			this->O37->UseVisualStyleBackColor = true;
			// 
			// O60
			// 
			this->O60->AutoSize = true;
			this->O60->Location = System::Drawing::Point(494, 175);
			this->O60->Name = L"O60";
			this->O60->Size = System::Drawing::Size(46, 17);
			this->O60->TabIndex = 217;
			this->O60->Text = L"O60";
			this->O60->UseVisualStyleBackColor = true;
			// 
			// O59
			// 
			this->O59->AutoSize = true;
			this->O59->Location = System::Drawing::Point(494, 152);
			this->O59->Name = L"O59";
			this->O59->Size = System::Drawing::Size(46, 17);
			this->O59->TabIndex = 216;
			this->O59->Text = L"O59";
			this->O59->UseVisualStyleBackColor = true;
			// 
			// O58
			// 
			this->O58->AutoSize = true;
			this->O58->Location = System::Drawing::Point(494, 129);
			this->O58->Name = L"O58";
			this->O58->Size = System::Drawing::Size(46, 17);
			this->O58->TabIndex = 215;
			this->O58->Text = L"O58";
			this->O58->UseVisualStyleBackColor = true;
			// 
			// O57
			// 
			this->O57->AutoSize = true;
			this->O57->Location = System::Drawing::Point(494, 107);
			this->O57->Name = L"O57";
			this->O57->Size = System::Drawing::Size(46, 17);
			this->O57->TabIndex = 214;
			this->O57->Text = L"O57";
			this->O57->UseVisualStyleBackColor = true;
			// 
			// O52
			// 
			this->O52->AutoSize = true;
			this->O52->Location = System::Drawing::Point(453, 174);
			this->O52->Name = L"O52";
			this->O52->Size = System::Drawing::Size(46, 17);
			this->O52->TabIndex = 213;
			this->O52->Text = L"O52";
			this->O52->UseVisualStyleBackColor = true;
			// 
			// O51
			// 
			this->O51->AutoSize = true;
			this->O51->Location = System::Drawing::Point(453, 152);
			this->O51->Name = L"O51";
			this->O51->Size = System::Drawing::Size(46, 17);
			this->O51->TabIndex = 212;
			this->O51->Text = L"O51";
			this->O51->UseVisualStyleBackColor = true;
			// 
			// O50
			// 
			this->O50->AutoSize = true;
			this->O50->Location = System::Drawing::Point(453, 129);
			this->O50->Name = L"O50";
			this->O50->Size = System::Drawing::Size(46, 17);
			this->O50->TabIndex = 211;
			this->O50->Text = L"O50";
			this->O50->UseVisualStyleBackColor = true;
			// 
			// O49
			// 
			this->O49->AutoSize = true;
			this->O49->Location = System::Drawing::Point(453, 107);
			this->O49->Name = L"O49";
			this->O49->Size = System::Drawing::Size(46, 17);
			this->O49->TabIndex = 210;
			this->O49->Text = L"O49";
			this->O49->UseVisualStyleBackColor = true;
			// 
			// O44
			// 
			this->O44->AutoSize = true;
			this->O44->Location = System::Drawing::Point(412, 174);
			this->O44->Name = L"O44";
			this->O44->Size = System::Drawing::Size(46, 17);
			this->O44->TabIndex = 209;
			this->O44->Text = L"O44";
			this->O44->UseVisualStyleBackColor = true;
			// 
			// O43
			// 
			this->O43->AutoSize = true;
			this->O43->Location = System::Drawing::Point(412, 152);
			this->O43->Name = L"O43";
			this->O43->Size = System::Drawing::Size(46, 17);
			this->O43->TabIndex = 208;
			this->O43->Text = L"O43";
			this->O43->UseVisualStyleBackColor = true;
			// 
			// O42
			// 
			this->O42->AutoSize = true;
			this->O42->Location = System::Drawing::Point(412, 129);
			this->O42->Name = L"O42";
			this->O42->Size = System::Drawing::Size(46, 17);
			this->O42->TabIndex = 207;
			this->O42->Text = L"O42";
			this->O42->UseVisualStyleBackColor = true;
			// 
			// O41
			// 
			this->O41->AutoSize = true;
			this->O41->Location = System::Drawing::Point(412, 107);
			this->O41->Name = L"O41";
			this->O41->Size = System::Drawing::Size(46, 17);
			this->O41->TabIndex = 206;
			this->O41->Text = L"O41";
			this->O41->UseVisualStyleBackColor = true;
			// 
			// O36
			// 
			this->O36->AutoSize = true;
			this->O36->Location = System::Drawing::Point(373, 174);
			this->O36->Name = L"O36";
			this->O36->Size = System::Drawing::Size(46, 17);
			this->O36->TabIndex = 205;
			this->O36->Text = L"O36";
			this->O36->UseVisualStyleBackColor = true;
			// 
			// O35
			// 
			this->O35->AutoSize = true;
			this->O35->Location = System::Drawing::Point(373, 152);
			this->O35->Name = L"O35";
			this->O35->Size = System::Drawing::Size(46, 17);
			this->O35->TabIndex = 204;
			this->O35->Text = L"O35";
			this->O35->UseVisualStyleBackColor = true;
			// 
			// O34
			// 
			this->O34->AutoSize = true;
			this->O34->Location = System::Drawing::Point(373, 129);
			this->O34->Name = L"O34";
			this->O34->Size = System::Drawing::Size(46, 17);
			this->O34->TabIndex = 203;
			this->O34->Text = L"O34";
			this->O34->UseVisualStyleBackColor = true;
			// 
			// O33
			// 
			this->O33->AutoSize = true;
			this->O33->Location = System::Drawing::Point(373, 107);
			this->O33->Name = L"O33";
			this->O33->Size = System::Drawing::Size(46, 17);
			this->O33->TabIndex = 202;
			this->O33->Text = L"O33";
			this->O33->UseVisualStyleBackColor = true;
			// 
			// O32
			// 
			this->O32->AutoSize = true;
			this->O32->Location = System::Drawing::Point(333, 264);
			this->O32->Name = L"O32";
			this->O32->Size = System::Drawing::Size(46, 17);
			this->O32->TabIndex = 201;
			this->O32->Text = L"O32";
			this->O32->UseVisualStyleBackColor = true;
			// 
			// O31
			// 
			this->O31->AutoSize = true;
			this->O31->Location = System::Drawing::Point(333, 241);
			this->O31->Name = L"O31";
			this->O31->Size = System::Drawing::Size(46, 17);
			this->O31->TabIndex = 200;
			this->O31->Text = L"O31";
			this->O31->UseVisualStyleBackColor = true;
			// 
			// O30
			// 
			this->O30->AutoSize = true;
			this->O30->Location = System::Drawing::Point(333, 218);
			this->O30->Name = L"O30";
			this->O30->Size = System::Drawing::Size(46, 17);
			this->O30->TabIndex = 199;
			this->O30->Text = L"O30";
			this->O30->UseVisualStyleBackColor = true;
			// 
			// O29
			// 
			this->O29->AutoSize = true;
			this->O29->Location = System::Drawing::Point(333, 196);
			this->O29->Name = L"O29";
			this->O29->Size = System::Drawing::Size(46, 17);
			this->O29->TabIndex = 198;
			this->O29->Text = L"O29";
			this->O29->UseVisualStyleBackColor = true;
			// 
			// O24
			// 
			this->O24->AutoSize = true;
			this->O24->Location = System::Drawing::Point(291, 263);
			this->O24->Name = L"O24";
			this->O24->Size = System::Drawing::Size(46, 17);
			this->O24->TabIndex = 197;
			this->O24->Text = L"O24";
			this->O24->UseVisualStyleBackColor = true;
			// 
			// O23
			// 
			this->O23->AutoSize = true;
			this->O23->Location = System::Drawing::Point(291, 241);
			this->O23->Name = L"O23";
			this->O23->Size = System::Drawing::Size(46, 17);
			this->O23->TabIndex = 196;
			this->O23->Text = L"O23";
			this->O23->UseVisualStyleBackColor = true;
			// 
			// O22
			// 
			this->O22->AutoSize = true;
			this->O22->Location = System::Drawing::Point(291, 218);
			this->O22->Name = L"O22";
			this->O22->Size = System::Drawing::Size(46, 17);
			this->O22->TabIndex = 195;
			this->O22->Text = L"O22";
			this->O22->UseVisualStyleBackColor = true;
			// 
			// O21
			// 
			this->O21->AutoSize = true;
			this->O21->Location = System::Drawing::Point(291, 196);
			this->O21->Name = L"O21";
			this->O21->Size = System::Drawing::Size(46, 17);
			this->O21->TabIndex = 194;
			this->O21->Text = L"O21";
			this->O21->UseVisualStyleBackColor = true;
			// 
			// O16
			// 
			this->O16->AutoSize = true;
			this->O16->Location = System::Drawing::Point(252, 263);
			this->O16->Name = L"O16";
			this->O16->Size = System::Drawing::Size(46, 17);
			this->O16->TabIndex = 193;
			this->O16->Text = L"O16";
			this->O16->UseVisualStyleBackColor = true;
			// 
			// O15
			// 
			this->O15->AutoSize = true;
			this->O15->Location = System::Drawing::Point(252, 241);
			this->O15->Name = L"O15";
			this->O15->Size = System::Drawing::Size(46, 17);
			this->O15->TabIndex = 192;
			this->O15->Text = L"O15";
			this->O15->UseVisualStyleBackColor = true;
			// 
			// O14
			// 
			this->O14->AutoSize = true;
			this->O14->Location = System::Drawing::Point(252, 218);
			this->O14->Name = L"O14";
			this->O14->Size = System::Drawing::Size(46, 17);
			this->O14->TabIndex = 191;
			this->O14->Text = L"O14";
			this->O14->UseVisualStyleBackColor = true;
			// 
			// O13
			// 
			this->O13->AutoSize = true;
			this->O13->Location = System::Drawing::Point(252, 196);
			this->O13->Name = L"O13";
			this->O13->Size = System::Drawing::Size(46, 17);
			this->O13->TabIndex = 190;
			this->O13->Text = L"O13";
			this->O13->UseVisualStyleBackColor = true;
			// 
			// O8
			// 
			this->O8->AutoSize = true;
			this->O8->Location = System::Drawing::Point(213, 263);
			this->O8->Name = L"O8";
			this->O8->Size = System::Drawing::Size(40, 17);
			this->O8->TabIndex = 189;
			this->O8->Text = L"O8";
			this->O8->UseVisualStyleBackColor = true;
			// 
			// O7
			// 
			this->O7->AutoSize = true;
			this->O7->Location = System::Drawing::Point(213, 241);
			this->O7->Name = L"O7";
			this->O7->Size = System::Drawing::Size(40, 17);
			this->O7->TabIndex = 188;
			this->O7->Text = L"O7";
			this->O7->UseVisualStyleBackColor = true;
			// 
			// O6
			// 
			this->O6->AutoSize = true;
			this->O6->Location = System::Drawing::Point(213, 218);
			this->O6->Name = L"O6";
			this->O6->Size = System::Drawing::Size(40, 17);
			this->O6->TabIndex = 187;
			this->O6->Text = L"O6";
			this->O6->UseVisualStyleBackColor = true;
			// 
			// O5
			// 
			this->O5->AutoSize = true;
			this->O5->Location = System::Drawing::Point(213, 196);
			this->O5->Name = L"O5";
			this->O5->Size = System::Drawing::Size(40, 17);
			this->O5->TabIndex = 186;
			this->O5->Text = L"O5";
			this->O5->UseVisualStyleBackColor = true;
			// 
			// O28
			// 
			this->O28->AutoSize = true;
			this->O28->Location = System::Drawing::Point(333, 175);
			this->O28->Name = L"O28";
			this->O28->Size = System::Drawing::Size(46, 17);
			this->O28->TabIndex = 185;
			this->O28->Text = L"O28";
			this->O28->UseVisualStyleBackColor = true;
			// 
			// O27
			// 
			this->O27->AutoSize = true;
			this->O27->Location = System::Drawing::Point(333, 152);
			this->O27->Name = L"O27";
			this->O27->Size = System::Drawing::Size(46, 17);
			this->O27->TabIndex = 184;
			this->O27->Text = L"O27";
			this->O27->UseVisualStyleBackColor = true;
			// 
			// O26
			// 
			this->O26->AutoSize = true;
			this->O26->Location = System::Drawing::Point(333, 129);
			this->O26->Name = L"O26";
			this->O26->Size = System::Drawing::Size(46, 17);
			this->O26->TabIndex = 183;
			this->O26->Text = L"O26";
			this->O26->UseVisualStyleBackColor = true;
			// 
			// O25
			// 
			this->O25->AutoSize = true;
			this->O25->Location = System::Drawing::Point(333, 107);
			this->O25->Name = L"O25";
			this->O25->Size = System::Drawing::Size(46, 17);
			this->O25->TabIndex = 182;
			this->O25->Text = L"O25";
			this->O25->UseVisualStyleBackColor = true;
			// 
			// O20
			// 
			this->O20->AutoSize = true;
			this->O20->Location = System::Drawing::Point(291, 174);
			this->O20->Name = L"O20";
			this->O20->Size = System::Drawing::Size(46, 17);
			this->O20->TabIndex = 181;
			this->O20->Text = L"O20";
			this->O20->UseVisualStyleBackColor = true;
			// 
			// O19
			// 
			this->O19->AutoSize = true;
			this->O19->Location = System::Drawing::Point(291, 152);
			this->O19->Name = L"O19";
			this->O19->Size = System::Drawing::Size(46, 17);
			this->O19->TabIndex = 180;
			this->O19->Text = L"O19";
			this->O19->UseVisualStyleBackColor = true;
			// 
			// O18
			// 
			this->O18->AutoSize = true;
			this->O18->Location = System::Drawing::Point(291, 129);
			this->O18->Name = L"O18";
			this->O18->Size = System::Drawing::Size(46, 17);
			this->O18->TabIndex = 179;
			this->O18->Text = L"O18";
			this->O18->UseVisualStyleBackColor = true;
			// 
			// O17
			// 
			this->O17->AutoSize = true;
			this->O17->Location = System::Drawing::Point(291, 107);
			this->O17->Name = L"O17";
			this->O17->Size = System::Drawing::Size(46, 17);
			this->O17->TabIndex = 178;
			this->O17->Text = L"O17";
			this->O17->UseVisualStyleBackColor = true;
			// 
			// O12
			// 
			this->O12->AutoSize = true;
			this->O12->Location = System::Drawing::Point(252, 174);
			this->O12->Name = L"O12";
			this->O12->Size = System::Drawing::Size(46, 17);
			this->O12->TabIndex = 177;
			this->O12->Text = L"O12";
			this->O12->UseVisualStyleBackColor = true;
			// 
			// O11
			// 
			this->O11->AutoSize = true;
			this->O11->Location = System::Drawing::Point(252, 152);
			this->O11->Name = L"O11";
			this->O11->Size = System::Drawing::Size(46, 17);
			this->O11->TabIndex = 176;
			this->O11->Text = L"O11";
			this->O11->UseVisualStyleBackColor = true;
			// 
			// O10
			// 
			this->O10->AutoSize = true;
			this->O10->Location = System::Drawing::Point(252, 129);
			this->O10->Name = L"O10";
			this->O10->Size = System::Drawing::Size(46, 17);
			this->O10->TabIndex = 175;
			this->O10->Text = L"O10";
			this->O10->UseVisualStyleBackColor = true;
			// 
			// O9
			// 
			this->O9->AutoSize = true;
			this->O9->Location = System::Drawing::Point(252, 107);
			this->O9->Name = L"O9";
			this->O9->Size = System::Drawing::Size(40, 17);
			this->O9->TabIndex = 174;
			this->O9->Text = L"O9";
			this->O9->UseVisualStyleBackColor = true;
			// 
			// O4
			// 
			this->O4->AutoSize = true;
			this->O4->Location = System::Drawing::Point(213, 174);
			this->O4->Name = L"O4";
			this->O4->Size = System::Drawing::Size(40, 17);
			this->O4->TabIndex = 173;
			this->O4->Text = L"O4";
			this->O4->UseVisualStyleBackColor = true;
			// 
			// O3
			// 
			this->O3->AutoSize = true;
			this->O3->Location = System::Drawing::Point(213, 152);
			this->O3->Name = L"O3";
			this->O3->Size = System::Drawing::Size(40, 17);
			this->O3->TabIndex = 172;
			this->O3->Text = L"O3";
			this->O3->UseVisualStyleBackColor = true;
			// 
			// O2
			// 
			this->O2->AutoSize = true;
			this->O2->Location = System::Drawing::Point(213, 129);
			this->O2->Name = L"O2";
			this->O2->Size = System::Drawing::Size(40, 17);
			this->O2->TabIndex = 171;
			this->O2->Text = L"O2";
			this->O2->UseVisualStyleBackColor = true;
			// 
			// O1
			// 
			this->O1->AutoSize = true;
			this->O1->Location = System::Drawing::Point(213, 107);
			this->O1->Name = L"O1";
			this->O1->Size = System::Drawing::Size(40, 17);
			this->O1->TabIndex = 170;
			this->O1->Text = L"O1";
			this->O1->UseVisualStyleBackColor = true;
			this->O1->CheckedChanged += gcnew System::EventHandler(this, &Form2::O1_CheckedChanged_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(248, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(259, 20);
			this->label2->TabIndex = 234;
			this->label2->Text = L"Output Neurons - 2D Array Format";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(18, 367);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(160, 17);
			this->label5->TabIndex = 237;
			this->label5->Text = L"10,000 Neuron Version";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(18, 334);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(308, 21);
			this->label3->TabIndex = 236;
			this->label3->Text = L"Neural Network Simulator Configurator";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(459, 363);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 21);
			this->label4->TabIndex = 235;
			this->label4->Text = L"2022 Veridical LLC";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(34, 89);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 39);
			this->button1->TabIndex = 238;
			this->button1->Text = L"Strengthen Connection";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(34, 145);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(117, 39);
			this->button2->TabIndex = 239;
			this->button2->Text = L"Weaken Connection";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(34, 200);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(117, 39);
			this->button3->TabIndex = 240;
			this->button3->Text = L"Save Build";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form2::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(34, 257);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(117, 39);
			this->button4->TabIndex = 241;
			this->button4->Text = L"Refresh Form";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form2::button4_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(652, 411);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->O64);
			this->Controls->Add(this->O63);
			this->Controls->Add(this->O62);
			this->Controls->Add(this->O61);
			this->Controls->Add(this->O56);
			this->Controls->Add(this->O55);
			this->Controls->Add(this->O54);
			this->Controls->Add(this->O53);
			this->Controls->Add(this->O48);
			this->Controls->Add(this->O47);
			this->Controls->Add(this->O46);
			this->Controls->Add(this->O45);
			this->Controls->Add(this->O40);
			this->Controls->Add(this->O39);
			this->Controls->Add(this->O38);
			this->Controls->Add(this->O37);
			this->Controls->Add(this->O60);
			this->Controls->Add(this->O59);
			this->Controls->Add(this->O58);
			this->Controls->Add(this->O57);
			this->Controls->Add(this->O52);
			this->Controls->Add(this->O51);
			this->Controls->Add(this->O50);
			this->Controls->Add(this->O49);
			this->Controls->Add(this->O44);
			this->Controls->Add(this->O43);
			this->Controls->Add(this->O42);
			this->Controls->Add(this->O41);
			this->Controls->Add(this->O36);
			this->Controls->Add(this->O35);
			this->Controls->Add(this->O34);
			this->Controls->Add(this->O33);
			this->Controls->Add(this->O32);
			this->Controls->Add(this->O31);
			this->Controls->Add(this->O30);
			this->Controls->Add(this->O29);
			this->Controls->Add(this->O24);
			this->Controls->Add(this->O23);
			this->Controls->Add(this->O22);
			this->Controls->Add(this->O21);
			this->Controls->Add(this->O16);
			this->Controls->Add(this->O15);
			this->Controls->Add(this->O14);
			this->Controls->Add(this->O13);
			this->Controls->Add(this->O8);
			this->Controls->Add(this->O7);
			this->Controls->Add(this->O6);
			this->Controls->Add(this->O5);
			this->Controls->Add(this->O28);
			this->Controls->Add(this->O27);
			this->Controls->Add(this->O26);
			this->Controls->Add(this->O25);
			this->Controls->Add(this->O20);
			this->Controls->Add(this->O19);
			this->Controls->Add(this->O18);
			this->Controls->Add(this->O17);
			this->Controls->Add(this->O12);
			this->Controls->Add(this->O11);
			this->Controls->Add(this->O10);
			this->Controls->Add(this->O9);
			this->Controls->Add(this->O4);
			this->Controls->Add(this->O3);
			this->Controls->Add(this->O2);
			this->Controls->Add(this->O1);
			this->Name = L"Form2";
			this->Text = L"NeuronNetSim V.b01";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void O1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		O1->Checked;
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	WeightRoute(1);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	WeightRoute(2);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {;
	SaveBuild();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void O1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
