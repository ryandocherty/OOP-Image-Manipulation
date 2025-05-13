#include <iostream> 
#include<iomanip>
using namespace  std;

class Matrix 
{
	Matrix::Matrix(int sizeR, int sizeC, double val);
	Matrix::~Matrix();
	void Matrix::Print();

private: 
	int M, N;
	double *data;
};

Matrix::Matrix(int sizeR, int sizeC, double val)
{ 
	M = sizeR; 
	N = sizeC; 
	data = new double[M*N]; 
	for (int ii=0; ii<M*N; ii++)
	{ 
		data[ii] = val;
	} 
}


Matrix::~Matrix()
{
	delete [] data;
}


void Matrix::Print()

{
	int A[35];
	{
		for (int ii = 0; ii < M; ii++)
			A[ii] = 98;

		
		for (int jj = 0; jj < N; jj++)
		{
			cout<< data[ii * N + jj] << + " ";
		}
	}

}

int main()
{
	Matrix Mat1(5,7,98);
	mat1.Print();
	system("pause");
	return 0; 
}