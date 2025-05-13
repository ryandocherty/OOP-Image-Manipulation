#include <iostream>
using namespace std;

class Matrix
{
public:

	Matrix::Matrix(int sizeR, int sizeC, double val);
	Matrix::Matrix(int sizeR, int sizeC, double *input_data);
	Matrix::Matrix(const Matrix&); 
	Matrix::~Matrix();
	Matrix Matrix::getBlock(int start_row, int end_row, int start_column, int end_column);
	double get(int i, int j) const{ return data[i*N + j]; };
	void set(int i, int j, double val) { data[i*N + j] = val; };
	
private:
	int M;
	int N;
	double* data;
};

int main()
{
	int a = 5;
	int b = 7;
	double* thing = new double[a*b];
	for (int i = 0; i < a*b; i++)
	{
		*(thing + i) = i + 1;
	}
	Matrix matrix1(5, 7, thing); //matrix with 5 rows, 7 cols
	cout << matrix1.get(4, 3) << endl; //matrix object B
	Matrix matrix2(matrix1); 
	Matrix matrix3 =matrix2.getBlock(2,3,4,4); 
	
	system("pause");
	return 0;
}

Matrix Matrix::getBlock(int start_row, int end_row, int start_column, int end_column)
{
	int rows = end_row - start_row +1; 
	int columns = end_column - start_column +1; 

	double *block = new double[rows * columns]; 
	for (int j = 0; j < rows * columns; j++)
	{

		block[j] = data[(start_row * N + start_column) + j];
		cout << block[j] << endl;  
	}
	return Matrix(rows, columns, block);
}

Matrix::Matrix(int sizeR, int sizeC, double val)
{
	M = sizeR;
	N = sizeC;

	data = new double[M*N];

	for (int ii = 0; ii<M*N; ii++)
	{
		data[ii] = val;
	}
	cout << "Matrix::Matrix(int sizeR, int sizeC, double val) is invoked." << endl;
}


Matrix::Matrix(int sizeR, int sizeC, double* input_data)
{
	M = sizeR;
	N = sizeC;

	data = new double[M*N];

	for (int ii = 0; ii<M*N; ii++)
	{
		data[ii] = input_data[ii];
	}
	cout << "Matrix::Matrix(int sizeR, int sizeC, double* input_data) is invoked." << endl;
}

Matrix::Matrix(const Matrix& m)
{
	M = m.M; //copies the value stored in the original matrix
	N = m.N;

	data = new double[M*N];

	for (int ii = 0; ii<M*N; ii++)
	{
		data[ii] = m.data[ii];
	}
	cout << "Matrix::Matrix(const Matrix&) is invoked." << endl;
}

Matrix::~Matrix()
{
	delete[] data;
	data = 0;
	cout << "Matrix::~Matrix() is invoked.\n" << endl;
}

