#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//상하좌우
using namespace std;

int main()
{
	int size;
	string direction;
	int x = 1;
	int y = 1;

	char movetype[4] = { 'L','R','U','D' };

	int dx[4] = { 0,0 , -1, 1};
	int dy[4] = {-1, 1, 0, 0};

	cin >> size;

	//버퍼 비우기
	cin.ignore();

	getline(cin, direction);


	for (int i = 0; i < direction.size(); i++)
	{
		char plan;
		plan = direction[i];

		for (int k = 0; k < 4; k++)
		{
			if (plan == movetype[k])
			{
				if(x + dx[k] > 1)
				x = x + dx[k];

				if(y + dy[k] > 1)
				y = y + dy[k];

				
				break;
			}
		}


	}

	printf("x %d  y %d ", x, y);

	return 1;

}
