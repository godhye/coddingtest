#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 
using namespace std;
 
 
int resultarray[30001] = { 0, };
vector<int> vsize;

int main()
{

	int n;
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int size;
		cin >> size;

		vsize.push_back(size);
	}
	 
	resultarray[0] = vsize[0];
	resultarray[1] = max(vsize[1], vsize[0]);

	for (int i = 2; i < n; i++)
	{
		resultarray[i] = max(resultarray[i - 1], resultarray[i - 2] + vsize[i]);
	}

	cout << resultarray[n - 1];

	return 1;
}
