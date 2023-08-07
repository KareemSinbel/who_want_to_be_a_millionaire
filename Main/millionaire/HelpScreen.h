#pragma once

namespace millionaire {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HelpScreen
	/// </summary>
	public ref class HelpScreen : public System::Windows::Forms::Form
	{
	public:
		HelpScreen(System::Windows::Forms::Form^ temp)
		{
			Start_Screen = temp;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HelpScreen()
		{
			Start_Screen->Show();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form^ Start_Screen;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;

	protected:

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
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ label2;
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::Label^ label4;
			System::Windows::Forms::Label^ label5;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(HelpScreen::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			label1 = (gcnew System::Windows::Forms::Label());
			label2 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			label4 = (gcnew System::Windows::Forms::Label());
			label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			label1->AutoSize = true;
			label1->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			label1->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			label1->Location = System::Drawing::Point(12, 79);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(410, 50);
			label1->TabIndex = 3;
			label1->Text = L"  Can be used only one time and gives you\n          a chance to change the questi"
				L"on";
			// 
			// label2
			// 
			label2->AutoSize = true;
			label2->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			label2->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			label2->Location = System::Drawing::Point(12, 209);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(410, 50);
			label2->TabIndex = 25;
			label2->Text = L"  Can be used only one time and gives you\n     a chance to remove 2 Wrong answers"
				L"";
			// 
			// label3
			// 
			label3->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			label3->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			label3->Location = System::Drawing::Point(12, 280);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(410, 121);
			label3->TabIndex = 26;
			label3->Text = L"  at question 5 and question 10 you have\n   the ability to retreat and get what y"
				L"ou\n      have of money but if you continued\n          and lost you will get noth"
				L"ing";
			// 
			// label4
			// 
			label4->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			label4->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			label4->Location = System::Drawing::Point(12, 384);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(410, 109);
			label4->TabIndex = 27;
			label4->Text = L" The right answer will be highlited with\n   a green color but if you got a red co"
				L"lor\n      then means you picked the wrong\n            answer .. Hope you have fu"
				L"n !";
			// 
			// label5
			// 
			label5->Font = (gcnew System::Drawing::Font(L"Cambria", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			label5->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			label5->Location = System::Drawing::Point(12, 483);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(410, 27);
			label5->TabIndex = 28;
			label5->Text = L"                                     ♥";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(2, 513);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(104, 47);
			this->button1->TabIndex = 4;
			this->button1->Text = L"<-- Back";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &HelpScreen::button1_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(156, 12);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(106, 64);
			this->pictureBox5->TabIndex = 23;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(156, 142);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(106, 64);
			this->pictureBox4->TabIndex = 24;
			this->pictureBox4->TabStop = false;
			// 
			// HelpScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(434, 561);
			this->Controls->Add(label5);
			this->Controls->Add(label4);
			this->Controls->Add(label3);
			this->Controls->Add(label2);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->button1);
			this->Controls->Add(label1);
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"HelpScreen";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Help";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	};
}
