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

	int heigh;
	int start = 0;
	int end = length[length.size() - 1];
	int middle = 0;
	int target = 0;
	int result;
	while (start <= end)
	{
		
		middle = (start + end) / 2;

		for (int i = 0; i < N; i++)
		{
			int remain = length[i] - middle;
			if (remain > 0)
				target += remain;
			
		}

		if (target == K)
			break;
		else if (target > K)
			start = middle - 1;
			
		else
		{
			result = middle;
			end = middle + 1;
		}
		target = 0;

	}
	 
	cout << middle;
	return 1;

}
