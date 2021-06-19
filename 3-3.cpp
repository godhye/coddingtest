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
	int result = 0 ;
	for (int i = 0; i < N; i++)
	{
		int n;
		//int n_min = 10000;
		int n_min = 10001; //왜10001 이지?,,,,10000으로해도 최소값은 구해지지않나????

		
		for (int k = 0; k < M; k++)
		{
			
			cin >> n;

			if (n < n_min)
				n_min = n;

		}

		//vecnmin.push_back(n_min); 굳이 값들을 기억할 필요 없고 작은 값만 찾으면 되니깐 벡터 사용x
		result = max(result, n_min);
	}

	//sort(vecnmin.begin(), vecnmin.end());

	//printf("%d", vecnmin[N - 1]);
	printf("%d", result);

	return 0;
}
