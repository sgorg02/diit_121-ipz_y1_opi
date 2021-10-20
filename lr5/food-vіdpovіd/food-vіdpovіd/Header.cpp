#include <iostream>
#include <random>
#include "Header.h"


int input_size() {
	system("cls");
	int size;
	while (true) {
		std::cout << "Введіть розмір матриці: ";
		std::cin >> size;
		if ((std::cin.peek() != '\n') || !(size > 1)) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "На жаль, цей введення неправильне. Розмір масива повинен бути більше за 1. Повторіть знову." << std::endl;
		}
		else
			return size;
	}
}

int** New2DArray(const int size) {//створення масива
	int** Arr = new int*[size];
	for (int i = 0; i < size; ++i)
		Arr[i] = new int[size];
	return Arr;
}

void Delete2DArray(int** Arr, const int size) {//видилення масива
	for (int i = 0; i < size; ++i)
		delete[] Arr[i];
	delete[] Arr;
}

void PrintArray(int** arr, const int size) {//друк масива
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void FillingArray(int **arr, const int size) {//заповнення масива випадковими числами
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 10);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = dis(gen);
}

int FindingMax(int **arr, const int size) {//знаходження максимального числа
	int max, m = 1;
	max = arr[0][0];
	for (int i = 0; i < size - 1; i++, m++)
		for (int j = 0; j < size - m; j++)
			if (arr[i][j] > max)
				max = arr[i][j];

	return max;
}

int FindingMin(int **arr, const int size) {//знаходження мінімального числа
	int min, m = 1;
	min = arr[1][0];
	for (int i = 1; i < size - 1; i++, m++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] < min)
				min = arr[i][j];

	return min;
}

int** NewTransposeArray(int **arr, const int size) {//транспортування матриці
	int** res = New2DArray(size);

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res[j][i] = arr[i][j];

	return res;
}

void SquareArray(int **arr, const int size) {//матриця в квадраті
	int **temp = New2DArray(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			temp[i][j] = 0;


	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			for (int k = 0; k < size; k++)
				temp[i][j] += arr[i][k] * arr[k][j];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = temp[i][j];
			temp[i][j] = 0;
		}
	}
}