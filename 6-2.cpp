#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 
using namespace std;
 
 
int main()
{
	int N, K;

	cin >> N >> K;
	cin.ignore();
	vector<int> list1;
	vector<int> list2;

	
	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;
		list1.push_back(value);
	}
 
	cin.ignore();

	for (int i = 0; i < N; i++)
	{

		int value;
		cin >> value;
		list2.push_back(value);
	}


	sort(list1.begin(), list1.end());
	sort(list2.begin(), list2.end());

	for (int i = 0; i < K; i++)
	{
		int v1 = list1[i];
		int v2 = list2[N-i-1];

		list1[i] = v2;
		list2[N - i - 1] = v1;



	}

	int result = 0;
	for (int i = 0; i < N; i++)
		result += list1[i];

	cout << result << endl;
	return 1;
}
