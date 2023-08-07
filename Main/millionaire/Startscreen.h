#pragma once
#ifndef STARTSCREEN_H
#define STARTSCREEN_H


#include "MyForm.h"
#include "HelpScreen.h"

namespace millionaire {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Startscreen
	/// </summary>
	public ref class Startscreen : public System::Windows::Forms::Form
	{
	
	public:
		Startscreen(void)
		{
			InitializeComponent();
			/*if (millionaire::MyForm::closed == true)
			{
				MyForm^ window = gcnew MyForm();
				window->Show();
			}*/
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Startscreen()
		{
			if (MyForm::closed == false)
			{
				Application::Exit();
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;



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
			System::Windows::Forms::Label^ label1;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Startscreen::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			label1->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			label1->Location = System::Drawing::Point(12, 197);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(371, 75);
			label1->TabIndex = 2;
			label1->Text = L"                             Welcome to\n              who wants to be a millionai"
				L"re\n                          pheonix edition! ";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->button1->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(134, 295);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 71);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Startscreen::loadgame);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(146, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(145, 130);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::MenuBar;
			this->button2->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(134, 395);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(175, 71);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Help";
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Startscreen::button2_Click);
			// 
			// Startscreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowText;
			this->ClientSize = System::Drawing::Size(434, 561);
			this->Controls->Add(this->button2);
			this->Controls->Add(label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Startscreen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Pheonix";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void loadgame(System::Object^ sender, System::EventArgs^ e) //when pressing start to load the game
	{
		MyForm^ window = gcnew MyForm(); 
		//window->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		//window->WindowState = System::Windows::Forms::FormWindowState::Maximized;
		//window->TopMost = true;
		window->Show();
		//millionaire::Startscreen::~Startscreen();          //closes the main screen
		this->Close();
	}

    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
    {
		HelpScreen^ window = gcnew HelpScreen(this);
		window->Show();
		this->Hide();
    }
};
}


#endif // !STARTSCREEN_H