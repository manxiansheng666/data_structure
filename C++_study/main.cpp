#include <iostream>
#include <string>
using namespace std;


int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 9; j >= i; j--)
		{
			cout << i << 'x' << j << '=' << i * j << "\t";
		}
		cout << endl;
	}
		
	return 0;
}