#pragma once
#include <iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "..\Queue\Queue.h"


namespace simulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int MaxSize, Size,PopCount,PushCount;
		double p=0,q=0;
		::Queue<int>* pQueue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rnd1;
		Pen^ BlackPen;
		Pen^ WhitePen;
	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = CreateGraphics();//this->
			rnd1 = gcnew Random();
			BlackPen = gcnew Pen(Color::Black);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::Control);
			WhitePen->Width = 10.0F;
			CenterX = 100;
			CenterY = 180;
			Width = Height = 200;
			PopCount = PushCount = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(475, 92);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(475, 156);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(266, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(266, 78);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 26);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(266, 110);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(138, 26);
			this->textBox3->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(266, 142);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(138, 26);
			this->textBox4->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(243, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Максимальная длина очереди";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(57, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(203, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Исходная длина очереди";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(54, 113);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(206, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Вероятность добавления";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(57, 145);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(203, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Вероятность извлечения";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(84, 178);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(176, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Добавлено в очередь";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(266, 175);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(138, 26);
			this->textBox5->TabIndex = 11;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(266, 207);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(138, 26);
			this->textBox6->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(78, 210);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(182, 20);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Извлечено из очереди";
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(603, 597);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox2->Text);
		p = Convert::ToDouble(textBox3->Text);
		q = Convert::ToDouble(textBox4->Text);
		pQueue = new ::Queue<int>(MaxSize);
		for(int i=0;i<Size;i++)
		{
			pQueue->push(i);
		}
		DrawQueue();
		timer1->Enabled = true;
	}
		   void DrawQueue() 
		   {
			   int start = 360 * pQueue->front() / pQueue->GetMaxSize();
			   int finish = 360 * (pQueue->GetSize()) / pQueue->GetMaxSize();
			   gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
		   }
		   void Clean() 
		   {
			   gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, 0, 360);
		   }
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	Clean();
	if(rnd1->NextDouble()<p)
	{
		pQueue->push(1);
		Size++;
		PushCount++;
	}
	if(rnd1->NextDouble()<q)
	{
		int pq=pQueue->pop();
		Size--;
		PopCount++;
	}
	DrawQueue();
	textBox5->Text = Convert::ToString(PushCount);
	textBox6->Text = Convert::ToString(PopCount);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;;
}
};
}
