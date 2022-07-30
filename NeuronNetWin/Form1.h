#pragma once
#pragma comment (lib, "User32.lib")
#pragma comment (lib, "kernel32.lib")
#pragma comment (lib, "advapi32.lib")
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Defs.h"
#include "Windows.h"

extern struct neuronNode* findNeuron(int);
extern int MainBuild(void);
extern int MainLoad(void);
extern struct neuronNode* LoadBuild(void);
extern int PropagateFire(unsigned int);
extern void SweepNet(void);
extern void SweepIO(void);
extern int SaveBuild(void);
extern float SigmoidCall(int);
extern void fprintStructure();
extern void loadOutputarray();
extern void printStructureReverse(struct neuronNode*);
extern int reverseFileLines(const char*, const char*);

extern struct NeuralNetwork* brain;
extern struct neuronNode* head;
extern struct neuronNode* top;
extern struct neuronNode* tail;
extern struct neuronNode* current;
extern struct neuronNode* next;
extern int inputArray[];
extern int outboundArray[];
extern int offSet;
extern bool mainBLD;

namespace NeuronNetWin {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Timers;
	using namespace std::chrono_literals;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ BuildNet;
	private: System::Windows::Forms::Button^ LoadNet;
	private: System::Windows::Forms::Button^ FireButton;
	private: System::Windows::Forms::Button^ customButton;
		   //Added temp































	private: System::Windows::Forms::Label^ label1;




































































































	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ outputPatternToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ arrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ linearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ circularToolStripMenuItem;



	private: System::Windows::Forms::CheckBox^ I1;
	private: System::Windows::Forms::CheckBox^ I2;
	private: System::Windows::Forms::CheckBox^ I3;
	private: System::Windows::Forms::CheckBox^ I4;
	private: System::Windows::Forms::CheckBox^ I8;
	private: System::Windows::Forms::CheckBox^ I7;
	private: System::Windows::Forms::CheckBox^ I6;
	private: System::Windows::Forms::CheckBox^ I5;
	private: System::Windows::Forms::CheckBox^ I12;
	private: System::Windows::Forms::CheckBox^ I11;
	private: System::Windows::Forms::CheckBox^ I10;
	private: System::Windows::Forms::CheckBox^ I9;
	private: System::Windows::Forms::CheckBox^ I16;
	private: System::Windows::Forms::CheckBox^ I15;
	private: System::Windows::Forms::CheckBox^ I14;
	private: System::Windows::Forms::CheckBox^ I13;













