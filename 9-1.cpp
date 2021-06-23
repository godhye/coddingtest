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
bool visited[100001] = { false, };

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
	d[startnode] = 0;

	int minnode =-1;


	//시작노드 거쳐 연결된 노드로 가는 비용 
	for (int i = 0; i < graph[startnode].size(); i++)
	{
		auto v = graph[startnode][i];
		d[v.first] = v.second; 

	}
	visited[startnode] = true; //방문표시 

	
	for (int i = 0; i < nnode - 1; i++)
	{	
		int minvalue = 9999999;

		//방문하지 않은 노드중에서 최단 거리가 가장 짧은 노드 선택
		for (int i = 1; i <= nnode; i++)
		{
			if (!visited[i])
			{
				if (minvalue > d[i])
				{
					minvalue = d[i];
					minnode = i;
					visited[minnode] = true;
				}
			}
		}

		//연결된 노드 최단 거리 초기화
		for (int i = 0; i < graph[minnode].size(); i++)
		{
			auto v = graph[minnode][i];
		

			if(d[v.first] > v.second + d[minnode] )
			d[v.first] = v.second + d[minnode]; //minnode를 거쳐 연결된 노드로 가는 비용 
			
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
