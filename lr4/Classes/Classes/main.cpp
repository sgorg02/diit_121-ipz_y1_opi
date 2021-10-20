#include <iostream>
#include <fstream>
#include <random>
#include <Windows.h>
#include "Matrix.h"
#include "FileWork.h"
#include "Interface.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu;
	int max;
	int rows, cols;
	do {
		menu = Interface::options();
		
		switch (menu) {
		case 1: {
			system("cls");
			rows = Interface::input_check('r');//r-rows
			cols = Interface::input_check('c');//c-cols
			Matrix matrix(rows, cols);
			matrix.FillByUser();
			matrix.output_matrix();
			max = matrix.FindingTheMax_Min();
			int **Array = matrix.getMatrix();
			while (true) {
				if (Array[0][0] == max) {
					Interface::message_one();
					matrix.output_matrix();
					system("pause");
					break;
				}
				else
					matrix.MixingElements();
			}
			break;
		}
		case 2: {
			system("cls");
			rows = Interface::input_check('r');//r-rows
			cols = Interface::input_check('c');//c-cols
			Matrix matrix(rows, cols);
			matrix.FillByRandom();
			matrix.output_matrix();
			max = matrix.FindingTheMax_Min();
			int **Array = matrix.getMatrix();
			while (true) {
				if (Array[0][0] == max) {
					Interface::message_one();
					matrix.output_matrix();
					system("pause");
					break;
				}
				else
					matrix.MixingElements();
			}
			break;
		}
		case 3: {
			system("cls");
			FileMatrix arr;
			std::ifstream file_in("array.txt", std::ios::binary);
			arr = FileWork::take_values_to_matrix(file_in);
			Matrix matrix(arr.rows, arr.cols);
			for (int i = 0; i < arr.rows; i++)
				for (int j = 0; j < arr.cols; j++)
					matrix.Setij(i, j, arr.matrix[i][j]);
			matrix.output_matrix();
			max = matrix.FindingTheMax_Min();
			int **Array = matrix.getMatrix();
			while (true) {
				if (Array[0][0] == max) {
					Interface::message_one();
					matrix.output_matrix();
					system("pause");
					break;
				}
				else
					matrix.MixingElements();
			}
			file_in.close();
			std::ofstream file_out("redone array.txt", std::ios::binary);
			FileWork::write_values_to_file(file_out, Array, arr.rows, arr.cols);
			file_out.close();
			break;
		}
		case 4:
			return 0;
		default:
			break;
		}
	} while (menu != 4);
}