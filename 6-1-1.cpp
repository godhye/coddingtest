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
		int index = i;
		for (int j = i+1; j < n; j++)
		{
			
				if (narray[index] > narray[j])
				{
					index = j;
					
				}
		}
 
		swap(narray, i, index);
	}

	for (int i = 0 ;i < narray.size(); i++)
		cout << narray[i] << " ";
	return 1;
}
