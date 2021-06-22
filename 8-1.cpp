#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 
using namespace std;
 
 
int cntarray[30001] = { 0, };

int main()
{
	  
	int n;
	cin >> n;

	int result;
	int number = 1;
	int cnt = 0;
	
	for (int i = 2; i <= n; i++)
	{
		cntarray[i] = cntarray[i - 1] + 1;

		if (i % 2 == 0)
			cntarray[i] = min(cntarray[i], cntarray[i / 2] + 1);


		if (i % 3 == 0)
			cntarray[i] = min(cntarray[i], cntarray[i / 3] + 1);


		if (i % 5 == 0)
			cntarray[i] = min(cntarray[i], cntarray[i / 5] + 1);
	}
	
	cout << cntarray[n] << endl;

	return 1;
}
