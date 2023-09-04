	#pragma once
#include "smallapi.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class WinForm : public System::Windows::Forms::Form
	{
	public:
		WinForm(void)
		{
			InitializeComponent(); 
			api = new SmallApi();
		}

	protected:
		~WinForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ load_button;
	protected:

	private: System::Windows::Forms::Button^ save_button;
	protected:

	private: System::Windows::Forms::Button^ add_button;

	private: System::Windows::Forms::TextBox^ NameBox;
	private: System::Windows::Forms::TextBox^ XBox;
	private: System::Windows::Forms::TextBox^ YBox;
	private: System::Windows::Forms::TextBox^ TypeBox;
	private: System::Windows::Forms::TextBox^ TimeBox;
	private: System::Windows::Forms::TextBox^ TextBox;
	private: System::Windows::Forms::TextBox^ Unsorted_list;


	private: System::Windows::Forms::Button^ clear;
	private: System::Windows::Forms::TextBox^ IntervalBox1;
	private: System::Windows::Forms::TextBox^ intervalBox2;




	private: System::Windows::Forms::TextBox^ intervalBox6;
	private: System::Windows::Forms::TextBox^ intervalBox3;
	private: System::Windows::Forms::TextBox^ intervalBox4;
	private: System::Windows::Forms::TextBox^ intervalBox5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;





	private:
		System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->load_button = (gcnew System::Windows::Forms::Button());
			this->save_button = (gcnew System::Windows::Forms::Button());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->TextBox = (gcnew System::Windows::Forms::TextBox());
			this->NameBox = (gcnew System::Windows::Forms::TextBox());
			this->XBox = (gcnew System::Windows::Forms::TextBox());
			this->YBox = (gcnew System::Windows::Forms::TextBox());
			this->TypeBox = (gcnew System::Windows::Forms::TextBox());
			this->TimeBox = (gcnew System::Windows::Forms::TextBox());
			this->Unsorted_list = (gcnew System::Windows::Forms::TextBox());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->IntervalBox1 = (gcnew System::Windows::Forms::TextBox());
			this->intervalBox2 = (gcnew System::Windows::Forms::TextBox());
			this->intervalBox6 = (gcnew System::Windows::Forms::TextBox());
			this->intervalBox3 = (gcnew System::Windows::Forms::TextBox());
			this->intervalBox4 = (gcnew System::Windows::Forms::TextBox());
			this->intervalBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// load_button
			// 
			this->load_button->Location = System::Drawing::Point(820, 280);
			this->load_button->Name = L"load_button";
			this->load_button->Size = System::Drawing::Size(75, 23);
			this->load_button->TabIndex = 0;
			this->load_button->Text = L"load file";
			this->load_button->UseVisualStyleBackColor = true;
			this->load_button->Click += gcnew System::EventHandler(this, &WinForm::Load_Click);
			// 
			// save_button
			// 
			this->save_button->Location = System::Drawing::Point(820, 312);
			this->save_button->Name = L"save_button";
			this->save_button->Size = System::Drawing::Size(75, 35);
			this->save_button->TabIndex = 1;
			this->save_button->Text = L"save";
			this->save_button->UseVisualStyleBackColor = true;
			this->save_button->Click += gcnew System::EventHandler(this, &WinForm::Save_Click);
			// 
			// add_button
			// 
			this->add_button->Location = System::Drawing::Point(817, 29);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(75, 23);
			this->add_button->TabIndex = 2;
			this->add_button->Text = L"add";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &WinForm::Add_Click);
			// 
			// TextBox
			// 
			this->TextBox->Location = System::Drawing::Point(290, 81);
			this->TextBox->Multiline = true;
			this->TextBox->Name = L"TextBox";
			this->TextBox->ReadOnly = true;
			this->TextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->TextBox->Size = System::Drawing::Size(524, 300);
			this->TextBox->TabIndex = 3;
			// 
			// NameBox
			// 
			this->NameBox->Location = System::Drawing::Point(289, 32);
			this->NameBox->Name = L"NameBox";
			this->NameBox->Size = System::Drawing::Size(100, 20);
			this->NameBox->TabIndex = 4;
			// 
			// XBox
			// 
			this->XBox->Location = System::Drawing::Point(395, 32);
			this->XBox->Name = L"XBox";
			this->XBox->Size = System::Drawing::Size(100, 20);
			this->XBox->TabIndex = 5;
			// 
			// YBox
			// 
			this->YBox->Location = System::Drawing::Point(501, 32);
			this->YBox->Name = L"YBox";
			this->YBox->Size = System::Drawing::Size(100, 20);
			this->YBox->TabIndex = 6;
			// 
			// TypeBox
			// 
			this->TypeBox->Location = System::Drawing::Point(607, 32);
			this->TypeBox->Name = L"TypeBox";
			this->TypeBox->Size = System::Drawing::Size(100, 20);
			this->TypeBox->TabIndex = 7;
			// 
			// TimeBox
			// 
			this->TimeBox->Location = System::Drawing::Point(713, 32);
			this->TimeBox->Name = L"TimeBox";
			this->TimeBox->Size = System::Drawing::Size(100, 20);
			this->TimeBox->TabIndex = 8;
			// 
			// Unsorted_list
			// 
			this->Unsorted_list->Location = System::Drawing::Point(12, 41);
			this->Unsorted_list->Multiline = true;
			this->Unsorted_list->Name = L"Unsorted_list";
			this->Unsorted_list->ReadOnly = true;
			this->Unsorted_list->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Unsorted_list->Size = System::Drawing::Size(264, 170);
			this->Unsorted_list->TabIndex = 9;
			// 
			// clear
			// 
			this->clear->Location = System::Drawing::Point(201, 217);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(75, 23);
			this->clear->TabIndex = 10;
			this->clear->Text = L"clear";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &WinForm::Clear_Click);
			// 
			// IntervalBox1
			// 
			this->IntervalBox1->Location = System::Drawing::Point(12, 256);
			this->IntervalBox1->Name = L"IntervalBox1";
			this->IntervalBox1->ReadOnly = true;
			this->IntervalBox1->Size = System::Drawing::Size(17, 20);
			this->IntervalBox1->TabIndex = 11;
			this->IntervalBox1->Text = L"0";
			this->IntervalBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// intervalBox2
			// 
			this->intervalBox2->Location = System::Drawing::Point(35, 256);
			this->intervalBox2->Name = L"intervalBox2";
			this->intervalBox2->Size = System::Drawing::Size(49, 20);
			this->intervalBox2->TabIndex = 15;
			this->intervalBox2->Text = L"10";
			this->intervalBox2->TextChanged += gcnew System::EventHandler(this, &WinForm::intervalBox2_TextChanged);
			// 
			// intervalBox6
			// 
			this->intervalBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9));
			this->intervalBox6->Location = System::Drawing::Point(255, 253);
			this->intervalBox6->Name = L"intervalBox6";
			this->intervalBox6->ReadOnly = true;
			this->intervalBox6->Size = System::Drawing::Size(21, 23);
			this->intervalBox6->TabIndex = 16;
			this->intervalBox6->Text = L"∞";
			this->intervalBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// intervalBox3
			// 
			this->intervalBox3->Location = System::Drawing::Point(90, 256);
			this->intervalBox3->Name = L"intervalBox3";
			this->intervalBox3->Size = System::Drawing::Size(49, 20);
			this->intervalBox3->TabIndex = 17;
			this->intervalBox3->Text = L"100";
			this->intervalBox3->TextChanged += gcnew System::EventHandler(this, &WinForm::intervalBox3_TextChanged);
			// 
			// intervalBox4
			// 
			this->intervalBox4->Location = System::Drawing::Point(145, 256);
			this->intervalBox4->Name = L"intervalBox4";
			this->intervalBox4->Size = System::Drawing::Size(49, 20);
			this->intervalBox4->TabIndex = 18;
			this->intervalBox4->Text = L"1000";
			this->intervalBox4->TextChanged += gcnew System::EventHandler(this, &WinForm::intervalBox4_TextChanged);
			// 
			// intervalBox5
			// 
			this->intervalBox5->Location = System::Drawing::Point(200, 256);
			this->intervalBox5->Name = L"intervalBox5";
			this->intervalBox5->Size = System::Drawing::Size(49, 20);
			this->intervalBox5->TabIndex = 19;
			this->intervalBox5->Text = L"10000";
			this->intervalBox5->TextChanged += gcnew System::EventHandler(this, &WinForm::intervalBox5_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(200, 301);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(28, 20);
			this->textBox5->TabIndex = 25;
			this->textBox5->Text = L"10";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &WinForm::textBox5_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(145, 301);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(25, 20);
			this->textBox4->TabIndex = 24;
			this->textBox4->Text = L"12";
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &WinForm::textBox4_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(90, 301);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(24, 20);
			this->textBox3->TabIndex = 23;
			this->textBox3->Text = L"30";
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &WinForm::textBox3_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9));
			this->textBox6->Location = System::Drawing::Point(255, 298);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(21, 23);
			this->textBox6->TabIndex = 22;
			this->textBox6->Text = L"∞";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(35, 301);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(28, 20);
			this->textBox2->TabIndex = 21;
			this->textBox2->Text = L"24";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &WinForm::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 301);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(17, 20);
			this->textBox1->TabIndex = 20;
			this->textBox1->Text = L"0";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(12, 342);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(49, 20);
			this->textBox7->TabIndex = 26;
			this->textBox7->Text = L"0";
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &WinForm::textBox7_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 240);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 13);
			this->label1->TabIndex = 27;
			this->label1->Text = L"distance limits";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 283);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 28;
			this->label2->Text = L"time limits";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(67, 345);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 29;
			this->label3->Text = L"type limit";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 30;
			this->label4->Text = L"object list";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(287, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 31;
			this->label5->Text = L"result";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(67, 304);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(16, 13);
			this->label6->TabIndex = 32;
			this->label6->Text = L"hr";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(120, 304);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 13);
			this->label7->TabIndex = 33;
			this->label7->Text = L"ds";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(170, 304);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 13);
			this->label8->TabIndex = 34;
			this->label8->Text = L"mth";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(233, 304);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(15, 13);
			this->label9->TabIndex = 35;
			this->label9->Text = L"yr";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(287, 16);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(33, 13);
			this->label10->TabIndex = 36;
			this->label10->Text = L"name";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(392, 16);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(12, 13);
			this->label11->TabIndex = 37;
			this->label11->Text = L"x";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(498, 16);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(12, 13);
			this->label12->TabIndex = 38;
			this->label12->Text = L"y";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(604, 16);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(27, 13);
			this->label13->TabIndex = 39;
			this->label13->Text = L"type";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(710, 16);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(26, 13);
			this->label14->TabIndex = 40;
			this->label14->Text = L"time";
			// 
			// WinForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(913, 403);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->intervalBox5);
			this->Controls->Add(this->intervalBox4);
			this->Controls->Add(this->intervalBox3);
			this->Controls->Add(this->intervalBox6);
			this->Controls->Add(this->intervalBox2);
			this->Controls->Add(this->IntervalBox1);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->Unsorted_list);
			this->Controls->Add(this->TimeBox);
			this->Controls->Add(this->TypeBox);
			this->Controls->Add(this->YBox);
			this->Controls->Add(this->XBox);
			this->Controls->Add(this->NameBox);
			this->Controls->Add(this->TextBox);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->save_button);
			this->Controls->Add(this->load_button);
			this->Name = L"WinForm";
			this->Text = L"WinForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Load_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Clear_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void intervalBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void intervalBox3_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void intervalBox4_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void intervalBox5_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e);

	//Utils
	std::string convert(System::String^ convertable);
	System::String^ convert(std::string convertable);
private: 
	SmallApi* api;
};

