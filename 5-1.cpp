#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

//DFS BFS구현
using namespace std;

int visited[9] = { 0, };
vector<int> graph[9];
queue<int> q;
void dfs(int start)
{

	visited[start] = 1;
	cout << start << endl;
	for (int i = 0; i < graph[start].size(); i++)
	{
		int value = graph[start][i];
		if (!visited[value])
			dfs(value);
	}
	 
}

void bfs(int node)
{
 
	visited[node] = 1;
	q.push(node);

	while (q.size() > 0 )
	{
		int v = q.front();
		q.pop();
		node = v;

		for (int i = 0; i < graph[node].size(); i++)
		{
			int value = graph[node][i];
			if (!visited[value])
			{
				q.push(value);
				visited[value] = 1;
			}
		}

		
		
		cout << node << endl;
	}
	//
}

int main()
{
	
	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(8);

	// 노드 2에 연결된 노드 정보 저장 
	graph[2].push_back(1);
	graph[2].push_back(7);

	// 노드 3에 연결된 노드 정보 저장 
	graph[3].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);

	// 노드 4에 연결된 노드 정보 저장 
	graph[4].push_back(3);
	graph[4].push_back(5);

	// 노드 5에 연결된 노드 정보 저장 
	graph[5].push_back(3);
	graph[5].push_back(4);

	// 노드 6에 연결된 노드 정보 저장 
	graph[6].push_back(7);

	// 노드 7에 연결된 노드 정보 저장 
	graph[7].push_back(2);
	graph[7].push_back(6);
	graph[7].push_back(8);

	// 노드 8에 연결된 노드 정보 저장 
	graph[8].push_back(1);
	graph[8].push_back(7);

	//dfs( 1);
	bfs(1);
	return 1;

}
