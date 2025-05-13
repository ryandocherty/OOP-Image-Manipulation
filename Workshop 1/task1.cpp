#include <iostream>
using namespace std;

int main(){
	int m = 0, n = 0, temp = 0;
	cout<<"Provide input 1\t";
	cin>>m;

	cout<<"\nProvide input 2\t";
	cin>>n;

	while (m > 0)
	{
		if (n > m)
		{
			temp = n;
			n = m;
			m = temp;
		}

		m = m - n;
	}
	
	cout << n;
	return 0;
}