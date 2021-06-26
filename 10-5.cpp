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
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

*/
 
int main()
{
	int nnode;
	
	//노드당 비용
	int indegree[10001] = { 0, };
	vector<int> info[10001];
	queue<int > q;
	int hour[10001] = {};


	int totalvalue=0 ;
	
	cin >> nnode ;

	for (int i = 1; i <= nnode; i++)
	{
		int v;
		cin >> v;
		hour[i] = v;
		cin >> v;
		while (v != -1)
		{
			
			info[v].push_back(i);
			indegree[i]++; //진입차수
			cin >> v;
		}

	}

	for (int i = 1; i <= nnode; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			
		}
	}

	while (!q.empty())
	{

		auto a = q.front();
		q.pop();
		 

		//시간 더해주기
		

		int  maxhour = 0;

		for (int i = 0; i < info[a].size(); i++)
		{


			auto b = info[a][i];
 
			indegree[b] --;
			if (indegree[b] == 0)
			{
				q.push(b);
				hour[b]= hour[a]+ hour[b];
			}
		}
	 
	}

	for (int i = 1; i <= nnode; i++)
		cout << hour[i] << endl;


 	return 1;
}
