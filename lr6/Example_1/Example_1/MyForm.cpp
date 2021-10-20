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

//����� 
int **arr;
int size;
int max, min;

System::Void Example_1::MyForm::�����ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	Application::Exit();
	return System::Void();
}

System::Void Example_1::MyForm::�����������ToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	MessageBox::Show("��������:\n���� �������� ����� ��������, �� ���������� ���� ���� ������� ���������  �������  �,  �����  ��  �����  �����  ��������,  �� ����������  �����  �������  �������,  ��  ������������  �������, ������ ������� �2.","���������� ��� ��������");
	return System::Void();
}

System::Void Example_1::MyForm::buttonRandom_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (size == 0) {
		MessageBox::Show("̳����� �������","�����!");
		return;
	}

	FillingArray(arr, size);
	Show();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
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
	
	//������� �������
	dataGridView1->RowCount = size;
	dataGridView1->ColumnCount = size;
	Show();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
	dataGridView1->AutoResizeColumns();

	return System::Void();
}

System::Void Example_1::MyForm::buttonReading_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (textBoxReading->Text == "") {
		MessageBox::Show("������ ����� �����!","�����!");
		return;
	}
	//�������� ����� �����
	std::string filename;
	Convert_String_to_string(textBoxReading->Text, filename);

	//�������� ��� � �����
	ReadingMatrix(arr, size, filename);
	//������� �������
	dataGridView1->RowCount = size;
	dataGridView1->ColumnCount = size;
	Show();
	dataGridView1->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
	dataGridView1->AutoResizeColumns();

	return System::Void();
}

System::Void Example_1::MyForm::numericUpDownSize_ValueChanged(System::Object ^ sender, System::EventArgs ^ e) {
	return System::Void();
}

void Example_1::MyForm::Show() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//�������� ������� � ������� �����
			dataGridView1->TopLeftHeaderCell->Value = "������� �";

			//����� ������� �����
			dataGridView1->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//����� ������� ��������
			dataGridView1->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//����� �������� �������
			dataGridView1->Rows[i]->Cells[j]->Value = arr[i][j];
		}
	}
}

void Example_1::MyForm::ShowResult(int **res) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//�������� ������� � ������� �����
			dataGridViewResult->TopLeftHeaderCell->Value = "������� B";

			//����� ������� �����
			dataGridViewResult->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			//����� ������� ��������
			dataGridViewResult->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			//����� �������� �������
			dataGridViewResult->Rows[i]->Cells[j]->Value = res[i][j];
		}
	}
}

System::Void Example_1::MyForm::buttonActions_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (size == 0) {
		MessageBox::Show("̳����� �������", "�����!");
		return;
	}
	int **result;
	min = FindingMin(arr, size);//����������� ���������� ����� �� �������
	max = FindingMax(arr, size);//����������� ������������� ����� �� �������

	if (max < min) {//��� �� ����������� ����� ������ ����������, �� �� ����������� �������
		MessageBox::Show("��� �� ����������� ����� ������ ����������, �� �� ����������� �������","�� �������!");
		result = TransposeArray(arr, size);
	}
	else {//��� �� ����������� ����� ����� ����������, �� �� ������� �������� � �������
		MessageBox::Show("��� �� ����������� ����� ����� ����������, �� �� ������� �������� � �������", "�� �������!");
		result = SquareArray(arr, size);
	}
	
	//������� �������
	dataGridViewResult->RowCount = size;
	dataGridViewResult->ColumnCount = size;
	ShowResult(result);
	dataGridViewResult->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);//������
	dataGridViewResult->AutoResizeColumns();


	return System::Void();
}
