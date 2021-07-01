#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
 
02984
*/
 
 

int main()
{
	string strn;

	cin >> strn;
	int result = 0;
	 

	for (int i = 0; i < strn.length(); i++)
	{
		//둘중하나라도 0 아니면 곱하기 
		if (result != 0 && (strn[i] -48) != 0)
		{
			result = result *( strn[i ] -48);
		}
		else
			result = result + (strn[i] - 48);
	}
 
	cout << result;
	return 1;
}
