#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*


7 8
1 2
1 5
2 3
2 6
3 4
4 7
5 6
6 4

*/

 
int main()
{
	int nnode, edge;
	queue< int> q;
	int indegree[1001] = { 0, };
	int visited[1001] = { 0, };
	int totalvalue = 0;
	cin >> nnode >> edge;

	vector<  int> v[1001];

	for (int i = 0; i < edge; i++)
	{
		int start, end;

		cin >> start >> end;//>> value;
		v[start].push_back( end );

		indegree[end] ++;
	}

	while (1) 
	{
		for (int i = 1; i <= nnode; i++)
		{
			if (indegree[i] == 0 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}

		if (q.empty())
			break;
		//큐에서 진입차수 0인 노드 꺼냄

		auto a = q.front();
		q.pop();

		//연결된 간선 제거
		for (int i = 0; i < v[a].size(); i++)
		{
			indegree[v[a][i]] --;

			v[a].erase(v[a].begin(), v[a].begin() + i);
		}
		//방문표시
		
		cout << a << " ";

	}
	cout << endl;
 	return 1;
}
