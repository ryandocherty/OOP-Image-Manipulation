#include <iostream>
using namespace std;

class Matrix
{
public:
	Matrix::Matrix(int sizeR, int sizeC, double val);
	Matrix::Matrix(const Matrix&);
	Matrix::Matrix(int sizeR, int sizeC, double *input_data);
	Matrix::~Matrix();
	Matrix Matrix::getBlock(int start_row, int end_row, int start_collumn, int end_collumn);
	double get(int i, int j) const{ return data[i*N + j]; };
	void set(int i, int j, double val) { data[i*N + j] = val; };
private:
	int M;
	int N;
	double* data;
};

int main()
{
	int k, m, n, l;
	int a = 5;
	int b = 7;
	double* thing = new double[a*b];
	for (int i = 0; i < a*b; i++)
	{
		thing[i] = i + 1;
	}
	Matrix matrix1(5, 7, thing);
	cout << "Input the starting collumn of the matrix: ";
		cin >> k;
	cout << "Input the starting row of the matrix: ";
		cin >> n;	
	cout << "Input the ending collumn of the matrix:  ";
		cin >> l;
	cout << "Input the ending row of the matrix: ";
		cin >> m;
	matrix1.getBlock(k, n, l, m);

	system("pause");
	return 0;
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
	M = m.M;
	N = m.N;

	data = new double[M*N];

	for (int ii = 0; ii < M*N; ii++)
	{
		data[ii] = m.data[ii];
	}
	cout << "Matrix::Matrix(const Matrix&) is invoked." << endl;
}
Matrix Matrix::getBlock(int start_collumn, int start_row, int end_collumn, int end_row)
{
	int startBlock = end_row - start_row;
	int endBlock = end_collumn - start_collumn;
	double *block = new double[startBlock*endBlock];
	for (int j = 0; j < startBlock*endBlock; j++)
	{
		block[j] = data[(start_row * N + start_collumn) + j];
		cout << block[j] << " \n";
	}
	return Matrix(startBlock, endBlock, data);
}

Matrix::~Matrix()
{
	delete[] data;
	data = 0;
	cout << "Matrix::~Matrix() is invoked...." << endl;
}