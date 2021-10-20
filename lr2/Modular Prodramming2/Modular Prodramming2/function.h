#ifndef __FUNCTION_H__
#define __FUNCTION_H__

enum Type { INT_, DOUBLE_ };
typedef double(*pointfunc)(void*, Type);

double f1(void *args, Type type);
double f2(void *args, Type type);
double f3(void *args, Type type);
double SolveExmpl(pointfunc F, double *arr, Type type);

int input1();
int input2();
double input_b();
void menu1();
void menu2();
void ExampleSelection(int number1, double *arr);

#endif