#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*


6 4
1 4
2 3
2 4
5 6

*/

int parent[101];
int find_parent(int n)
{

	if (parent[n] == n)
		return parent[n];
	return parent[n] = find_parent(parent[n]);
	 
	
}
int main()
{
	int nnode , edge;
	vector<pair<int, int>> info;
	cin >> nnode >>  edge;

	for (int i = 0; i < edge; i++)
	{
		int start, end;

		cin >> start >> end;
		info.push_back({ start,end });
	}

	//parent 본인으로 초기화
	for (int i = 1; i <= nnode; i++)
		parent[i] = i;

	bool bCycle;
	for (auto it = info.begin(); it != info.end(); it++)
	{

		 
		int a = find_parent(it->first);
		int b = find_parent(it->second);
		
		//사이클 유무 확인 
		if (a == b)
		{
			bCycle = true;
			return 1;
		}

		if (a < b)
			parent[it->second] = a;
		else
			parent[it->first] = b;
	}

	// 각 원소가 속 한 집합
	
	for (int i = 1; i <= nnode; i++)
		cout <<find_parent(i);

	cout << endl;

	//부모 테이블
	for (int i = 1; i <= nnode; i++)
	{
		cout << parent[i] << " ";
	}

 	return 1;
}
