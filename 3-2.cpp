#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
//큰수의법칙 동빈맘
using namespace std;

int main()
{

	int	N;
	int M;
	int K;
	int result = 0;
	std::vector<int> number;
	cin >> N >> M >> K;

	printf("%d %d %d\n", N, M, K);

	for (int i = 0; i < N; i++)
	{
		int n;
		std::cin >> n;
		number.push_back(n);
	}

	 sort(number.begin(), number.end());

	result += number[N-1] * ( (M / K) * K);
	result += number[N-2] * (M % K);


	printf("%d", result);

	 
	return 0;
}