	private:




































































































	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label2;












































	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->BuildNet = (gcnew System::Windows::Forms::Button());
			this->LoadNet = (gcnew System::Windows::Forms::Button());
			this->FireButton = (gcnew System::Windows::Forms::Button());
			this->customButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->outputPatternToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->arrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->linearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circularToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->I1 = (gcnew System::Windows::Forms::CheckBox());
			this->I2 = (gcnew System::Windows::Forms::CheckBox());
			this->I3 = (gcnew System::Windows::Forms::CheckBox());
			this->I4 = (gcnew System::Windows::Forms::CheckBox());
			this->I8 = (gcnew System::Windows::Forms::CheckBox());
			this->I7 = (gcnew System::Windows::Forms::CheckBox());
			this->I6 = (gcnew System::Windows::Forms::CheckBox());
			this->I5 = (gcnew System::Windows::Forms::CheckBox());
			this->I12 = (gcnew System::Windows::Forms::CheckBox());
			this->I11 = (gcnew System::Windows::Forms::CheckBox());
			this->I10 = (gcnew System::Windows::Forms::CheckBox());
			this->I9 = (gcnew System::Windows::Forms::CheckBox());
			this->I16 = (gcnew System::Windows::Forms::CheckBox());
			this->I15 = (gcnew System::Windows::Forms::CheckBox());
			this->I14 = (gcnew System::Windows::Forms::CheckBox());
			this->I13 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// BuildNet
			// 
			this->BuildNet->AllowDrop = true;
			this->BuildNet->BackColor = System::Drawing::Color::Salmon;
			this->BuildNet->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BuildNet->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BuildNet->ForeColor = System::Drawing::Color::Black;
			this->BuildNet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BuildNet.Image")));
			this->BuildNet->Location = System::Drawing::Point(69, 235);
			this->BuildNet->Margin = System::Windows::Forms::Padding(4);
			this->BuildNet->Name = L"BuildNet";
			this->BuildNet->Size = System::Drawing::Size(143, 49);
			this->BuildNet->TabIndex = 0;
			this->BuildNet->Text = L"Build NeuronNet";
			this->BuildNet->UseVisualStyleBackColor = false;
			this->BuildNet->Click += gcnew System::EventHandler(this, &Form1::BuildNet_Click);
			// 
			// LoadNet
			// 
			this->LoadNet->AllowDrop = true;
			this->LoadNet->BackColor = System::Drawing::Color::Salmon;
			this->LoadNet->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->LoadNet->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoadNet->ForeColor = System::Drawing::Color::Black;
			this->LoadNet->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoadNet.Image")));
			this->LoadNet->Location = System::Drawing::Point(69, 162);
			this->LoadNet->Margin = System::Windows::Forms::Padding(4);
			this->LoadNet->Name = L"LoadNet";
			this->LoadNet->Size = System::Drawing::Size(143, 49);
			this->LoadNet->TabIndex = 1;
			this->LoadNet->Text = L"Load NeuronNet";
			this->LoadNet->UseVisualStyleBackColor = false;
			this->LoadNet->Click += gcnew System::EventHandler(this, &Form1::LoadNet_Click);
			// 
			// FireButton
			// 
			this->FireButton->AllowDrop = true;
			this->FireButton->BackColor = System::Drawing::Color::Salmon;
			this->FireButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->FireButton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FireButton->ForeColor = System::Drawing::Color::Black;
			this->FireButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FireButton.Image")));
			this->FireButton->Location = System::Drawing::Point(69, 309);
			this->FireButton->Margin = System::Windows::Forms::Padding(4);
			this->FireButton->Name = L"FireButton";
			this->FireButton->Size = System::Drawing::Size(143, 49);
			this->FireButton->TabIndex = 2;
			this->FireButton->Text = L"Fire Input Pattern";
			this->FireButton->UseVisualStyleBackColor = false;
			this->FireButton->Click += gcnew System::EventHandler(this, &Form1::FireButton_Click);
			// 
			// customButton
			// 
			this->customButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->customButton->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->customButton->ForeColor = System::Drawing::Color::Black;
			this->customButton->Location = System::Drawing::Point(887, 310);
			this->customButton->Margin = System::Windows::Forms::Padding(4);
			this->customButton->Name = L"customButton";
			this->customButton->Size = System::Drawing::Size(143, 49);
			this->customButton->TabIndex = 174;
			this->customButton->Text = L"Load Custom Build";
			this->customButton->UseVisualStyleBackColor = false;
			this->customButton->Click += gcnew System::EventHandler(this, &Form1::customButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(484, 165);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 26);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Input Neurons";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Gray;
			this->menuStrip1->Enabled = false;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Location = System::Drawing::Point(0, 28);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1108, 24);
			this->menuStrip1->TabIndex = 85;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->outputPatternToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(1108, 28);
			this->menuStrip2->TabIndex = 86;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// outputPatternToolStripMenuItem
			// 
			this->outputPatternToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->arrayToolStripMenuItem,
					this->linearToolStripMenuItem, this->circularToolStripMenuItem
			});
			this->outputPatternToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium Cond", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->outputPatternToolStripMenuItem->Name = L"outputPatternToolStripMenuItem";
			this->outputPatternToolStripMenuItem->Size = System::Drawing::Size(199, 24);
			this->outputPatternToolStripMenuItem->Text = L"Output Pattern Format Selection";
			this->outputPatternToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::outputPatternToolStripMenuItem_Click);
			// 
			// arrayToolStripMenuItem
			// 
			this->arrayToolStripMenuItem->Name = L"arrayToolStripMenuItem";
			this->arrayToolStripMenuItem->Size = System::Drawing::Size(134, 26);
			this->arrayToolStripMenuItem->Text = L"Array";
			// 
			// linearToolStripMenuItem
			// 
			this->linearToolStripMenuItem->Name = L"linearToolStripMenuItem";
			this->linearToolStripMenuItem->Size = System::Drawing::Size(134, 26);
			this->linearToolStripMenuItem->Text = L"Linear";
			// 
			// circularToolStripMenuItem
			// 
			this->circularToolStripMenuItem->Name = L"circularToolStripMenuItem";
			this->circularToolStripMenuItem->Size = System::Drawing::Size(134, 26);
			this->circularToolStripMenuItem->Text = L"Circular";
			// 
			// I1
			// 
			this->I1->AutoSize = true;
			this->I1->BackColor = System::Drawing::Color::Salmon;
			this->I1->Enabled = false;
			this->I1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I1->ForeColor = System::Drawing::Color::Black;
			this->I1->Location = System::Drawing::Point(471, 244);
			this->I1->Margin = System::Windows::Forms::Padding(4);
			this->I1->Name = L"I1";
			this->I1->Size = System::Drawing::Size(41, 20);
			this->I1->TabIndex = 90;
			this->I1->Text = L"I1";
			this->I1->UseVisualStyleBackColor = false;
			this->I1->CheckedChanged += gcnew System::EventHandler(this, &Form1::I1_CheckedChanged_1);
			// 
			// I2
			// 
			this->I2->AutoSize = true;
			this->I2->BackColor = System::Drawing::Color::Salmon;
			this->I2->Enabled = false;
			this->I2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I2->ForeColor = System::Drawing::Color::Black;
			this->I2->Location = System::Drawing::Point(471, 277);
			this->I2->Margin = System::Windows::Forms::Padding(4);
			this->I2->Name = L"I2";
			this->I2->Size = System::Drawing::Size(41, 20);
			this->I2->TabIndex = 90;
			this->I2->Text = L"I2";
			this->I2->UseVisualStyleBackColor = false;
			this->I2->CheckedChanged += gcnew System::EventHandler(this, &Form1::I2_CheckedChanged_1);
			// 
			// I3
			// 
			this->I3->AutoSize = true;
			this->I3->BackColor = System::Drawing::Color::Salmon;
			this->I3->Enabled = false;
			this->I3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I3->ForeColor = System::Drawing::Color::Black;
			this->I3->Location = System::Drawing::Point(471, 310);
			this->I3->Margin = System::Windows::Forms::Padding(4);
			this->I3->Name = L"I3";
			this->I3->Size = System::Drawing::Size(41, 20);
			this->I3->TabIndex = 92;
			this->I3->Text = L"I3";
			this->I3->UseVisualStyleBackColor = false;
			this->I3->CheckedChanged += gcnew System::EventHandler(this, &Form1::I3_CheckedChanged_1);
			// 
			// I4
			// 
			this->I4->AutoSize = true;
			this->I4->BackColor = System::Drawing::Color::Salmon;
			this->I4->Enabled = false;
			this->I4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I4->ForeColor = System::Drawing::Color::Black;
			this->I4->Location = System::Drawing::Point(471, 342);
			this->I4->Margin = System::Windows::Forms::Padding(4);
			this->I4->Name = L"I4";
			this->I4->Size = System::Drawing::Size(41, 20);
			this->I4->TabIndex = 93;
			this->I4->Text = L"I4";
			this->I4->UseVisualStyleBackColor = false;
			this->I4->CheckedChanged += gcnew System::EventHandler(this, &Form1::I4_CheckedChanged_1);
			// 
			// I8
			// 
			this->I8->AutoSize = true;
			this->I8->BackColor = System::Drawing::Color::Salmon;
			this->I8->Enabled = false;
			this->I8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I8->ForeColor = System::Drawing::Color::Black;
			this->I8->Location = System::Drawing::Point(520, 342);
			this->I8->Margin = System::Windows::Forms::Padding(4);
			this->I8->Name = L"I8";
			this->I8->Size = System::Drawing::Size(41, 20);
			this->I8->TabIndex = 97;
			this->I8->Text = L"I8";
			this->I8->UseVisualStyleBackColor = false;
			this->I8->CheckedChanged += gcnew System::EventHandler(this, &Form1::I8_CheckedChanged_1);
			// 
			// I7
			// 
			this->I7->AutoSize = true;
			this->I7->BackColor = System::Drawing::Color::Salmon;
			this->I7->Enabled = false;
			this->I7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I7->ForeColor = System::Drawing::Color::Black;
			this->I7->Location = System::Drawing::Point(520, 309);
			this->I7->Margin = System::Windows::Forms::Padding(4);
			this->I7->Name = L"I7";
			this->I7->Size = System::Drawing::Size(41, 20);
			this->I7->TabIndex = 96;
			this->I7->Text = L"I7";
			this->I7->UseVisualStyleBackColor = false;
			this->I7->CheckedChanged += gcnew System::EventHandler(this, &Form1::I7_CheckedChanged_1);
			// 
			// I6
			// 
			this->I6->AutoSize = true;
			this->I6->BackColor = System::Drawing::Color::Salmon;
			this->I6->Enabled = false;
			this->I6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I6->ForeColor = System::Drawing::Color::Black;
			this->I6->Location = System::Drawing::Point(520, 277);
			this->I6->Margin = System::Windows::Forms::Padding(4);
			this->I6->Name = L"I6";
			this->I6->Size = System::Drawing::Size(41, 20);
			this->I6->TabIndex = 95;
			this->I6->Text = L"I6";
			this->I6->UseVisualStyleBackColor = false;
			this->I6->CheckedChanged += gcnew System::EventHandler(this, &Form1::I6_CheckedChanged_1);
			// 
			// I5
			// 
			this->I5->AutoSize = true;
			this->I5->BackColor = System::Drawing::Color::Salmon;
			this->I5->Enabled = false;
			this->I5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I5->ForeColor = System::Drawing::Color::Black;
			this->I5->Location = System::Drawing::Point(520, 244);
			this->I5->Margin = System::Windows::Forms::Padding(4);
			this->I5->Name = L"I5";
			this->I5->Size = System::Drawing::Size(41, 20);
			this->I5->TabIndex = 94;
			this->I5->Text = L"I5";
			this->I5->UseVisualStyleBackColor = false;
			this->I5->CheckedChanged += gcnew System::EventHandler(this, &Form1::I5_CheckedChanged_1);
			// 
			// I12
			// 
			this->I12->AutoSize = true;
			this->I12->BackColor = System::Drawing::Color::Salmon;
			this->I12->Enabled = false;
			this->I12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I12->ForeColor = System::Drawing::Color::Black;
			this->I12->Location = System::Drawing::Point(569, 342);
			this->I12->Margin = System::Windows::Forms::Padding(4);
			this->I12->Name = L"I12";
			this->I12->Size = System::Drawing::Size(49, 20);
			this->I12->TabIndex = 101;
			this->I12->Text = L"I12";
			this->I12->UseVisualStyleBackColor = false;
			this->I12->CheckedChanged += gcnew System::EventHandler(this, &Form1::I12_CheckedChanged_1);
			// 
			// I11
			// 
			this->I11->AutoSize = true;
			this->I11->BackColor = System::Drawing::Color::Salmon;
			this->I11->Enabled = false;
			this->I11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I11->ForeColor = System::Drawing::Color::Black;
			this->I11->Location = System::Drawing::Point(569, 310);
			this->I11->Margin = System::Windows::Forms::Padding(4);
			this->I11->Name = L"I11";
			this->I11->Size = System::Drawing::Size(49, 20);
			this->I11->TabIndex = 100;
			this->I11->Text = L"I11";
			this->I11->UseVisualStyleBackColor = false;
			this->I11->CheckedChanged += gcnew System::EventHandler(this, &Form1::I11_CheckedChanged_1);
			// 
			// I10
			// 
			this->I10->AutoSize = true;
			this->I10->Enabled = false;
			this->I10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I10->ForeColor = System::Drawing::Color::Black;
			this->I10->Location = System::Drawing::Point(569, 277);
			this->I10->Margin = System::Windows::Forms::Padding(4);
			this->I10->Name = L"I10";
			this->I10->Size = System::Drawing::Size(49, 20);
			this->I10->TabIndex = 99;
			this->I10->Text = L"I10";
			this->I10->UseVisualStyleBackColor = false;
			this->I10->CheckedChanged += gcnew System::EventHandler(this, &Form1::I10_CheckedChanged_1);
			// 
			// I9
			// 
			this->I9->AutoSize = true;
			this->I9->BackColor = System::Drawing::Color::Salmon;
			this->I9->Enabled = false;
			this->I9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I9->ForeColor = System::Drawing::Color::Black;
			this->I9->Location = System::Drawing::Point(569, 244);
			this->I9->Margin = System::Windows::Forms::Padding(4);
			this->I9->Name = L"I9";
			this->I9->Size = System::Drawing::Size(41, 20);
			this->I9->TabIndex = 98;
			this->I9->Text = L"I9";
			this->I9->UseVisualStyleBackColor = false;
			this->I9->CheckedChanged += gcnew System::EventHandler(this, &Form1::I9_CheckedChanged_1);
			// 
			// I16
			// 
			this->I16->AutoSize = true;
			this->I16->BackColor = System::Drawing::Color::Salmon;
			this->I16->Enabled = false;
			this->I16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I16->ForeColor = System::Drawing::Color::Black;
			this->I16->Location = System::Drawing::Point(621, 342);
			this->I16->Margin = System::Windows::Forms::Padding(4);
			this->I16->Name = L"I16";
			this->I16->Size = System::Drawing::Size(49, 20);
			this->I16->TabIndex = 105;
			this->I16->Text = L"I16";
			this->I16->UseVisualStyleBackColor = false;
			this->I16->CheckedChanged += gcnew System::EventHandler(this, &Form1::I16_CheckedChanged);
			// 
			// I15
			// 
			this->I15->AutoSize = true;
			this->I15->BackColor = System::Drawing::Color::Salmon;
			this->I15->Enabled = false;
			this->I15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I15->ForeColor = System::Drawing::Color::Black;
			this->I15->Location = System::Drawing::Point(621, 310);
			this->I15->Margin = System::Windows::Forms::Padding(4);
			this->I15->Name = L"I15";
			this->I15->Size = System::Drawing::Size(49, 20);
			this->I15->TabIndex = 104;
			this->I15->Text = L"I15";
			this->I15->UseVisualStyleBackColor = false;
			this->I15->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox14_CheckedChanged);
			// 
			// I14
			// 
			this->I14->AutoSize = true;
			this->I14->BackColor = System::Drawing::Color::Salmon;
			this->I14->Enabled = false;
			this->I14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I14->ForeColor = System::Drawing::Color::Black;
			this->I14->Location = System::Drawing::Point(621, 277);
			this->I14->Margin = System::Windows::Forms::Padding(4);
			this->I14->Name = L"I14";
			this->I14->Size = System::Drawing::Size(49, 20);
			this->I14->TabIndex = 103;
			this->I14->Text = L"I14";
			this->I14->UseVisualStyleBackColor = false;
			this->I14->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox15_CheckedChanged);
			// 
			// I13
			// 
			this->I13->AutoSize = true;
			this->I13->BackColor = System::Drawing::Color::Salmon;
			this->I13->Enabled = false;
			this->I13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->I13->ForeColor = System::Drawing::Color::Black;
			this->I13->Location = System::Drawing::Point(621, 244);
			this->I13->Margin = System::Windows::Forms::Padding(4);
			this->I13->Name = L"I13";
			this->I13->Size = System::Drawing::Size(49, 20);
			this->I13->TabIndex = 102;
			this->I13->Text = L"I13";
			this->I13->UseVisualStyleBackColor = false;
			this->I13->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox16_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(64, 471);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(380, 27);
			this->label3->TabIndex = 170;
			this->label3->Text = L"Neural Network Simulator Configurator";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click_1);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(64, 512);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(202, 23);
			this->label5->TabIndex = 171;
			this->label5->Text = L"10,000 Neuron Version";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Book", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(827, 507);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(196, 27);
			this->label2->TabIndex = 172;
			this->label2->Text = L"2022 Veridical LLC";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click_1);
			// 
			// Form1
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Salmon;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1108, 588);
			this->Controls->Add(this->customButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->I2);
			this->Controls->Add(this->I16);
			this->Controls->Add(this->I15);
			this->Controls->Add(this->I14);
			this->Controls->Add(this->I13);
			this->Controls->Add(this->I12);
			this->Controls->Add(this->I11);
			this->Controls->Add(this->I10);
			this->Controls->Add(this->I9);
			this->Controls->Add(this->I8);
			this->Controls->Add(this->I7);
			this->Controls->Add(this->I6);
			this->Controls->Add(this->I5);
			this->Controls->Add(this->I4);
			this->Controls->Add(this->I3);
			this->Controls->Add(this->I1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->FireButton);
			this->Controls->Add(this->LoadNet);
			this->Controls->Add(this->BuildNet);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"NeuronNetSim V.b01";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		I1->Enabled = true;
		I2->Enabled = true;
		I3->Enabled = true;
		I4->Enabled = true;
		I5->Enabled = true;
		I6->Enabled = true;
		I7->Enabled = true;
		I8->Enabled = true;
		I9->Enabled = true;
		I10->Enabled = true;
		I11->Enabled = true;
		I12->Enabled = true;
		I13->Enabled = true;
		I14->Enabled = true;
		I15->Enabled = true;
		I16->Enabled = true;

		MainBuild();
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void O13_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton13_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton8_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void arrayToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void LoadNet_Click(System::Object^ sender, System::EventArgs^ e) {
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::WriteLine("Neural Net Assembly Kit Loaded\n");
	}
	private: System::Void outputPatternToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I15_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I14_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I13_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I12_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I11_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I10_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I9_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I16_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[16] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void checkBox16_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[13] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void checkBox15_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[14] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void checkBox14_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[15] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void checkBox13_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[13] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I12_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[12] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I11_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[11] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I10_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[10] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I9_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[9] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}

