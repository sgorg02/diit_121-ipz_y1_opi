#include <iostream>
#include "prototypes.h"
#include "Windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::system("menu.txt");

	int number;
	do
	{
		std::system("cls");
		std::cout << "1. Заповнювати матрицю з клавіатури" << std::endl;
		std::cout << "2. Випадкове заповнення матриці" << std::endl;
		std::cout << "3. Вихід" << std::endl;
		while (!(std::cin >> number) || (std::cin.peek() != '\n')) //перевірки введеної зміної на символи
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			system("cls");
			std::cerr << "Помилка вводу! Повторіть ввод. Номер меню повинен бути цілим числом." << std::endl;
			std::cout << std::endl;
			std::cout << "1. Заповнювати матрицю з клавіатури" << std::endl;
			std::cout << "2. Випадкове заповнення матриці" << std::endl;
			std::cout << "3. Вихід" << std::endl;
		}

		switch (number)
		{
		case 1:
		{
			std::system("cls");

			int size;
			std::cout << "Введіть розмір матриці: ";
			while (!(std::cin >> size) || (std::cin.peek() != '\n') || !(size > 1)) //перевірки введеної зміної на символи
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cerr << "Помилка вводу! Повторіть ввод. Розмір матриці повинен бути додатним числом и більше 1." << std::endl;
				std::cout << std::endl;
				std::cout << "Введіть розмір матриці: ";
			}

			int n = 1;
			int **Array = New2DArray(size);
			
			for (int i = 0; i < size; i++)//заповнення масива нулями
			{
				for (int j = 0; j < size; j++)
				{
					Array[i][j] = 0;
				}
			}

			for (int m = 0; m < size; m++)//заповнення масива з клавіатури
			{
				for (int n = 0; n < size; n++)
				{
					std::system("cls");				
					PrintArray(Array, size);
					std::cout << "arr[" << m << "][" << n << "] = ";
					std::cin >> Array[m][n];
				}
			}
			
			std::system("cls");
			PrintArray(Array, size);

			int max;
			max = FindingMax(Array, size);
			//std::cout << "Максимальне число " << max << std::endl;

			int min;
			min = FindingMin(Array, size);
			//std::cout << "Мінімальне число " << min << std::endl;

			if (max < min)
			{
				std::cout << "Так як максимальне число меньше мінімального, то ми транспонуємо матрицю" << std::endl;
				int** tmparr = NewTransposeArray(Array, size);
				PrintArray(tmparr, size);
				Delete2DArray(tmparr, size);
			}
			else
			{
				std::cout << "Так як максимальне число більше мінімального, то ми матрицю підносимо у квадрат" << std::endl;
				std::cout << "Матриця в квадраті:" << std::endl;
				SquareArray(Array, size);
				PrintArray(Array, size);
			}

			Delete2DArray(Array, size);
			std::system("pause");
		}
		break;
		case 2:
		{
			std::system("cls");

			int size;
			std::cout << "Введіть розмір матриці: ";
			while (!(std::cin >> size) || (std::cin.peek() != '\n') || !(size > 1)) //перевірки введеної зміної на символи
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cerr << "Помилка вводу! Повторіть ввод. Розмір матриці повинен бути цілим числом та більшим за 1." << std::endl;
				std::cout << std::endl;
				std::cout << "Введіть розмір матриці: ";
			}

			int **Array = New2DArray(size);
			FillingArray(Array, size);
			PrintArray(Array, size);

			int max;
			max = FindingMax(Array, size);
			//std::cout << "Максимальне число " << max << std::endl;

			int min;
			min = FindingMin(Array, size);
			//std::cout << "Мінімальне число " << min << std::endl;


			if (max < min)
			{
				std::cout << "Так як максимальне число меньше мінімального, то ми транспонуємо матрицю" << std::endl;
				std::cout << "Транспортована матриця:" << std::endl;
				int** tmparr = NewTransposeArray(Array, size);
				PrintArray(tmparr, size);
				Delete2DArray(tmparr, size);
			}
			else
			{
				std::cout << "Так як максимальне число більше мінімального, то ми матрицю підносимо у квадрат" << std::endl;
				std::cout << "Матриця в квадраті:" << std::endl;
				SquareArray(Array, size);
				PrintArray(Array, size);
			}

			Delete2DArray(Array, size);
			std::system("pause");
		}
		break;
		case 3:
			return 0;
		default:
			std::system("cls");
			std::cout << "Введено невірний номер меню!" << std::endl << std::endl;
			std::system("pause");
			break;
		}
	} while (number != 3);
}