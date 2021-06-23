#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 /*
 6 11
 1
 1 2 2
 1 3 5
 1 4 1
 2 3 3
 2 4 2
 3 2 3
 3 6 5
 4 3 3
 4 5 1
 5 3 1
 5 6 2

 
 */
#define INF 1E9
using namespace std;
 
//방문여부
//bool visited[100001] = { false, };

//노드 정보
vector<pair<int, int>> graph[100001];

//최단거리테이블
int d[100001];


int main()
{

	int nnode, nedge;
	int startnode;

	cin >> nnode >> nedge;
	cin >> startnode;
	
	
	cin.ignore();

	fill(d, d + 100001, INF);

	for (int i = 0; i < nedge; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;

		graph[start].push_back({ end, value });

	}
	//시작점 표시 
	

	int minnode =-1;



	//visited[startnode] = true; //방문표시 
	
	//비용 , 노드
	priority_queue<pair<int, int>>	q;
	q.push({ 0,startnode });
	d[startnode] = 0;
	
	//시작노드 거쳐 연결된 노드로 가는 비용 
	//for (int i = 0; i < graph[startnode].size(); i++)
	//{
	//	auto v = graph[startnode][i];
	//	d[v.first] = v.second;

	//}
	while (!q.empty())
	{
		auto a = q.top();
		int node = a.second;
		int node_gain = -a.first;
		q.pop();

		//이미 처리된적 있는 노드면 무시
		if (d[node] < node_gain)
			continue;

		for (int i = 0; i < graph[node].size(); i++)
		{
			 
			if (d[graph[node][i].first] > graph[node][i].second + d[node])
			{
				d[graph[node][i].first] = graph[node][i].second + d[node];
				q.push({ -d[graph[node][i].first]  ,graph[node][i].first });
			}
			//이미처리된 노드에서 방문여부 확인 
			//visited[graph[node][i].first] = true;
			
		}

	}

	for (int i = 1; i < nnode+1; i++)
	{
		if (d[i] != 9999999)
			cout << d[i] << endl;
		else
			cout << "INF" << endl;
	}
	return 1;
}
