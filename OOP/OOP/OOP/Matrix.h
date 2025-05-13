#include <iostream>
using namespace std;

class Matrix
{
protected:
	int M, N;
	double* data;

public:
	Matrix();
	Matrix(const Matrix&);
	Matrix(int sizeR, int sizeC, double val);
	Matrix(int sizeR, int sizeC, double* input_data);

	
	double* getDoubleData(); 
	int getData(int i) const;
	int getM() const; 
	int getN() const; 


	//matrix block
	Matrix Matrix::getBlock(int start_row, int end_row, int start_column, int end_column);
	void Matrix::setBlock(int start_row, int end_row, int start_column, int end_column, Matrix& temp);
	

	//values from matrix
	double getValue(int i, int j); 
	void setValue(int i, int j, int val);

	double sumValue(); 

	//minimum value in a matrix
	double minValue(); 


	//operator overloads
	double operator()(int i, int j);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator=(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator/(const Matrix&);
	Matrix operator++();
	~Matrix(); //destructor
	
};


class BinaryImage : public Matrix
{
public:

	//constructors
	BinaryImage();
	BinaryImage::BinaryImage(int M, int N, double val);
	BinaryImage(int M, int N, double* input_data, double threshold);
	BinaryImage(const BinaryImage&);
	BinaryImage(int mValue, int nValue);
	
	BinaryImage getBlock(int start_row, int end_row, int start_col, int end_col);

	//operator overloads
	BinaryImage operator=(const BinaryImage&);
	BinaryImage operator+(const BinaryImage&);
	BinaryImage operator-(const BinaryImage&);
	BinaryImage operator*(const BinaryImage&);

	double operator()(int i, int j); 

};