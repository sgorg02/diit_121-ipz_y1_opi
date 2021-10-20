#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix {
private:
	int rows, cols;
	int **arr;
	int **tmp_arr;
public:
	Matrix(int new_rows, int new_cols);

	~Matrix();

	void Setij(int i, int j, int el);

	int** getMatrix();

	void FillByUser();
	void FillByRandom();

	void output_matrix();
	int FindingTheMax_Min();
	void MixingElements();

	friend class FileWork;
	friend class Interface;
};

#endif