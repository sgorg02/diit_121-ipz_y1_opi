#include <string>
#include "MyForm.h"
#include "matrix.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Example_1::MyForm form;
	Application::Run(% form);
}

//Дание 
int **arr;
int size;
int max, min;

System::Void Example_1::MyForm::вихідToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	Application::Exit();
	return System::Void();
}

System::Void Example_1::MyForm::проПрограмуToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	MessageBox::Show("Завдання:\nЯкщо максимум серед елементів, що розташовані вище бічної діагоналі квадратної  матриці  А,  менше  за  мінімум  серед  елементів,  що розташовані  нижче  головної  діагоналі,  то  транспонуйте  матрицю, інакше знайдіть А2.","Інформація про програму");
	return System::Void();
}

System::Void Example_1::MyForm::buttonRandom_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (size == 0) {
		MessageBox::Show("Мітриця відсутня","Увага!");
		return;
	}

	FillingArray(arr, size);
	Show();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//ячейки
	dataGridView1->AutoResizeColumns();
	return System::Void();
}

System::Void Example_1::MyForm::buttonCreate_Click(System::Object ^ sender, System::EventArgs ^ e) {
	size = Convert::ToInt32(numericUpDownSize->Value);

	arr = new int*[size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = 0;
	
	//Создаем таблицу
	dataGridView1->RowCount = size;
	dataGridView1->ColumnCount = size;
	Show();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//ячейки
	dataGridView1->AutoResizeColumns();

	return System::Void();
}

System::Void Example_1::MyForm::buttonReading_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (textBoxReading->Text == "") {
		MessageBox::Show("Введіть назву файла!","Увага!");
		return;
	}
	//Зчитуемо назву файла
	std::string filename;
	Convert_String_to_string(textBoxReading->Text, filename);

	//Зчитуемо дані з файла
	ReadingMatrix(arr, size, filename);
	//Создаем таблицу
	dataGridView1->RowCount = size;
	dataGridView1->ColumnCount = size;
	Show();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//ячейки
	dataGridView1->AutoResizeColumns();

	return System::Void();
}

System::Void Example_1::MyForm::numericUpDownSize_ValueChanged(System::Object ^ sender, System::EventArgs ^ e) {
	return System::Void();
}

void Example_1::MyForm::Show() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//назавние таблицы в верхнем углду
			dataGridView1->TopLeftHeaderCell->Value = "Матриці А";

			//вывод номеров строк
			dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//вывод номеров столбцов
			dataGridView1->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//вывод значение матрицы
			dataGridView1->Rows[i]->Cells[j]->Value = arr[i][j];
		}
	}
}

void Example_1::MyForm::ShowResult(int **res) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//назавние таблицы в верхнем углду
			dataGridViewResult->TopLeftHeaderCell->Value = "Матриці B";

			//вывод номеров строк
			dataGridViewResult->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//вывод номеров столбцов
			dataGridViewResult->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//вывод значение матрицы
			dataGridViewResult->Rows[i]->Cells[j]->Value = res[i][j];
		}
	}
}

System::Void Example_1::MyForm::buttonActions_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (size == 0) {
		MessageBox::Show("Мітриця відсутня", "Увага!");
		return;
	}
	int **result;
	min = FindingMin(arr, size);//знаходження мінімального числа по завданю
	max = FindingMax(arr, size);//знаходження максимального числа по завданю

	if (max < min) {//Так як максимальне число меньше мінімального, то ми транспонуємо матрицю
		MessageBox::Show("Так як максимальне число меньше мінімального, то ми транспонуємо матрицю","По завданю!");
		result = TransposeArray(arr, size);
	}
	else {//Так як максимальне число більше мінімального, то ми матрицю підносимо у квадрат
		MessageBox::Show("Так як максимальне число більше мінімального, то ми матрицю підносимо у квадрат", "По завданю!");
		result = SquareArray(arr, size);
	}
	
	//Создаем таблицу
	dataGridViewResult->RowCount = size;
	dataGridViewResult->ColumnCount = size;
	ShowResult(result);
	dataGridViewResult->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//ячейки
	dataGridViewResult->AutoResizeColumns();


	return System::Void();
}
