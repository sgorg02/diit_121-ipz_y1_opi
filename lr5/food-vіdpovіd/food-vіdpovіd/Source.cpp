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
		std::cout << "�� ������� �������� ������ �� ������� ���� �������-�������!\n ������ ���������� ������? (Y/N)" << std::endl;
		choiceExit = _getch();
		if ((choiceExit == 'Y') || (choiceExit == 'y')) {
			std::system("cls");
			std::cout << "������ ������ ����� ��� � ���������? (Y/N)" << std::endl;
			choice = _getch();
			if ((choice == 'Y') || (choice == 'y')) {
				std::system("cls");
				std::cout << "������ ����� �������: ";
				size = input_size();

				int n = 1;
				Array = New2DArray(size);

				for (int i = 0; i < size; i++)//���������� ������ ������
					for (int j = 0; j < size; j++)
						Array[i][j] = 0;

				for (int m = 0; m < size; m++) {//���������� ������ � ���������
					for (int n = 0; n < size; n++) {
						std::system("cls");
						PrintArray(Array, size);
						std::cout << "arr[" << m << "][" << n << "] = ";
						std::cin >> Array[m][n];
					}
				}
				std::system("cls");
				std::cout << "������ �������� ����������? (Y/N)" << std::endl;
				choice = _getch();
				if ((choice == 'Y') || (choice == 'y')) {
					max = FindingMax(Array, size);
					min = FindingMin(Array, size);
					if (max < min)
						tmparr = NewTransposeArray(Array, size);
					else
						SquareArray(Array, size);

					std::system("cls");
					std::cout << "������ ������� ����������? (Y/N)" << std::endl;
					choice = _getch();
					if ((choice == 'Y') || (choice == 'y')) {
						std::system("cls");
						if (max < min) {
							std::cout << "��� �� ����������� ����� ������ ����������, �� �� ����������� �������" << std::endl;
							PrintArray(tmparr, size);
							Delete2DArray(tmparr, size);
						}
						else {
							std::cout << "��� �� ����������� ����� ����� ����������, �� �� ������� �������� � �������" << std::endl;
							std::cout << "������� � �������:" << std::endl;
							PrintArray(Array, size);
							Delete2DArray(Array, size);
						}
						system("Pause");
						std::cout << "������ ���������� ������? (Y/N)" << std::endl;
						choiceExit = _getch();
					}
				}
			}
			else {
				std::system("cls");
				std::cout << "������ ���������� ����� ��� �� ��������� ���������� ���������� �����? (Y/N)" << std::endl;
				choice = _getch();
				if ((choice == 'Y') || (choice == 'y')) {
					std::system("cls");
					std::cout << "������ ����� �������: ";
					size = input_size();
					Array = New2DArray(size);
					FillingArray(Array, size);//���������� ������ ����������� �������
					
					std::system("cls");
					std::cout << "������ �������� ����������? (Y/N)" << std::endl;
					choice = _getch();
					if ((choice == 'Y') || (choice == 'y')) {
						max = FindingMax(Array, size);
						min = FindingMin(Array, size);
						if (max < min)
							tmparr = NewTransposeArray(Array, size);
						else
							SquareArray(Array, size);

						std::system("cls");
						std::cout << "������ ������� ����������? (Y/N)" << std::endl;
						choice = _getch();
						if ((choice == 'Y') || (choice == 'y')) {
							std::system("cls");
							if (max < min) {
								std::cout << "��� �� ����������� ����� ������ ����������, �� �� ����������� �������" << std::endl;
								PrintArray(tmparr, size);
								Delete2DArray(tmparr, size);
							}
							else {
								std::cout << "��� �� ����������� ����� ����� ����������, �� �� ������� �������� � �������" << std::endl;
								std::cout << "������� � �������:" << std::endl;
								PrintArray(Array, size);
								Delete2DArray(Array, size);
							}
							system("Pause");
							std::cout << "������ ���������� ������? (Y/N)" << std::endl;
							choiceExit = _getch();
						}
					}
				}
			}
		}
	} while ((choiceExit != 'N') && (choiceExit != 'n'));
	return 0;
}