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
		std::cout << "1. ����������� ������� � ���������" << std::endl;
		std::cout << "2. ��������� ���������� �������" << std::endl;
		std::cout << "3. �����" << std::endl;
		while (!(std::cin >> number) || (std::cin.peek() != '\n')) //�������� ������� ���� �� �������
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			system("cls");
			std::cerr << "������� �����! �������� ����. ����� ���� ������� ���� ����� ������." << std::endl;
			std::cout << std::endl;
			std::cout << "1. ����������� ������� � ���������" << std::endl;
			std::cout << "2. ��������� ���������� �������" << std::endl;
			std::cout << "3. �����" << std::endl;
		}

		switch (number)
		{
		case 1:
		{
			std::system("cls");

			int size;
			std::cout << "������ ����� �������: ";
			while (!(std::cin >> size) || (std::cin.peek() != '\n') || !(size > 1)) //�������� ������� ���� �� �������
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cerr << "������� �����! �������� ����. ����� ������� ������� ���� �������� ������ � ����� 1." << std::endl;
				std::cout << std::endl;
				std::cout << "������ ����� �������: ";
			}

			int n = 1;
			int **Array = New2DArray(size);
			
			for (int i = 0; i < size; i++)//���������� ������ ������
			{
				for (int j = 0; j < size; j++)
				{
					Array[i][j] = 0;
				}
			}

			for (int m = 0; m < size; m++)//���������� ������ � ���������
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
			//std::cout << "����������� ����� " << max << std::endl;

			int min;
			min = FindingMin(Array, size);
			//std::cout << "̳������� ����� " << min << std::endl;

			if (max < min)
			{
				std::cout << "��� �� ����������� ����� ������ ����������, �� �� ����������� �������" << std::endl;
				int** tmparr = NewTransposeArray(Array, size);
				PrintArray(tmparr, size);
				Delete2DArray(tmparr, size);
			}
			else
			{
				std::cout << "��� �� ����������� ����� ����� ����������, �� �� ������� �������� � �������" << std::endl;
				std::cout << "������� � �������:" << std::endl;
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
			std::cout << "������ ����� �������: ";
			while (!(std::cin >> size) || (std::cin.peek() != '\n') || !(size > 1)) //�������� ������� ���� �� �������
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				std::cerr << "������� �����! �������� ����. ����� ������� ������� ���� ����� ������ �� ������ �� 1." << std::endl;
				std::cout << std::endl;
				std::cout << "������ ����� �������: ";
			}

			int **Array = New2DArray(size);
			FillingArray(Array, size);
			PrintArray(Array, size);

			int max;
			max = FindingMax(Array, size);
			//std::cout << "����������� ����� " << max << std::endl;

			int min;
			min = FindingMin(Array, size);
			//std::cout << "̳������� ����� " << min << std::endl;


			if (max < min)
			{
				std::cout << "��� �� ����������� ����� ������ ����������, �� �� ����������� �������" << std::endl;
				std::cout << "�������������� �������:" << std::endl;
				int** tmparr = NewTransposeArray(Array, size);
				PrintArray(tmparr, size);
				Delete2DArray(tmparr, size);
			}
			else
			{
				std::cout << "��� �� ����������� ����� ����� ����������, �� �� ������� �������� � �������" << std::endl;
				std::cout << "������� � �������:" << std::endl;
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
			std::cout << "������� ������� ����� ����!" << std::endl << std::endl;
			std::system("pause");
			break;
		}
	} while (number != 3);
}