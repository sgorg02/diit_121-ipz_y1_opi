#include <fstream>
#include <iomanip> 
#include <iostream>
#include "FileWork.h"
#include "Matrix.h"

FileMatrix FileWork::take_values_to_matrix(std::ifstream& file) {
	FileMatrix ar;
	file >> ar.rows;
	file >> ar.cols;
	ar.matrix = new int*[ar.rows];
	for (int i = 0; i < ar.rows; i++)
		ar.matrix[i] = new int[ar.cols];

	for (int i = 0; i < ar.rows; i++)
		for (int j = 0; j < ar.cols; j++)
			file >> ar.matrix[i][j];
	return ar;
}

void FileWork::write_values_to_file(std::ofstream& file, int **arr, int new_rows, int new_cols) {
	for (int i = 0; i < new_rows; i++) {
		for (int j = 0; j < new_cols; j++)
			file << arr[i][j] << "\t";
		file << std::endl;
	}
}