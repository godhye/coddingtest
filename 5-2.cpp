#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

//음료수 얼려먹기
using namespace std;

int N, M;
int map[1000][1000] = { 1, };
int visited[1000][1000] = { 1, };
int visittotal = 0;

int dx[] = { -1 ,1 , 0 , 0 };
int dy[] = { 0 , 0 , -1 , 1 };


  
// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool dfs(int x, int y) {
	// 주어진 범위를 벗어나는 경우에는 즉시 종료
	if (x <= -1 || x >= N || y <= -1 || y >= M) {
		return false;
	}
	// 현재 노드를 아직 방문하지 않았다면
	if (map[x][y] == 0) {
		// 해당 노드 방문 처리
		map[x][y] = 1;
		// 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

//bool dfs(int i, int j)
//{
//	cout << "dfs i = " << i << " j = " << j << endl;
//	//틀이면 false 
//	if (map[i][j] == 1)
//		return false;
//
//	
//		if (i <= -1 || i >= N || j <= -1|| j >= M)
//			return false;
//
//		if (map[i][j] == 0)
//		{
//			cout <<  "i = "<< i << " j == "<< j << endl;
//			map[i][j] == 1; //방문표시
//
//			dfs(i - 1, j);
//			dfs(i + 1, j);
//			dfs(i, j - 1);
//			dfs(i, j + 1);
//			return true;
//		}
//		return false;
//
//}


int main()
{
	
	int result = 0;
	cin >> N >> M;
	cin.ignore();

	
	string rows;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			int c;
			scanf("%1d", &map[i][k]);
			 
			
		}
	}
	 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			bool bresult = dfs(i, j);
			if (bresult)
				result++;
		}
	}
	 
	cout << result << endl;
	return 1;
}
