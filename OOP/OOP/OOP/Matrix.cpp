#include "Matrix.h"



//----------------------------------------------CONSTRUCTORS--------------------------------------------------------



Matrix::Matrix(int sizeR, int sizeC, double val)
{
	//makes new matrix and sets it all to one value (normal constructor)
	M = sizeR;
	N = sizeC;

	data = new double[M*N];

	for (int ii = 0; ii < M*N; ii++)
	{
		data[ii] = val;
	}
}

Matrix::Matrix(const Matrix& m)
{
	//copy constructor
	m.M; 

	M = m.getM();
	N = m.getN();

	data = new double[M*N];

	for (int ii = 0; ii < M*N; ii++)
	{
		data[ii] = m.getData(ii);
	}
}


Matrix::Matrix(int sizeR, int sizeC, double* input_data)
{
	M = sizeR;
	N = sizeC;

	data = new double[M*N];

	for (int ii = 0; ii < M*N; ii++)
	{
		*(data + ii) = *(input_data + ii); 
	}
}


Matrix::Matrix()
{

}

int Matrix::getM() const { return M; } 
int Matrix::getN() const { return N; }



double* Matrix::getDoubleData()
{
	//return pointer to matrix values
	return data; 
}

int Matrix::getData(int i) const
{
	//returns data from one dimensional coodinate
	return (int)*(data + i); 
}



double Matrix::getValue(int i, int j)
{
	return *(data + ((i * N) + j)); 
}


Matrix Matrix::getBlock(int start_row, int end_row, int start_column, int end_column)
{
	//get a block from matrix
	int endBlock = end_column - start_column + 1;
	int startBlock = end_row - start_row + 1;

	Matrix temp(endBlock, startBlock, 1);

	for (int i = 0; i < end_row; i++)
	{
		for (int j = 0; j < end_column; j++)
		{
			temp.setValue(i - start_row, j - start_column, getValue(i, j));
		}
	}
	return temp;
}

void Matrix::setBlock(int start_row, int end_row, int start_column, int end_column, Matrix& temp)
{
	
	for (int i = 0; i < temp.getN()-1; i++)
	{
		for (int j = 0; j < temp.getM()-1; j++)
		{
			setValue(j + start_row, i + start_column, temp.getValue(j, i));
		}
	}
}


void Matrix::setValue(int i, int j, int value) 
{
	//set single value in any matrix 
	*(data + ((i*N)+j)) = value; 
}

double Matrix::minValue()
{
	double minValue = data[0];
	double smallestPosition = 0;

	for (int i = 0; i < M*N; i++)
	{
		if (data[i] < minValue)
		{
			minValue = data[i]; //stores current data as the minimum value
			smallestPosition = i; //stores the smallest value position 
		}
	}

	return smallestPosition;
}

double Matrix::sumValue()
{
	double output = 0;
	for (int i = 0; i < (M*N); i++)
	{
		output = output + data[i];
	}

	return output;
}


//----------------------------------------------OPERATOR OVERLOADS--------------------------------------------------------


Matrix Matrix::operator+(const Matrix& existing)
{
	Matrix temp;

	temp.M = existing.M;
	temp.N = existing.N;

	temp.data = new double[temp.M*temp.N];
	for (int k = 0; k < (temp.M*temp.N); k++)
	{
		temp.data[k] = this->data[k] + existing.data[k];
	}
	return temp;

}

Matrix Matrix::operator-(const Matrix& existing)
{
	Matrix temp;
	temp.M = existing.M;
	temp.N = existing.N;

	temp.data = new double[temp.M*temp.N];
	for (int k = 0; k < (temp.M*temp.N); k++)
	{
		temp.data[k] = this->data[k] - existing.data[k];
	}
	return temp;

}

Matrix Matrix::operator*(const Matrix& existing)
{
	Matrix temp;
	temp.M = existing.M;
	temp.N = existing.N;

	temp.data = new double[temp.M*temp.N];
	for (int k = 0; k < (temp.M*temp.N); k++)
	{
		temp.data[k] = this->data[k] * existing.data[k];
	}
	return temp;

}

Matrix Matrix::operator/(const Matrix& existing)
{
	Matrix temp;
	temp.M = existing.M;
	temp.N = existing.N;

	temp.data = new double[temp.M*temp.N];
	for (int k = 0; k < (temp.M*temp.N); k++)
	{
		temp.data[k] = this->data[k] / existing.data[k];
	}
	return temp;

}

Matrix Matrix::operator++()
{
	for (int i = 0; i < (M*N); i++)
	{
		this->data[i]++;
	}

	return *this;
}


Matrix Matrix::operator=(const Matrix& existing)
{
	delete[] data;

	data = new double[existing.M*existing.N];

	for (int k = 0; k < (existing.M*existing.N); k++)

	{
		data[k] = existing.data[k];
	}

	return *this;
}

double Matrix::operator()(int i, int j)
{
	return (int)*(data + ((i*N) + j));
}



Matrix::~Matrix()
{
	delete[] data;
	//data = 0; 
}