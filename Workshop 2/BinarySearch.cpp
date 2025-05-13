#include <iostream>
using namespace std;

int main (){

	int first = 0, last = 10, input;
	int mid = (first + last)/2;

	int Array1[11] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30};


	cout<<"Enter number to be found:\t";
	cin>>input;

	if (Array1[mid] == input)
	{
		cout<<"Position = "<<mid;
	}

	while ((Array1[mid] != input) &&(first <= last))
	{

		if (Array1[mid] > input)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
		mid = (first + last)/2;
	}


	if (first <= last)
	{
		cout<<"Position = "<<mid<<endl;
	}
	else
	{
		cout<<"Not found";
	}
	return 0;

	system("pause");

}

