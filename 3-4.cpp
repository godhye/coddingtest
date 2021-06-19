#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
//1이 될때까지   
using namespace std;

int main()
{
	  
	int N;
	int K;
	int result = 0;
	cin >> N >> K;
	int target;

	while (true)
	{
		// 나누기전ㅇㅔ 1빼기 수행
		target = (N / K) * K;
		result += (N - target);
		N = target;
		printf("A target %d result %d N %d K %d \n", target, result, N , K);

		//K로 나누기
		result += 1;
		N = N / K;

		printf("B target %d result %d N %d K %d \n", target, result, N, K);
		if (N == 1)
			break;

	}
	 
	printf("%d ", result);
	cout << result;
	return 0;
}
