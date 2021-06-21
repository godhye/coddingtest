#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 
using namespace std;
 
 

int main()
{

	int N, K;
	cin >> N >> K;
	vector<int> length;

	for (int i = 0; i < N; i++)
	{
		int c;
		cin >> c;
		length.push_back(c);
	}
	//정렬
	sort(length.begin(), length.end());

	
	int remain = 0;
	int k = 0;
	int n = length[N - 1];
	while (1)
	{
		
		remain = 0;
		for (int i =N-1; i >= 0; i--)
		{
			int remain2 =  length[i] - n;
			
			if (remain2 < 0)
				continue;
			else
				remain += remain2;

		}

		if (remain == K)
			break;

		n--;
		k++;

	}

	cout << n;
	 
	return 1;

}
