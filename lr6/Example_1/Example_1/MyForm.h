#pragma once

namespace Example_1 {

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
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  вихідToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  проПрограмуToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownSize;




	private: System::Windows::Forms::Button^  buttonCreate;


	private: System::Windows::Forms::Button^  buttonRandom;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::DataGridView^  dataGridViewResult;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonReading;
	private: System::Windows::Forms::TextBox^  textBoxReading;

	private: System::Windows::Forms::Button^  buttonActions;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;








	private: System::ComponentModel::IContainer^  components;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вихідToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->проПрограмуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->numericUpDownSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonCreate = (gcnew System::Windows::Forms::Button());
			this->buttonRandom = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridViewResult = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonReading = (gcnew System::Windows::Forms::Button());
			this->textBoxReading = (gcnew System::Windows::Forms::TextBox());
			this->buttonActions = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSize))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewResult))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->вихідToolStripMenuItem,
					this->проПрограмуToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(667, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вихідToolStripMenuItem
			// 
			this->вихідToolStripMenuItem->Name = L"вихідToolStripMenuItem";
			this->вихідToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->вихідToolStripMenuItem->Text = L"Вихід";
			this->вихідToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::вихідToolStripMenuItem_Click);
			// 
			// проПрограмуToolStripMenuItem
			// 
			this->проПрограмуToolStripMenuItem->Name = L"проПрограмуToolStripMenuItem";
			this->проПрограмуToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->проПрограмуToolStripMenuItem->Text = L"Про програму";
			this->проПрограмуToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::проПрограмуToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(97, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Матриця A:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(6, 33);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(240, 150);
			this->dataGridView1->TabIndex = 3;
			// 
			// numericUpDownSize
			// 
			this->numericUpDownSize->Location = System::Drawing::Point(100, 189);
			this->numericUpDownSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSize->Name = L"numericUpDownSize";
			this->numericUpDownSize->Size = System::Drawing::Size(41, 20);
			this->numericUpDownSize->TabIndex = 4;
			this->numericUpDownSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSize->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownSize_ValueChanged);
			// 
			// buttonCreate
			// 
			this->buttonCreate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCreate->Location = System::Drawing::Point(171, 217);
			this->buttonCreate->Name = L"buttonCreate";
			this->buttonCreate->Size = System::Drawing::Size(75, 23);
			this->buttonCreate->TabIndex = 6;
			this->buttonCreate->Text = L"Створити";
			this->buttonCreate->UseVisualStyleBackColor = true;
			this->buttonCreate->Click += gcnew System::EventHandler(this, &MyForm::buttonCreate_Click);
			// 
			// buttonRandom
			// 
			this->buttonRandom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRandom->Location = System::Drawing::Point(6, 217);
			this->buttonRandom->Name = L"buttonRandom";
			this->buttonRandom->Size = System::Drawing::Size(97, 23);
			this->buttonRandom->TabIndex = 7;
			this->buttonRandom->Text = L"Сгенерувати";
			this->buttonRandom->UseVisualStyleBackColor = true;
			this->buttonRandom->Click += gcnew System::EventHandler(this, &MyForm::buttonRandom_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Controls->Add(this->buttonRandom);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->buttonCreate);
			this->groupBox1->Controls->Add(this->numericUpDownSize);
			this->groupBox1->Location = System::Drawing::Point(24, 60);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(256, 259);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Матриця А";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridViewResult);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(360, 60);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(256, 195);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Матриця В";
			// 
			// dataGridViewResult
			// 
			this->dataGridViewResult->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewResult->Location = System::Drawing::Point(10, 35);
			this->dataGridViewResult->Name = L"dataGridViewResult";
			this->dataGridViewResult->Size = System::Drawing::Size(240, 150);
			this->dataGridViewResult->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(97, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Матриця B:";
			// 
			// buttonReading
			// 
			this->buttonReading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonReading->Location = System::Drawing::Point(24, 338);
			this->buttonReading->Name = L"buttonReading";
			this->buttonReading->Size = System::Drawing::Size(126, 23);
			this->buttonReading->TabIndex = 10;
			this->buttonReading->Text = L"Зчитати з файла";
			this->buttonReading->UseVisualStyleBackColor = true;
			this->buttonReading->Click += gcnew System::EventHandler(this, &MyForm::buttonReading_Click);
			// 
			// textBoxReading
			// 
			this->textBoxReading->Location = System::Drawing::Point(156, 341);
			this->textBoxReading->Name = L"textBoxReading";
			this->textBoxReading->Size = System::Drawing::Size(125, 20);
			this->textBoxReading->TabIndex = 11;
			// 
			// buttonActions
			// 
			this->buttonActions->Location = System::Drawing::Point(303, 151);
			this->buttonActions->Name = L"buttonActions";
			this->buttonActions->Size = System::Drawing::Size(35, 23);
			this->buttonActions->TabIndex = 13;
			this->buttonActions->Text = L"=";
			this->buttonActions->UseVisualStyleBackColor = true;
			this->buttonActions->Click += gcnew System::EventHandler(this, &MyForm::buttonActions_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(667, 392);
			this->Controls->Add(this->buttonActions);
			this->Controls->Add(this->textBoxReading);
			this->Controls->Add(this->buttonReading);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Matrix";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSize))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewResult))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void вихідToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void проПрограмуToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonRandom_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonCreate_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void buttonReading_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void numericUpDownSize_ValueChanged(System::Object^  sender, System::EventArgs^  e);
	private: void Show();
	private: void ShowResult(int **res);
private: System::Void buttonActions_Click(System::Object^  sender, System::EventArgs^  e);
};
}
