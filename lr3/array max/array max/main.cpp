#include <iostream>
#include "Windows.h"
#include "function.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	matrix arr;


	char application_selection = 'r';//r-rows
	arr.rows = InputCheck(application_selection);

	application_selection = 'c';//c-cols
	system("cls");
	arr.cols = InputCheck(application_selection);

	int **Array = New2DArray(arr.rows, arr.cols);
	std::cout << "Початковий масив:" << std::endl;
	FillingArray(Array, arr.rows, arr.cols);

	std::system("cls");
	PrintArray(Array, arr.rows, arr.cols);

	arr.max = FindingMax(Array, arr);
	std::cout << "Максимальне число " << arr.max << std::endl;
	std::cout << std::endl;

	while (true) {
		if (Array[0][0] == arr.max) {
			std::cout << "Перероблений масив:" << std::endl;
			PrintArray(Array, arr.rows, arr.cols);
			system("pause");
			return 0;
		}
		else
			MixingElements(Array, arr);
	}
}
