#ifndef __INTERFACE_H__
#define __INTERFACE_H__

class Interface {
private:
public:
	static int options() {
		int menu;
		while (true) {
			system("cls");
			std::cout << "1. Заповнювати матрицю з клавіатури" << std::endl;
			std::cout << "2. Випадкове заповнення матриці" << std::endl;
			std::cout << "3. Отримати значення з файлу" << std::endl;
			std::cout << "4. Вихід" << std::endl;
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
		std::cout << "Перероблений масив:" << std::endl;
	}
	static int input_check(char choice) {
		int ArrayParameters;
		while (true) {
			if (choice == 'r')
				std::cout << "Введіть кількість рядків: ";
			else
				std::cout << "Введіть кількість стовпців: ";
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
			std::cout << "Введіть ліву границю: ";
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
			std::cout << "Введіть праву границю: ";
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