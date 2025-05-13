//2D array using pointers
#include <iostream> 
#include<iomanip>
using namespace  std;

void getSubArray(double *pA, int start, int end, double *pB);

int main()
{
	//Create array of 5 pointers, in this case the number of rows is 5
	double 	start = 0;
	double end = 3;
	double *pA[10];
	double *pB[4];

	//for each one of the 5 pointers allocate memory of 10 integers for each which is the number of columns
	for (int i = 0; i < 5; i++)
		pA[i] = new double[10];


	//initilize array elements each to 10i+20j
	for (int i = 0; i < 5; i++)      //LOOP through rows
	for (int j = 0; j < 10; j++)     //LOOP through columns
		pA[i][j] = 10 * i + 20 * j;


	//Print the first row at location [0][j]
	for (int j = 0; j < 10; j++)
	{
		cout << setw(4) << pA[0][j];      //set the width of each printed element to 4 digits
		cout << endl;
	}
	
	getSubArray(*pA, start, end, *pB);

	//FREE memory , the inverse of allocation memory
	for (int i = 0; i < 5; i++)
		delete[] pA[i];

	system("pause");
}

void getSubArray(double *pA, int start, int end, double *pB)
{

	pB = new double[end - start + 1];

	int pbCurrent = 0;
	for (int i = start; i <= end; i++)
	{
		pB[pbCurrent] = pA[i];
		cout << pB[pbCurrent] << ",";
		pbCurrent++;
	}
}