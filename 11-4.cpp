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
3 2 1 1 9
*/
 
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int inum;
		cin >> inum;
		v.push_back(inum);
	}

	sort(v.begin(), v.end());

	int result = 1;

	for (int i = 0; i < v.size(); i++)
	{
		if (result < v[i])
			break;

		result += v[i];

	}

	cout << result;
	return 0;
}
