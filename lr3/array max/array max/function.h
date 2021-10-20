#ifndef __FUNCTION_H__
#define __FUNCTION_H__

struct matrix{
	int cols, rows;
	int max;
};

int** New2DArray(const int rows, const int cols);
void Delete2DArray(int** arr, const int rows);
void PrintArray(int** arr, int rows, int cols);
void FillingArray(int **arr, int rows, int cols);
int FindingMax(int **arr, matrix Arr);
int InputCheck(char choice);
void MixingElements(int **arr, matrix Arr);

#endif