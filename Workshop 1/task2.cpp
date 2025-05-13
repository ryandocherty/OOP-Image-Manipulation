#include <iostream>
#include <cmath>
using namespace std;

int main(){

	double array[11] = { 2123, 2, 3, 4, 5, 6, 7, 34, 12, 100, 23 };
	double arraytotal = 0, sdtotal = 0, sd = 0, mean = 0;

	for (int i = 0; i < 11; i++)
	{
		arraytotal = arraytotal + array[i];
	}
	mean = arraytotal / 11;

	
	for (int i = 0; i < 11; i++)
	{
		sdtotal = sdtotal + pow(array[i] - mean, 2);
	}
	sd = sqrt(sdtotal / 11);
	

	cout << "Mean = " <<mean;
	cout << "\nSD = " << sd;
	return 0;
}