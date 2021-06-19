#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//게임개발
using namespace std;


int xsize, ysize;

//방문한 위치 저장 맵
int d[50][50] = {0, };

//전체 맵 정보
int arr[50][50];

//북 동 남 서 방향 정의 
int dx[] = { -1, 0 , 1, 0 };
int dy[] = { 0,1,0,-1 };

int curpointx;
int curpointy;
int curdirect;

void turn_left()
{
	curdirect -= -1;
	if (curdirect == -1)
		curdirect = 3;
}

int main()
{
	cin >> xsize >> ysize;
	cin.ignore();

	cin >> curpointx >> curpointy >> curdirect;

	//현재 있는 위치 방문 표시 
	d[curpointx][curpointy] = 1;

	for (int x = 0; x < xsize; x++)
	{
		for (int y = 0; y < ysize; y++)
		{
			int c;
			cin >> c;
			arr[x][y] = c;
		}
	}

	int cnt = 1;
	int turn_time = 0;
	while (1)
	{
		 
		turn_left();
		int nx = curpointx + dx[curdirect];
		int ny = curpointy + dy[curdirect];

		 
		if (d[nx][ny] == 0 && arr[nx][ny] == 0)
		{
			 
			d[nx][ny] = 1;

			curpointx = nx;
			curpointy = ny;
			cnt += 1;
			turn_time = 0;
			continue;
		}

		else turn_time += 1;
		
		if (turn_time == 4)
		{
			nx = curpointx - dx[curdirect];
			ny = curpointy - dy[curpointy];

			if (arr[nx][ny] == 0)
			{
				curpointx = nx;
				curpointy = ny;
			}
		
		else break;
		turn_time = 0;
		}
	}

	
	printf("%d", cnt);
	return 1;

}
