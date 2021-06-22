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
	
	resultarray[1] = 2;
	resultarray[2] = 3;

	for (int i = 3; i < n; i++)
	{
		resultarray[i] = (resultarray[i - 1] + resultarray[i - 2] *2) % 796796;
	}

	cout << resultarray[n];


	return 1;
}
