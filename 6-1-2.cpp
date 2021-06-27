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
 3
 2
 4
 1
 0
 삽입정렬
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

	 //삽입정렬

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (narray[i] > narray[j]) // j이전 데이터는 이미 정렬 되어있다고 가정 
				swap(narray, j, i);
		}

	}

	for (int i = 0 ;i < narray.size(); i++)
		cout << narray[i] << " ";

	return 1;
}
