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
 
 
 
int main()
{

	int nnode, nedge;
	int startnode;

	cin >> nnode >> nedge;
	cin >> startnode;
	cin.ignore();

	 
	int graph[501][501];
	//본인노드  본인 노드 0으로 초기화
	for (int i = 1; i <= nnode; i++)
	{
		fill(graph[i], graph[i] + 1000, INF);
	}

	

	for (int i = 0; i < nedge; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;

		graph[start][end ] = value;

	}
	//본인노드  본인 노드 0으로 초기화
	for (int i = 1; i <= nnode; i++)
	{
		graph[i][i] = 0;
	}
	
	//
	for (int i = 1; i < nnode+1; i++)
	{

		for (int j = 1; j < nnode + 1; j++)
		{
			for (int k = 1; k < nnode + 1; k++)
			{

				graph[j][k] = min(graph[j][k], (graph[j][i] + graph[i][k]));

			}
		}

	}

	for (int i = 1; i <= nnode; i++)
	{
		for (int j = 1; j<= nnode; j++)
		{

			if (graph[i][j] == INF)
				cout << INF << " ";
			else
				cout << graph[i][j] << " " ;
		}
		cout << endl;
	}
	 
	return 1;
}
