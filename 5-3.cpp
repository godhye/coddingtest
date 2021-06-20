#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

//미로탈출
using namespace std;

int N, M;
int map[200][200] = { };
 
 
int main()
{
	queue < pair<int, int>> q;

	int result = 0;
	cin >> N >> M;
	cin.ignore();


	string rows;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			int c;
			//1이 갈수있는 길 , 0 몬스터
			scanf("%1d", &map[i][k]);

		}
	}

	int dx[] = { -1 , 1 , 0 , 0 };
	int dy[] = { 0, 0 , -1 ,1 };
	 
	 
	int i = 0, j = 0;
	q.push({ i , j });
	while(!q.empty())
	{

		i = q.front().first;
		j = q.front().second;

		q.pop();
		for (int rotate = 0; rotate < 4; rotate++)
		{
			int nx = i + dx[rotate];
			int ny = j + dx[rotate];


			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (map[nx][ny] == 1)
			{
				q.push({ nx, ny });
				map[nx][ny] = map[i][j] + 1;
			}

		}
			 

			 
	
	}
		
	 
	cout << map[N-1][M-1] << endl;
	return 1;
}
