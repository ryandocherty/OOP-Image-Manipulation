#include <iostream>
using namespace std;

int main (){

	double input, answer = 1;

	cout<<"Provide input:\t";
	cin>>input; 

	for (int i = 1; i <= input; i ++)
	{
		answer = answer*i;
	}
		
	cout<<"Factorial = "<<answer<<endl;

	return 0;
}