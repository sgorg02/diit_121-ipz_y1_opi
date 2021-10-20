#ifndef __FUNCTION_H__
#define __FUNCTION_H__

using namespace System;

int** New2DArray(const int size);
void FillingArray(int **arr, const int size);
int FindingMax(int **arr, const int size);
int FindingMin(int **arr, const int size);
int** TransposeArray(int **arr, const int size);
int** SquareArray(int **arr, const int size);
void ReadingMatrix(int **(&arr), int &size, std::string filename);

std::string& Convert_String_to_string(String^ s, std::string& os);//конвертируем System::string^ в std::string
String^ Convert_string_to_String(std::string& os, String^ s);//конвертируем std::string в System::string^

#endif