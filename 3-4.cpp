#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
//1이 될때까지   
using namespace std;

int main()
{
	  
	int N;
	int M;
	int result = 0;
	cin >> N >> M;
	 
	for (int i = 0; i < 100000; i++)
	{
		if (N == 1)
			break;

		if (N%M != 0)
		{
			N = N - 1;
		}
		else
		{
			N = N / M;

		}
		result++;
	}

	cout << result;
	return 0;
}
