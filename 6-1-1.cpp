#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
선택정렬
 
 5
 3
 4
 1
 2
 0
*/
 
void swap(vector<int> &v , int a, int b)
{
	int temp;
	temp = v[a];

	v[a] = v[b];
	v[b] = temp;

	return;
}

int main()
{
	vector<int> narray;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int n;
		cin >> n;

		narray.push_back(n);
	}

	
	int nindex = -1;

	for (int i = 0; i < n; i++)
	{
		int nmin = 10000;
		for (int j = i; j < n; j++)
		{
			
				if (nmin > narray[j])
				{
					nindex = j;
					nmin = narray[j];
				}
		}
 
		swap(narray, i, nindex);
	}

	for (int i = 0 ;i < narray.size(); i++)
		cout << narray[i] << " ";
	return 1;
}
