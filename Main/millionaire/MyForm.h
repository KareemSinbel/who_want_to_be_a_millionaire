#pragma once
#ifndef MYFORMS_H
#define MYFORMS_H

#include <fstream>                  //for reading and writing files
#include <vector>                   //for std::vectors
#include <string.h>                 //for string variable
#include <msclr\marshal_cppstd.h>   //used in project to convert System::String^ to anyother type of strings (std::string or std::wstring)
#include <algorithm>                //for using random_shuffle function which allow us to random an array without repition
#include <cliext/vector>            //for using vectors which can store a different type of data types (System::String^ .. etc)
#include "Won.h"                    //including a won form to display a another window when the user win or lose
#include <sstream>                  //Stream class to operate on strings have many (functions .. etc) to edit on string

std::vector<std::wstring>questionsfile, a1file, a2file, a3file, a4file;                              //vectors to store strings from the files
int questionsnum = 0;                      //number of questions
int* randomized;                           //an array full of number of questions in random order without repetition starting from 0 to questionsnum (depend on the number of questions in the file)
int maximumquestions = 15;                 //maximum number of questions will be asked
int questionsflag = 0;                     // the number of the exact question (starting from question 1 to question 15 --> maximum)
int randombutton;                          //random number between 0 and 3 to switch the button places in switch case
bool checkansweronce = false;              //variable used in checkanswer() to forbid maximumquestions from increasing over and over
std::string money[16] = {"0", "100","200","300","500","1000","2000","4000","8000","16000","32000","64000","125000","250000","500000","1 Million" };
System::Windows::Forms::DialogResult result;

void readfile()
{
	std::wfstream infile;
	infile.open("Questions\\stacks.txt");
	if (!infile)
	{
		result = System::Windows::Forms::MessageBox::Show("Error source file failed to load");
	}
	else
	{
		infile.imbue(std::locale("ar_EG.UTF-8"));
		std::wstring line;
		std::wstring pch;
		while (std::getline(infile, line))
		{
			std::wstringstream ws(line);
			std::getline(ws, pch, L',');
			questionsfile.push_back(pch);  //push question
			std::getline(ws, pch, L',');
			a1file.push_back(pch);//push answer 1 (correct answer)
			std::getline(ws, pch, L',');
			a2file.push_back(pch);//push answer 2
			std::getline(ws, pch, L',');
			a3file.push_back(pch);//push answer 3
			std::getline(ws, pch, L',');
			a4file.push_back(pch);//push answer 3
			questionsnum++;
		}
		infile.close();
	}
	randomized = new int[questionsnum];
}


namespace millionaire {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Timers;
	using namespace System::Threading;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
	static bool closed = false;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	public:
		static int reference = 0;
		MyForm(void)
		{
			closed = true;
			readfile();
			if (result == System::Windows::Forms::DialogResult::OK)
			{
				Application::Exit();
			}
			else
			{
				randomized = randomquestion();
				FillSysVector();
				InitializeComponent();
				nextquestion();
			}
			//
			//TODO: Add the constructor code here
			//
		}


