#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
 
 5
 2 4 3 3 3
*/
 
 

int main()
{
	int n;
	int result =0;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}

	sort(v.begin(), v.end());
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		
		int k = v[i];

		count++;
		if (count >= k)
		{
			result++;
			count = 0;
		}


		 
		
	}
	cout << result;
	return 1;
}
