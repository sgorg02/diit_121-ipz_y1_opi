#include <iostream>
#include <random>
#include "FileWork.h"
#include "Matrix.h"
#include "Interface.h"

Matrix::Matrix(int new_rows, int new_cols) {
	rows = new_rows;
	cols = new_cols;
	arr = new int*[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];
}

Matrix::~Matrix() {
	delete[] arr;
}

void Matrix::Setij(int i, int j, int el) {
	arr[i][j] = el;
}

int** Matrix::getMatrix() {
	return arr;
}

void Matrix::FillByUser() {//заповнення масива з клавіатури
	for (int i = 0; i < rows; i++)//заповнення масива нулями
		for (int j = 0; j < cols; j++)
			arr[i][j] = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::system("cls");
			output_matrix();
			std::cout << "arr[" << i + 1 << "][" << j + 1 << "] = ";
			std::cin >> arr[i][j];
		}
	}
	system("cls");
}
void Matrix::FillByRandom() {//заповнення масива випрадковими числами
	int Lb, Rb;
	Lb = Interface::left_border();
	Rb = Interface::right_border();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(Lb, Rb);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = dis(gen);
	system("cls");
}
void Matrix::output_matrix() {//друк масива
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}
int Matrix::FindingTheMax_Min() {//функция знаходження мінімального числа
	int max, m = 1;
	max = arr[0][0];
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (arr[i][j] > max)
				max = arr[i][j];
	return max;
}
void Matrix::MixingElements() {//переміщення елементів вліво на одну позицію 
	int temp;
	temp = arr[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			arr[i][j] = arr[i][j + 1];
		if (i != rows - 1)
			arr[i][cols - 1] = arr[i + 1][0];
	}
	arr[rows - 1][cols - 1] = temp;
}