	public:

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			Application::Exit();
			delete[] randomized;
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
    //private: System::Collections::Generic::List<System::String^>questions, a1, a2, a3, a4;
	//array<String^>^ strArray = gcnew array<String^>(10);
	private: cliext::vector<System::String^>questions, a1, a2, a3, a4;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	//private: array<String^>^ money = gcnew array<String^>;
	/*private: array<String^>^ a1 = gcnew array<String^>(questionsnum);
	private: array<String^>^ a2 = gcnew array<String^>(questionsnum);
	private: array<String^>^ a3 = gcnew array<String^>(questionsnum);
	private: array<String^>^ a4 = gcnew array<String^>(questionsnum);*/

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(168, 388);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(522, 59);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Questions";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(150, 482);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(245, 60);
			this->button1->TabIndex = 12;
			this->button1->TabStop = false;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->EnabledChanged += gcnew System::EventHandler(this, &MyForm::button1_EnabledChanged);
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(464, 482);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(245, 60);
			this->button2->TabIndex = 13;
			this->button2->TabStop = false;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->EnabledChanged += gcnew System::EventHandler(this, &MyForm::button2_EnabledChanged);
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold));
			this->button3->ForeColor = System::Drawing::SystemColors::Window;
			this->button3->Location = System::Drawing::Point(150, 574);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(245, 60);
			this->button3->TabIndex = 14;
			this->button3->TabStop = false;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->EnabledChanged += gcnew System::EventHandler(this, &MyForm::button3_EnabledChanged);
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14.25F, System::Drawing::FontStyle::Bold));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->Location = System::Drawing::Point(464, 574);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(245, 60);
			this->button4->TabIndex = 15;
			this->button4->TabStop = false;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->EnabledChanged += gcnew System::EventHandler(this, &MyForm::button4_EnabledChanged);
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 16);
			this->label2->TabIndex = 16;
			this->label2->Text = L"label2";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(832, 101);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(240, 415);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(330, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(170, 170);
			this->pictureBox2->TabIndex = 18;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(105, 374);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(650, 275);
			this->pictureBox3->TabIndex = 19;
			this->pictureBox3->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 1250;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 2000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(966, 12);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(106, 64);
			this->pictureBox4->TabIndex = 20;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &MyForm::pictureBox4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->groupBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->groupBox1->Location = System::Drawing::Point(105, 187);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox1->Size = System::Drawing::Size(650, 181);
			this->groupBox1->TabIndex = 21;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Retreat";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(502, 129);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(102, 29);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Retreat";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			this->label5->MouseLeave += gcnew System::EventHandler(this, &MyForm::label5_MouseLeave);
			this->label5->MouseHover += gcnew System::EventHandler(this, &MyForm::label5_MouseHover);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(63, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(541, 58);
			this->label3->TabIndex = 0;
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(63, 129);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(120, 29);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Continue";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			this->label4->MouseLeave += gcnew System::EventHandler(this, &MyForm::label4_MouseLeave);
			this->label4->MouseHover += gcnew System::EventHandler(this, &MyForm::label4_MouseHover);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(854, 12);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(106, 64);
			this->pictureBox5->TabIndex = 22;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &MyForm::pictureBox5_Click);
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1084, 661);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox3);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pheonix";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::escape_pressed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void escape_pressed(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		if (e->KeyCode == Keys::Escape) //to minimize the game screen
		{
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
			this->WindowState = System::Windows::Forms::FormWindowState::Normal;
			this->TopMost = false;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			/*this->label1->Location =  System::Drawing::Point(label1->Location.X + 100, label1->Location.Y + 75);
			this->label1->Location = System::Drawing::Point(233, 277);*/
		}

		if (e->Control && e->KeyCode == Keys::Enter)  //to maximize the game screen again
		{
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->TopMost = true;
			/*this->label1->Location = System::Drawing::Point(label1->Location.X + 50, label1->Location.Y + 20);*/
		}
	}

	private: System::Void FillSysVector()
	{
		for (int z = 0; z < questionsnum; z++)
		{
			String^ check_1 = gcnew String(questionsfile[z].c_str());
			questions.push_back(check_1); // questions.push_back(check_1) --- > = check_1
		}

		for (int z = 0; z < questionsnum; z++)
		{
			String^ check_1 = gcnew String(a1file[z].c_str());
			a1.push_back(check_1);
		}

		for (int z = 0; z < questionsnum; z++)
		{
			String^ check_1 = gcnew String(a2file[z].c_str());
			a2.push_back(check_1);
		}

		for (int z = 0; z < questionsnum; z++)
		{
			String^ check_1 = gcnew String(a3file[z].c_str());
			a3.push_back(check_1);
		}

		for (int z = 0; z < questionsnum; z++)
		{
			String^ check_1 = gcnew String(a4file[z].c_str());
			a4.push_back(check_1);
		}
	}

	private: System::Void nextquestion()
	{
		this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
		this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
		this->button3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
		this->button4->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
		this->label1->Enabled = true;
		this->button1->Enabled = true;
		this->button2->Enabled = true;
		this->button3->Enabled = true;
		this->button4->Enabled = true;
		this->button1->Visible = true;
		this->button2->Visible = true;
		this->button3->Visible = true;
		this->button4->Visible = true;
		if (maximumquestions > questionsflag)
		{
			//MessageBox::Show(gcnew String(std::to_string(questionsflag).c_str())+ "   " + gcnew String(std::to_string(maximumquestions).c_str()));
			int temp = randomized[questionsflag];
			srand(time(NULL));
			randombutton = (rand() % 4);
			/*String^ lab1 = gcnew String(questions[temp]);
			String^ answer1_Text = gcnew String(a1[temp]);
			String^ answer2_Text = gcnew String(a2[temp]);
			String^ answer3_Text = gcnew String(a3[temp]);
			String^ answer4_Text = gcnew String(a4[temp]);*/
			if (this->pictureBox5->Enabled == false)
			{
				String^ lab2 = gcnew String(std::to_string(questionsflag).c_str());
				label2->Text = "Question number: " + lab2;
				String^ path = gcnew String(std::to_string(questionsflag - 1).c_str());
				pictureBox1->Image = System::Drawing::Image::FromFile(L"Photos\\Money\\" + path + ".png");
				retreat(questionsflag - 1);
			}
			else
			{
				String^ lab2 = gcnew String(std::to_string(questionsflag + 1).c_str());
				label2->Text = "Question number: " + lab2;
				String^ path = gcnew String(std::to_string(questionsflag).c_str());
				pictureBox1->Image = System::Drawing::Image::FromFile(L"Photos\\Money\\" + path + ".png");
				retreat(questionsflag);
			}
			switch (randombutton)
			{
			case 0:
				this->label1->Text = questions[temp];
				this->button1->Text = a1[temp];
				this->button2->Text = a2[temp];
				this->button3->Text = a3[temp];
				this->button4->Text = a4[temp];
				break;
			case 1:
				this->label1->Text = questions[temp];
				this->button1->Text = a2[temp];
				this->button2->Text = a1[temp];
				this->button3->Text = a3[temp];
				this->button4->Text = a4[temp];
				break;
			case 2:
				this->label1->Text = questions[temp];
				this->button1->Text = a4[temp];
				this->button2->Text = a3[temp];
				this->button3->Text = a2[temp];
				this->button4->Text = a1[temp];
				break;
			case 3:
				this->label1->Text = questions[temp];
				this->button1->Text = a4[temp];
				this->button2->Text = a3[temp];
				this->button3->Text = a1[temp];
				this->button4->Text = a2[temp];
				break;
			}
		}
		else
		{
			//String^ path = gcnew String(std::to_string(questionsflag).c_str());
			pictureBox1->Image = System::Drawing::Image::FromFile(L"Photos\\Money\\15.png");
			this->label1->Enabled = false;
			this->button1->Visible = false;
			this->button2->Visible = false;
			this->button3->Visible = false;
			this->button4->Visible = false;
			Won::wonorlose = true;
			this->timer2->Interval = 2500;
			this->timer2->Enabled = true;
			this->timer2->Start();
		}

	}

	public: void gameover()
	{
		//MessageBox::Show(gcnew String((std::to_string(Won::flag)).c_str()));
		if (Won::flag == 1)
		{
			//this->Enabled = false;
			this->Hide();
			Won^ window = gcnew Won(this);
			window->TopMost = true;
			window->Show();
			Won::wonorlose = false;
			this->restartthegame();
		}
		else if (Won::flag == 2)
		{
			this->Hide();
			Won^ window = gcnew Won(this);
			window->TopMost = true;
			window->Show();
			this->restartthegame();
		}
	}

	public: void restartthegame()
	{
		/*messagebox::show("done");
		if (won::createagain == 1)
		{
			this->enabled = true;
			myform^ n = gcnew myform();
			n->topmost = true;
			n->show();
			won::createagain = 0;
			this->close();
		}
		won^ won = gcnew won();
		won->showdialog(this);
		myform^ window = gcnew myform();
		window->show();
		this->close();*/
		questionsflag = 0;
		maximumquestions = 15;
		checkansweronce = false;
		this->pictureBox4->Image = System::Drawing::Image::FromFile(L"Photos\\50.jpg");
		this->pictureBox4->Enabled = true;
		this->pictureBox5->Image = System::Drawing::Image::FromFile(L"Photos\\Switch.png");
		this->pictureBox5->Enabled = true;
		randomized = randomquestion();
		nextquestion();
	}

	private: System::String^ btns_clicked(System::Object^ sender)
	{
		Button^ btn = dynamic_cast<Button^>(sender); //casting the sender to button
		String^ get = btn->Text;
		return get;
	}

	private: std::wstring ToStdString(System::String^ get)
	{
		msclr::interop::marshal_context context;
		std::wstring but1string = context.marshal_as<std::wstring>(get);

		return but1string;
	}

	private: bool checkanswer(std::wstring check)
	{
		int temp = randomized[questionsflag];
		if (this->pictureBox5->Enabled == false && checkansweronce == false)
		{
		   maximumquestions++;
		   checkansweronce = true;
		}
		if (a1file[temp] == check)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	private: int* questionsarray()
	{
		int* x = new int[questionsnum];
		for (int j = 0; j < questionsnum; j++)
		{
			x[j] = j;
		}
		return x;
	}

	private: int* randomquestion()
	{
		int* p = new int[questionsnum];
		p = questionsarray();
		std::srand(time(NULL));                   //Changing the order of the randomized array ..... to not start with the same number (same order)
		std::random_shuffle(p, p + questionsnum);
		return p;
	}

	private: void revealright()
	{
		/*std::string temp = std::to_string(randombutton);
		msclr::interop::marshal_context context;
		String^ but1string = context.marshal_as<String^>(temp);
		System::Windows::Forms::MessageBox::Show(but1string);*/
		switch (randombutton)
		{
		case 0:
			this->button1->BackColor = System::Drawing::Color::Lime;
			break;
		case 1:
			this->button2->BackColor = System::Drawing::Color::Lime;
			break;
		case 2:
			this->button4->BackColor = System::Drawing::Color::Lime;
			break;
		case 3:
			this->button3->BackColor = System::Drawing::Color::Lime;
			break;
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ x = btns_clicked(sender);
		std::wstring y = ToStdString(x);
		this->button2->Enabled = false;
		this->button3->Enabled = false;
		this->button4->Enabled = false;
		if (checkanswer(y))
		{
			label2->Text = "Correct";
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->timer1->Enabled = true;
			this->timer1->Start();
		}
		else
		{
			this->button1->BackColor = System::Drawing::Color::Red;
			revealright();
			this->timer2->Enabled = true;
			this->timer2->Start();
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ x = btns_clicked(sender);
		std::wstring y = ToStdString(x);
		this->button1->Enabled = false;
		this->button3->Enabled = false;
		this->button4->Enabled = false;
		if (checkanswer(y))
		{
			label2->Text = "Correct";
			this->button2->BackColor = System::Drawing::Color::Lime;
			this->timer1->Enabled = true;
			this->timer1->Start();
		}
		else
		{
			this->button2->BackColor = System::Drawing::Color::Red;
			revealright();
			this->timer2->Enabled = true;
			this->timer2->Start();
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ x = btns_clicked(sender);
		std::wstring y = ToStdString(x);
		this->button2->Enabled = false;
		this->button1->Enabled = false;
		this->button4->Enabled = false;
		if (checkanswer(y))
		{
			label2->Text = "Correct";
			this->button3->BackColor = System::Drawing::Color::Lime;
			this->timer1->Enabled = true;
			this->timer1->Start();
		}
		else
		{
			this->button3->BackColor = System::Drawing::Color::Red;
			revealright();
			this->timer2->Enabled = true;
			this->timer2->Start();
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ x = btns_clicked(sender);
		std::wstring y = ToStdString(x);
		this->button2->Enabled = false;
		this->button3->Enabled = false;
		this->button1->Enabled = false;
		if (checkanswer(y))
		{
			label2->Text = "Correct";
			this->button4->BackColor = System::Drawing::Color::Lime;
			this->timer1->Enabled = true;
			this->timer1->Start();
		}
		else
		{
			this->button4->BackColor = System::Drawing::Color::Red;
			revealright();
			this->timer2->Enabled = true;
			this->timer2->Start();
		}
	}

    private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
    {
		this->timer1->Stop();
		this->timer1->Enabled = false;
		questionsflag++;
		nextquestion();
    }

    private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) 
    {
		this->timer2->Stop();
		this->timer2->Enabled = false;
		gameover();
    }

    private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) //50-50 choice
    {
		pictureBox4->Image = System::Drawing::Image::FromFile(L"Photos\\50X.jpg");
		pictureBox4->Enabled = false;
		switch (randombutton)
		{
		case 0:
			/*this->button2->Text = "";
			this->button3->Text = "";*/
			this->button2->Visible = false;
			this->button3->Visible = false;
			break;
		case 1:
			/*this->button1->Text = "";
			this->button4->Text = "";*/
			this->button1->Visible = false;
			this->button4->Visible = false;
			break;
		case 2:
			/*this->button1->Text = "";
			this->button3->Text = "";*/
			this->button1->Visible = false;
			this->button3->Visible = false;
			break;
		case 3:
			/*this->button2->Text = "";
			this->button4->Text = "";*/
			this->button2->Visible = false;
			this->button4->Visible = false;
			break;
		}
    }

	private: void retreat(int x)
	{
		if (x == 5 || x == 10)
		{
			if (this->pictureBox5->Enabled == false)
			{
				this->label3->Text = L"You Have " + gcnew String(money[questionsflag - 1].c_str()) + "$ want to \ncontinue or retreaing with what you have ? ";
			}
			else
			{
				this->label3->Text = L"You Have " + gcnew String(money[questionsflag].c_str()) + "$ want to \ncontinue or retreaing with what you have ? ";
			}
			this->pictureBox4->Enabled = false;
			this->pictureBox5->Enabled = false;
			this->label1->Enabled = false;
			this->button1->Enabled = false;
			this->button2->Enabled = false;
			this->button3->Enabled = false;
			this->button4->Enabled = false;
			this->button1->Visible = false;
			this->button2->Visible = false;
			this->button3->Visible = false;
			this->button4->Visible = false;
			groupBox1->Show();
		}
		else
		{
			groupBox1->Hide();
		}
	}

    private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		groupBox1->Hide();
		this->pictureBox4->Enabled = true;
		this->label1->Enabled = true;
		this->button1->Enabled = true;
		this->button2->Enabled = true;
		this->button3->Enabled = true;
		this->button4->Enabled = true;
		this->button1->Visible = true;
		this->button2->Visible = true;
		this->button3->Visible = true;
		this->button4->Visible = true;
    }

    private: System::Void label4_MouseHover(System::Object^ sender, System::EventArgs^ e) 
	{
		label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
    }


    private: System::Void label4_MouseLeave(System::Object^ sender, System::EventArgs^ e) 
	{
		this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    }

    private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e)
    {
		Won::flag = 2;
		if (this->pictureBox5->Enabled == false)
		{
			Won::amount = gcnew String(money[questionsflag - 1].c_str());
		}
		else
		{
			Won::amount = gcnew String(money[questionsflag].c_str());
		}
		gameover();
    }

    private: System::Void label5_MouseHover(System::Object^ sender, System::EventArgs^ e) 
	{
		this->label5->ForeColor = System::Drawing::Color::Red;
    }

    private: System::Void label5_MouseLeave(System::Object^ sender, System::EventArgs^ e) 
	{
		this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
    }

    private: System::Void button2_EnabledChanged(System::Object^ sender, System::EventArgs^ e) 
    {
		int temp = randomized[questionsflag];
		if (this->button2->Enabled == false)
		{
			switch (randombutton)
			{
			case 0:
				this->button2->Text = a2[temp];
				break;
			case 1:
				this->button2->Text = a1[temp];
				break;
			case 2:
				this->button2->Text = a3[temp];
				break;
			case 3:
				this->button2->Text = a3[temp];
				break;
			}
			this->button2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::buttonsPaint);
		}
    }

    private: System::Void button1_EnabledChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		int temp = randomized[questionsflag];
		if (this->button1->Enabled == false)
		{
			switch (randombutton)
			{
			case 0:
				this->button1->Text = a1[temp];
				break;
			case 1:
				this->button1->Text = a2[temp];
				break;
			case 2:
				this->button1->Text = a4[temp];
				break;
			case 3:
				this->button1->Text = a4[temp];
				break;
			}
			this->button1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::buttonsPaint);
		}
    }

    private: System::Void button3_EnabledChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		int temp = randomized[questionsflag];
		if (this->button3->Enabled == false)
		{
			switch (randombutton)
			{
			case 0:
				this->button3->Text = a3[temp];
				break;
			case 1:
				this->button3->Text = a3[temp];
				break;
			case 2:
				this->button3->Text = a2[temp];
				break;
			case 3:
				this->button3->Text = a1[temp];
				break;
			}
			this->button3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::buttonsPaint);
		}
    }

    private: System::Void button4_EnabledChanged(System::Object^ sender, System::EventArgs^ e) 
    {
		int temp = randomized[questionsflag];
		if (this->button4->Enabled == false)
		{
			switch (randombutton)
			{
			case 0:
				this->button4->Text = a4[temp];
				break;
			case 1:
				this->button4->Text = a4[temp];
				break;
			case 2:
				this->button4->Text = a1[temp];
				break;
			case 3:
				this->button4->Text = a2[temp];
				break;
			}
			this->button4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::buttonsPaint);
		}
    }

    private: System::Void buttonsPaint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
	{
		Button^ btn = dynamic_cast<Button^>(sender);
		System::Drawing::SolidBrush^ drawbrush = gcnew System::Drawing::SolidBrush(btn->ForeColor);
		TextRenderer::DrawText(e->Graphics, btn->Text, btn->Font, e->ClipRectangle, btn->ForeColor);
    }

    private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) 
    {
		pictureBox5->Image = System::Drawing::Image::FromFile(L"Photos\\SwitchX.png");
		pictureBox5->Enabled = false;
		questionsflag++;
		nextquestion();
    }
};
}

#endif