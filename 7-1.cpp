#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 
using namespace std;
 
//이진탐색
 
int main()
{
 
	int N, K;
	cin >> N >> K;

	vector <int> list;
	for (int i = 0; i < N; i++)
	{
		int c;
		cin >> c;
		list.push_back(c);
	}

	int start = 0;
	int end = list.size() - 1;
	int result = 0;
	while (1)
	{
		int middle = (start + end) / 2;
		result++;
		if (list[middle] == K)
		{
			break;
		}
		else if (list[middle] > K)
		{
			
			end = middle - 1;
		}
		else
		{
			start = middle + 1;

		}
		

	}
	cout << result << endl;
	return 1;

}
