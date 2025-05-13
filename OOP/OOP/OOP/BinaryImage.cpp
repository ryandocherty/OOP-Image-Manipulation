#include "Matrix.h"


BinaryImage::BinaryImage(int M, int N, double* input_data, double threshold) : Matrix(M, N, input_data)
{

	//fixes the noisy image
	for (int i = 0; i < M*N; i++)
	{
		if (data[i] < threshold)
		{
			data[i] = 0;
		}

		else
		{
			data[i] = 1; 
		}
	}
}
		



BinaryImage::BinaryImage(int M, int N, double val) : Matrix(M, N, val)
{

}


BinaryImage::BinaryImage(int mValue, int nValue)
{
	M = mValue;
	N = nValue; 
	data = new double[M * N]; 
}



BinaryImage::BinaryImage(const BinaryImage& m)
{
	//copy constructor

	M = m.getM();
	N = m.getN();

	data = new double[M*N];

	for (int i = 0; i < M*N; i++)
	{
		data[i] = m.getData(i);
	}
}

BinaryImage::BinaryImage(){}

BinaryImage BinaryImage::getBlock(int start_row, int end_row, int start_column, int end_column)
{
	int startBlock = (end_row - start_row) + 1;
	int endBlock = (end_column - start_column) + 1;

	BinaryImage temp(startBlock, endBlock);

	for (int i = start_row; i < end_row; i++)
	{
		for (int j = start_column; j < end_column; j++)
		{
			temp.setValue(i - start_row, j - start_column, getValue(i, j));
		}
	}
	return temp;
}


//----------------------------OPERATOR OVERLOADS--------------------------------------------------------


BinaryImage BinaryImage::operator=(const BinaryImage& existing)
{
	delete[] data;

	data = new double[existing.M*existing.N];

	for (int k = 0; k < (existing.M*existing.N); k++)

	{
		data[k] = existing.data[k];
	}

	return *this;
}

BinaryImage BinaryImage::operator+(const BinaryImage& existing)
{
	BinaryImage temp;

	temp.M = existing.M;
	temp.N = existing.N;

	temp.data = new double[temp.M*temp.N];
	for (int k = 0; k < (temp.M*temp.N); k++)
	{
		temp.data[k] = this->data[k] || existing.data[k];
	}
	return temp;
}

BinaryImage BinaryImage::operator-(const BinaryImage& existing)
{

	
	BinaryImage temp;

	temp.M = existing.M;
	temp.N = existing.N;

	temp.data = new double[temp.M*temp.N];
	for (int k = 0; k < (temp.M*temp.N); k++)
	{
		temp.data[k] = this->data[k] != existing.data[k];
	}
	return temp;
}

BinaryImage BinaryImage::operator*(const BinaryImage& existing)
{

	
	BinaryImage temp;

	temp.M = existing.M;
	temp.N = existing.N;

	temp.data = new double[temp.M*temp.N];
	for (int k = 0; k < (temp.M*temp.N); k++)
	{
		temp.data[k] = this->data[k] && existing.data[k];
	}
	return temp;
}
