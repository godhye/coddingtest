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
 2 4 3 1 2
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

	sort(v.begin(), v.begin() + v.size());

	for (int i = 0; i < v.size(); i++)
	{
		int k = v[i];

		for (int j = i; j < k; j++)
		{
			if (k < v[j])
				break;
			
			if (k == v[j])
				result++;
		}

		if (k != 1)
			i += k;
		
	}
	cout << result;
	return 1;
}
