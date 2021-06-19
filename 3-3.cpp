#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
//숫자 카드 게임  
using namespace std;

int main()
{
	  
	int N;
	int M;
	
	vector<int> vecnmin;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int n;
		int n_min = 10000;
		for (int k = 0; k < M; k++)
		{
			
			cin >> n;

			if (n < n_min)
				n_min = n;

		}

		vecnmin.push_back(n_min);
	}

	sort(vecnmin.begin(), vecnmin.end());

	printf("%d", vecnmin[N - 1]);

	return 0;
}
