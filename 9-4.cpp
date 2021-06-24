#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 /*
5 7
1 2
1 4
1 3
2 4
3 4
3 5
4 5
4 5

 
 */
#define INF 1E9
using namespace std;
 
//방문여부
//bool visited[100001] = { false, };

//노드 정보


//최단거리테이블



int main()
{
	int graph[101][101];
	int start, nedge;
	int x, k;

	//최단거리 맵 초기화
	for (int i = 0; i < 101; i++)
		fill(graph[i], graph[i] + 101, INF);
	 
	cin >> start >> nedge;
	 

	for (int i = 0; i < nedge; i++)
	{
		int start, end;
		cin >> start >> end;
		graph[start][ end] = 1;
		graph[end][start] = 1;

	}
  
	
	cin >> x >> k;

  
	for (int i = 1; i <= start; i++)
	{
		graph[i][i] = 0;
	}

	for (int i = 1; i < start + 1; i++)
		for (int j = 1; j < start + 1; j++)
			for (int k = 1; k < start + 1; k++)
				graph[j][k] = min(graph[j][k], (graph[j][i] + graph[i][k]));


	//출력
	if (graph[1][k] + graph[k][x] >= INF)
		cout << -1;
	else
	cout << graph[1][k]  << " , " << graph[k][x];
	return 1;
}
