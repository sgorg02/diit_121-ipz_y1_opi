#ifndef __HEADER_H__
#define __HEADER_H__

int input_size();
int** New2DArray(const int size);
void Delete2DArray(int** Arr, const int size);
void PrintArray(int **arr, const int size);
void FillingArray(int **arr, const int size);
int FindingMax(int **arr, const int size);
int FindingMin(int **arr, const int size);
int** NewTransposeArray(int **arr, const int size);
void SquareArray(int **arr, const int size);

#endif