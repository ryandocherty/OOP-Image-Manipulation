#include <iostream>
using namespace std;

int main(){
	
	int size;
	
	cout << "Enter array size\t";
	cin >> size;

	int first = 0, last = size, input;
	int mid = (first + last) / 2;

	int *Array1 = new int[size];


	bool found = false;
	for (int i = 0; i< size; i++)
	{
		cout << "Array[" << i << "]: ";
		cin >> Array1[i];
	}

	
	cout << "\nEnter number to be found:";
	cin >> input;

	if (Array1[mid] == input)
	{
		cout << "Position = " << mid;
	}

	while ((Array1[mid] != input) && (first <= last))
	{

		if (Array1[mid] > input)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
		mid = (first + last) / 2;
	}


	if (first <= last)
	{
		cout << "\nPosition = " << mid << endl;
	}
	else
	{
		cout << "\nNot found";
	}
	
	system("Pause");
	return 0;
}