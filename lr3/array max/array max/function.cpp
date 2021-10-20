#include <iostream>
#include <random>
#include "function.h"


int** New2DArray(const int rows, const int cols)//створення масива
{
	int** Arr = new int*[rows];
	for (int i = 0; i < rows; ++i)
		Arr[i] = new int[cols];
	return Arr;
}
void Delete2DArray(int** arr, const int rows)//видилення масива
{
	for (int i = 0; i < rows; ++i)
		delete[] arr[i];
	delete[] arr;
}
void PrintArray(int** arr, int rows, int cols)//друк масива
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
void FillingArray(int **arr, int rows, int cols)//заповнення масива випадковими числами
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 100);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = dis(gen);

}

int FindingMax(int **arr, matrix Arr)//знаходження максимального числа
{
	Arr.max = arr[0][0];
	for (int i = 0; i < Arr.rows; i++)
		for (int j = 0; j < Arr.cols; j++)
			if (arr[i][j] > Arr.max)
				Arr.max = arr[i][j];
	return Arr.max;
}

int InputCheck(char choice) {//перевірка чисел
	int ArrayParameters;
	while (true) {
		if (choice == 'r')
			std::cout << "Введіть кількість рядків: ";
		else
			std::cout << "Введіть кількість стовпців: ";

		std::cin >> ArrayParameters;
		if ((std::cin.peek() != '\n') || !(ArrayParameters > 0)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "На жаль, цей введення неправильне. Число повино бути більше за 0. Повторіть знову." << std::endl;
		}
		else
			return ArrayParameters;
	}
}

void MixingElements(int **arr, matrix Arr) {//переміщення елементів вліво на одну позицію 
	int temp;
	temp = arr[0][0];
	for (int i = 0; i < Arr.rows; i++) {
		for (int j = 0; j < Arr.cols; j++) {
			arr[i][j] = arr[i][j + 1];
		}
		if (i != Arr.rows - 1)
			arr[i][Arr.cols - 1] = arr[i + 1][0];
	}
	arr[Arr.rows - 1][Arr.cols - 1] = temp;
}