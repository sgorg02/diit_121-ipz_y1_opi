#include <iostream>
#include <cmath>
#include "function.h"

int input1() {
	int number1;
	while (!(std::cin >> number1) || (std::cin.peek() != '\n')) {
		std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "1.ѕерший приклад" << std::endl;
		std::cout << "2.ƒругий приклад" << std::endl;
		std::cout << "3.“рет≥й приклад" << std::endl;
		std::cout << "4.¬их≥д" << std::endl;
	}
	return number1;
}
int input2() {
	int number2;
	while (!(std::cin >> number2) || (std::cin.peek() != '\n')) {
		std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "1.÷≥л≥ числа" << std::endl;
		std::cout << "2.ƒ≥йсне числа" << std::endl;
		std::cout << "3.¬их≥д в меню" << std::endl;
		std::cout << "4.¬их≥д з програми" << std::endl;
	}
	return number2;
}
double input_b() {
	double b;
	while (!(std::cin >> b) || (std::cin.peek() != '\n') || (b < 0)) {
		std::system("cls");
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "„исло b повино бути б≥льше або дор≥внюват≥ нулю!" << std::endl;
		std::cout << "¬вед≥ть число b: ";
	}
	return b;
}

void menu1() {
	std::cout << "1.ѕерший приклад" << std::endl;
	std::cout << "2.ƒругий приклад" << std::endl;
	std::cout << "3.“рет≥й приклад" << std::endl;
	std::cout << "4.¬их≥д" << std::endl;
}
void menu2() {
	std::cout << "1.÷≥л≥ числа" << std::endl;
	std::cout << "2.ƒ≥йсне числа" << std::endl;
	std::cout << "3.¬их≥д в меню" << std::endl;
	std::cout << "4.¬их≥д з програми" << std::endl;
}
void ExampleSelection(int number1, double *arr) {// вибор зм≥них дл€ приклад≥в

	switch (number1){
	case 1: {
		std::cout << "¬вед≥ть число a: ";
		std::cin >> arr[0];
		std::cout << "¬вед≥ть число b: ";
		arr[1] = input_b();
		std::cout << "¬вед≥ть число c: ";
		std::cin >> arr[2];
		break;
	}
	case 2: {
		std::cout << "¬вед≥ть число y: ";
		std::cin >> arr[0];
		std::cout << "¬вед≥ть число n: ";
		std::cin >> arr[1];
		std::cout << "¬вед≥ть число m: ";
		std::cin >> arr[2];
		break;
	}
	case 3: {
		std::cout << "¬вед≥ть число z: ";
		std::cin >> arr[0];
		std::cout << "¬вед≥ть число p: ";
		std::cin >> arr[1];
		std::cout << "¬вед≥ть число q: ";
		std::cin >> arr[2];
		break;
	}
	default:
		break;
	}
}

double f1(void* args, Type type) {
	
	double b, result;
	b = static_cast<double*>(args)[1];
	result = sqrt(b);
	
	switch (type) {
	case INT_: {
		return static_cast<int>(result);
		break;
	}
	case DOUBLE_: {
		return static_cast<double>(result);
		break;
	}
	default:
		std::cout << "Error" << std::endl;
	}
}
double f2(void* args, Type type) {
	
	double y, n, m, result, result1, result2;
	y = static_cast<double*>(args)[0];
	n = static_cast<double*>(args)[1];
	m = static_cast<double*>(args)[2];
	result1 = pow((2 * n) / pow(y, (m + n)), (1 / n));
	result2 = pow(pow(y, (pow((m - n), 2) + (4 * m * n)) / (pow(m, 2) - pow(n, 2))), (1 / m));
	result = result1 / result2;
	
	switch (type) {
	case INT_: {
		return static_cast<int>(result);
		break;
	}
	case DOUBLE_: {
		return static_cast<double>(result);
		break;
	}
	default:
		std::cout << "Error" << std::endl;
	}
}
double f3(void* args, Type type) {

	double z, p, q, result, result1, result2;
	z = static_cast<double*>(args)[0];
	p = static_cast<double*>(args)[1];
	q = static_cast<double*>(args)[2];
	result1 = pow((pow(z, (2 / p)) + pow(z, (2 / q))), 2) - 4 * pow(z, ((2 / p) + (2 / q)));
	result2 = pow((pow(z, (1 / p)) - pow(z, (1 / q))), 2) + 4 * pow(z, ((1 / p) + (1 / q)));
	result = pow((result1 / result2), (1 / 2));

	switch (type) {
	case INT_: {
		return static_cast<int>(result);
		break;
	}
	case DOUBLE_: {
		return static_cast<double>(result);
		break;
	}
	default:
		std::cout << "Error" << std::endl;
	}
}

double SolveExmpl(pointfunc F, double *arr, Type type) {
	return F(arr, type);
}