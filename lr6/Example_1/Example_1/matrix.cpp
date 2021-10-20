#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include "matrix.h"

using namespace System;
using namespace System::Windows::Forms;

int** New2DArray(const int size) {//створення масива
	int** Arr = new int*[size];
	for (int i = 0; i < size; ++i)
		Arr[i] = new int[size];
	return Arr;
}

void FillingArray(int **arr, const int size) {//заповнення масива випадковими числами
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 10);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = dis(gen);
		}
	}
}

int FindingMax(int **arr, const int size) {//знаходження максимального числа
	int max, m = 1;
	max = arr[0][0];
	for (int i = 0; i < size - 1; i++, m++)
	{
		for (int j = 0; j < size - m; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}

	return max;
}

int FindingMin(int **arr, const int size) {//знаходження мінімального числа
	int min, m = 1;
	min = arr[1][0];
	for (int i = 1; i < size - 1; i++, m++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}
		}
	}

	return min;
}

int** TransposeArray(int **arr, const int size) {//транспортування матриці
	int** res = New2DArray(size);

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[j][i] = arr[i][j];
	return res;
}


int** SquareArray(int **arr, const int size) {//матриця в квадраті
	int **temp = New2DArray(size);
	
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			temp[i][j] = 0;


	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
				temp[i][j] += arr[i][k] * arr[k][j];

	return temp;
}

void ReadingMatrix(int **(&arr), int &size, std::string filename) {//читання даних з файла
	std::ifstream reading(filename);

	if (reading) {
		//зчитуємо розмірність матриці
		reading >> size;

		//Виділяємо память під матрицю
		arr = new int*[size];
		for (int i = 0; i < size; i++)
			arr[i] = new int[size];

		//Хчитуємо матрицю
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				reading >> arr[i][j];
	}
	else
		MessageBox::Show("Ошибка відкритя файла!","Ошибка!");
	reading.close();
}

std::string& Convert_String_to_string(String^ s, std::string &os) {
	using namespace Runtime::InteropServices;
	const char *chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

String^ Convert_string_to_String(std::string &os, String^ s) {
	s = gcnew System::String(os.c_str());

	return s;
}
