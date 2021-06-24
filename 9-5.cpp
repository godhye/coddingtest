#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 /*
 
3 2 1
1 2 4
1 3 2
 
 
 */

#define INF 1E9
using namespace std;

vector<pair<int, int>>graph[30001];

int d[30001];
int main()
{


	fill(d, d + 30001, INF);

	int nnode, nedge, startnode;
	cin >> nnode >> nedge >> startnode;

	for (int i = 0; i < nedge; i++)
	{
		int X, Y, Z;
		cin >> X >> Y >> Z;

		graph[X].push_back({ Y,Z });
	}

	d[startnode] = 0;

	priority_queue<pair<int, int>> q;

	q.push({ 0, startnode });

	while (!q.empty())
	{
		auto a = q.top();
		int node = a.second;
		int nodevalue = -a.first;
		q.pop();

		if (d[node] < nodevalue)
			continue;

		for (int i = 0; i < graph[node].size(); i++)
		{
		
			if (d[graph[node][i].first] > graph[node][i].second + d[node])
			{
				d[graph[node][i].first] = graph[node][i].second + d[node];
				q.push({ -d[graph[node][i].first], graph[node][i].first });
			}
			

		}
	}

	//연결된 갯수 , 도시들이 모두 메세지 받는데 걸리는 시간 
	int nnoderesult = 0;
	int totalvalue = 0;
	for (int i = 1; i <= nnode; i++)
	{
		if (d[i] != INF)
		{
			nnoderesult++;
			totalvalue = max(d[i] , totalvalue);
		}
	}

	cout << nnoderesult-1 << " , " << totalvalue << endl;


 	return 1;
}
