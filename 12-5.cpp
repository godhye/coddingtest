#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
 
 
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
*/
 
using namespace std;

#include <string>
#include <vector>

using namespace std;

 
int n, k, l;
int arr[101][101]; // 맵 정보
vector<pair<int, char> > info; // 방향 회전 정보

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int turn(int direction, char c)
{

	if (c == 'L') direction = (direction == 0) ? 3 : direction - 1;
	else direction = (direction + 1) % 4;
	return direction;

}

int simulate()
{
	int x = 1, y = 1;
	arr[x][y] = 2; //뱀 존재하는 위치 2로 표시
	int diretion = 0; //처음 동쪽 보고 있음 
	int time = 0;
	int index = 0; //다음 회전할 정보
	queue<pair<int, int>> q; //뱀이 차지하고 있는 위치 정보 (꼬리가 앞쪽)
	q.push({ x, y });

	while (true)
	{
		int nx = x + dx[diretion];
		int ny = y + dy[diretion];

		//맵 범위 안에 있고  뱀 몸통이 없는 위치
		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && arr[nx][ny] != 2)
		{
			//사과 없다면
			if (arr[nx][ny] == 0)
			{
				arr[nx][ny] = 2;
				q.push({ nx,ny });
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				arr[px][py] = 0;
			}

			//사과 있다면 
			if (arr[nx][ny] == 1)
			{
				arr[nx][ny] == 2;
				q.push({ nx, ny });

			}
		}

		//벽이나 몸통과 부딪
		else 
		{
			time += 1;
			break;
		
		}

		x = nx;
		y = ny;
		time += 1;
		if (index < l && time == info[index].first) 
		{
		//회전할 시간인 경우 회전
			diretion = turn(diretion, info[index].second);
			index++;
		}
	}
	return time;

}
int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a>> b;
		arr[a][b] = 1; //사과 표시

	}

	cin >> l;

	for (int i = 0; i < l; i++)
	{
		int x;
		char c;
		cin >> x >> c;
		info.push_back({ x,c });
	}
	 

	cout << simulate() << endl;

	return 0;

}