private: System::Void I8_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[8] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I7_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[7] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I6_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[6] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I5_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[5] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I4_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[4] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I3_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[3] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I2_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[2] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void I1_CheckedChanged_1(System::Object ^ sender, System::EventArgs ^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
	if (activeCheckBox->Checked) {
		inputArray[1] = 1;
		activeCheckBox->ForeColor = Color::Purple;
		activeCheckBox->BackColor = Color::Purple;
	}
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox33_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void FireButton_Click(System::Object^ sender, System::EventArgs^ e) {

	MainLoad();
}
private: System::Void BuildNet_Click(System::Object^ sender, System::EventArgs^ e) {
	I1->Enabled = true;
	I2->Enabled = true;
	I3->Enabled = true;
	I4->Enabled = true;
	I5->Enabled = true;
	I6->Enabled = true;
	I7->Enabled = true;
	I8->Enabled = true;
	I9->Enabled = true;
	I10->Enabled = true;
	I11->Enabled = true;
	I12->Enabled = true;
	I13->Enabled = true;
	I14->Enabled = true;
	I15->Enabled = true;
	I16->Enabled = true;

	MainBuild();
}
public: System::Void O1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}

public: System::Void Scan_Outputs_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {

}
	   
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void customButton_Click(System::Object^ sender, System::EventArgs^ e) {
	Button^ activeButton = safe_cast<Button^>(sender);
	int i;
	int rc;
	I1->Enabled = true;
	I2->Enabled = true;
	I3->Enabled = true;
	I4->Enabled = true;
	I5->Enabled = true;
	I6->Enabled = true;
	I7->Enabled = true;
	I8->Enabled = true;
	I9->Enabled = true;
	I10->Enabled = true;
	I11->Enabled = true;
	I12->Enabled = true;
	I13->Enabled = true;
	I14->Enabled = true;
	I15->Enabled = true;
	I16->Enabled = true;

	rc = reverseFileLines("BrainBuild.txt", "BrainBuildReverse.txt");

	head = LoadBuild();
	top = head;
}
private: System::Void checkBox1_CheckedChanged_2(System::Object^ sender, System::EventArgs^ e) {
	CheckBox^ activeCheckBox = safe_cast<CheckBox^>(sender);
}
};
}

