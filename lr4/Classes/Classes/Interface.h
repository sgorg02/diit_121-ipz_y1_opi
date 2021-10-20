#ifndef __INTERFACE_H__
#define __INTERFACE_H__

class Interface {
private:
public:
	static int options() {
		int menu;
		while (true) {
			system("cls");
			std::cout << "1. ����������� ������� � ���������" << std::endl;
			std::cout << "2. ��������� ���������� �������" << std::endl;
			std::cout << "3. �������� �������� � �����" << std::endl;
			std::cout << "4. �����" << std::endl;
			std::cin >> menu;
			if ((std::cin.peek() != '\n') || !(menu > 0)) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
				return menu;
		}
	}

	static void message_one() {
		std::cout << "������������ �����:" << std::endl;
	}
	static int input_check(char choice) {
		int ArrayParameters;
		while (true) {
			if (choice == 'r')
				std::cout << "������ ������� �����: ";
			else
				std::cout << "������ ������� ��������: ";
			std::cin >> ArrayParameters;
			if ((std::cin.peek() != '\n') || !(ArrayParameters > 1)) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
				return ArrayParameters;
		}
	}
	static int left_border() {
		int Lb;
		while (true) {
			std::cout << "������ ��� �������: ";
			std::cin >> Lb;
			if ((std::cin.peek() != '\n')) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
				return Lb;
		}
	}
	static int right_border() {
		int Rb;
		while (true) {
			std::cout << "������ ����� �������: ";
			std::cin >> Rb;
			if ((std::cin.peek() != '\n')) {
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			else
				return Rb;
		}
	}
};

#endif