#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <unordered_set>
#include <string>
#include <vector>
 
using namespace std;
 
int map[201][10001] ;

#define MAX 100000;

class Virus 
{
public:
	int index; //바이러스값
	int second; //현재초
	int x;
	int y;

	Virus(int index, int second, int x , int y)
	{
		this->index = index;
		this->second = second;
		this->x = x;
		this->y = y;

	}

	bool operator <(Virus &other) {
		return this->index < other.index;
	
	}

};

int dx[] = { 0 , 0 , -1 ,1 };
int dy[] = { 1,-1, 0 ,0 };

int main()
{
	vector<Virus> virues;
	int m, n;

	cin >> m >> n;
	int count = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int value;
			cin >> value;

			map[i][j] = value;

			if (!value)
			{
				virues.push_back(Virus(value,0, i, j));
			}
		
		}
	}
	
	int second, X, Y;
	cin >> second >> X >> Y;

	//바이러스 숫자로 정렬
	sort(virues.begin(), virues.end());

	//방문하지않은 곳
	queue<Virus> q;

	for (int i = 0; i < virues.size(); i++)
	{
		q.push(virues[i]);
	}

	while (!q.empty())
	{
		Virus virus = q.front();
		q.pop();

		//second 만큼 초가 지나거나 , 큐가 빌떄까지 반복
		if (virus.second == second)
			break;

		//현재노드 기준 상하좌우 확인

		for (int i = 0; i < 5; i++)
		{
			int nx = virus.x + dx[i];
			int ny = virus.y + dy[i];


			if (0 < nx && nx < n && 0 < ny && ny < m)
			{
				if (map[nx][ny] != 0)
				{
					map[nx][ny] = virus.index;
					virues.push_back(Virus(virus.index , virus.second++ , nx ,ny));
				}
			}
		}

	}

	cout << map[X][Y] << endl;
	//타겟 초 되면 출력
}
