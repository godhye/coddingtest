#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//왕실의나이트
using namespace std;

int main()
{
	int result = 0;
	char pointx;
	int pointy;
	int cur_x;
	int cur_y;
	char x[8] = { 'a','b','c','d','e','f','g' };
	scanf("%c%d", &pointx, &pointy);

	for (int i = 0; i < 8; i++)
	{
		if (x[i] == pointx)
			cur_x = i +1 ;
	}
	cur_y = pointy;

	int xmove[8] = { 2 ,2 ,-2,-2,1,-1,1,-1 };
	int ymove[8] = { 1,-1,1,-1,2,2,-2,2 };
	printf("x %d y %d \n", cur_x, cur_y);


	for (int i = 0; i < 8; i++)
	{
		int dx;
		int dy;

		dx = cur_x + xmove[i];
		dy = cur_y + ymove[i];

		if (dx < 1 || dx >8 || dy < 1 || dy >8)
			continue;

		printf("ith %d  x %d y %d \n",i, dx, dy);
		result++;

	}

	printf("%d ", result);
	return 1;

}
