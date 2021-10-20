#ifndef __FILEWORK_H__
#define __FILEWORK_H__
class Matrix;
struct FileMatrix {
	int rows, cols;
	int **matrix;
};
class FileWork {
public:
	static FileMatrix take_values_to_matrix(std::ifstream& file);
	static void write_values_to_file(std::ofstream& file, int **arr, int new_rows, int new_cols);
};

#endif