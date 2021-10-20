#include <iostream>
#include <cmath>
#include "Windows.h"
#include "function.h"


int main() {
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double arr[3];
	int number1, number2;
	do {
		system("cls");
		menu1();
		number1 = input1();
		std::cin.get();//очистка буфера

		switch (number1) {
		case 1: {
			do {
				system("cls");
				menu2();
				number2 = input2();
				std::cin.get();

				switch (number2) {
				case 1: {
					system("cls");
					int result;
					ExampleSelection(number1, arr);
					result = SolveExmpl(f1, arr, INT_);
					std::cout << "Відповідь: " << result << std::endl;
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					double result;
					ExampleSelection(number1, arr);
					result = SolveExmpl(f1, arr, DOUBLE_);
					std::cout << "Відповідь: " << result << std::endl;
					system("pause");
					break;
				}
				case 4:
					return NULL;
				default:
					break;
				}
			} while (number2 != 3);
			break;
		}
		case 2: {
			do {
				system("cls");
				menu2();
				number2 = input2();
				std::cin.get();

				switch (number2) {
				case 1: {
					system("cls");
					int result;
					ExampleSelection(number1, arr);
					result = SolveExmpl(f2, arr, INT_);
					std::cout << "Відповідь: " << result << std::endl;
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					double result;
					ExampleSelection(number1, arr);
					result = SolveExmpl(f2, arr, DOUBLE_);
					std::cout << "Відповідь: " << result << std::endl;
					system("pause");
					break;
				}
				case 4:
					return NULL;
				default:
					break;
				}
			} while (number2 != 3);
			break;
		}
		case 3: {
			do {
				system("cls");
				menu2();
				number2 = input2();
				std::cin.get();

				switch (number2) {
				case 1: {
					system("cls");
					int result;
					ExampleSelection(number1, arr);
					result = SolveExmpl(f3, arr, INT_);
					std::cout << "Відповідь: " << result << std::endl;
					system("pause");
					break;
				}
				case 2: {
					system("cls");
					double result;
					ExampleSelection(number1, arr);
					result = SolveExmpl(f3, arr, DOUBLE_);
					std::cout << "Відповідь: " << result << std::endl;
					system("pause");
					break;
				}
				case 4:
					return NULL;
				default:
					break;
				}
			} while (number2 != 3);
			break;
		}
		case 4:
			return NULL;
		default:
			break;
		}
	} while (number1 != 4);
}