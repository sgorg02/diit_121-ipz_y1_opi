#include <iostream>
#include <conio.h>
#include "Header.h"
#include "Windows.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int min, max;
	int **Array;
	int **tmparr;
	int size;
	char choice, choiceExit;

	do {
		std::system("cls");
		std::cout << "Ви відкрили програму роботи із діалогом типу питання-відповідь!\n Бажаєте продовжити роботу? (Y/N)" << std::endl;
		choiceExit = _getch();
		if ((choiceExit == 'Y') || (choiceExit == 'y')) {
			std::system("cls");
			std::cout << "Бажаєте ввести вхідні дані з клавіатури? (Y/N)" << std::endl;
			choice = _getch();
			if ((choice == 'Y') || (choice == 'y')) {
				std::system("cls");
				std::cout << "Введіть розмір матриці: ";
				size = input_size();

				int n = 1;
				Array = New2DArray(size);

				for (int i = 0; i < size; i++)//заповнення масива нулями
					for (int j = 0; j < size; j++)
						Array[i][j] = 0;

				for (int m = 0; m < size; m++) {//заповнення масива з клавіатури
					for (int n = 0; n < size; n++) {
						std::system("cls");
						PrintArray(Array, size);
						std::cout << "arr[" << m << "][" << n << "] = ";
						std::cin >> Array[m][n];
					}
				}
				std::system("cls");
				std::cout << "Бажаєте виконати розрахунки? (Y/N)" << std::endl;
				choice = _getch();
				if ((choice == 'Y') || (choice == 'y')) {
					max = FindingMax(Array, size);
					min = FindingMin(Array, size);
					if (max < min)
						tmparr = NewTransposeArray(Array, size);
					else
						SquareArray(Array, size);

					std::system("cls");
					std::cout << "Бажаєте вивести результати? (Y/N)" << std::endl;
					choice = _getch();
					if ((choice == 'Y') || (choice == 'y')) {
						std::system("cls");
						if (max < min) {
							std::cout << "Так як максимальне число меньше мінімального, то ми транспонуємо матрицю" << std::endl;
							PrintArray(tmparr, size);
							Delete2DArray(tmparr, size);
						}
						else {
							std::cout << "Так як максимальне число більше мінімального, то ми матрицю підносимо у квадрат" << std::endl;
							std::cout << "Матриця в квадраті:" << std::endl;
							PrintArray(Array, size);
							Delete2DArray(Array, size);
						}
						system("Pause");
						std::cout << "Бажаєте продовжити роботу? (Y/N)" << std::endl;
						choiceExit = _getch();
					}
				}
			}
			else {
				std::system("cls");
				std::cout << "Бажаєте сформувати вхідні дані за допомогою генератора випадкових чисел? (Y/N)" << std::endl;
				choice = _getch();
				if ((choice == 'Y') || (choice == 'y')) {
					std::system("cls");
					std::cout << "Введіть розмір матриці: ";
					size = input_size();
					Array = New2DArray(size);
					FillingArray(Array, size);//заповнення масива випадковими числами
					
					std::system("cls");
					std::cout << "Бажаєте виконати розрахунки? (Y/N)" << std::endl;
					choice = _getch();
					if ((choice == 'Y') || (choice == 'y')) {
						max = FindingMax(Array, size);
						min = FindingMin(Array, size);
						if (max < min)
							tmparr = NewTransposeArray(Array, size);
						else
							SquareArray(Array, size);

						std::system("cls");
						std::cout << "Бажаєте вивести результати? (Y/N)" << std::endl;
						choice = _getch();
						if ((choice == 'Y') || (choice == 'y')) {
							std::system("cls");
							if (max < min) {
								std::cout << "Так як максимальне число меньше мінімального, то ми транспонуємо матрицю" << std::endl;
								PrintArray(tmparr, size);
								Delete2DArray(tmparr, size);
							}
							else {
								std::cout << "Так як максимальне число більше мінімального, то ми матрицю підносимо у квадрат" << std::endl;
								std::cout << "Матриця в квадраті:" << std::endl;
								PrintArray(Array, size);
								Delete2DArray(Array, size);
							}
							system("Pause");
							std::cout << "Бажаєте продовжити роботу? (Y/N)" << std::endl;
							choiceExit = _getch();
						}
					}
				}
			}
		}
	} while ((choiceExit != 'N') && (choiceExit != 'n'));
	return 0;
}