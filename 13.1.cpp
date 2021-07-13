#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
 
 
 4 4 2 1
 1 2
 1 3
 2 3
 2 4
*/
 
using namespace std;

#include <string>
#include <vector>
 
#define INF 1999999999999
 

vector<int> map[300001];
int visited[300001] = { 0, };
vector<int> depth(300001 , -1);


int currentdepth = 0;

int main() {


	int mapsize;
	int roadsize;
	int targedepth;
	int startnode;
	queue<int> q;

	cin >> mapsize >> roadsize >> targedepth >> startnode;

	for (int i = 0; i < roadsize; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
	}

	//bfs
	depth[startnode] = 0;

	q.push(startnode);
 

	int result = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < map[now].size(); i++)
		{
			int nextnode = map[now][i];
			if (depth[nextnode] == -1)
			{
				depth[nextnode] = depth[now] + 1;
				q.push(nextnode);
			}
		}

	}

	bool check= false;
	for (int i = 1; i <= mapsize; i++)
	{
		if (depth[i ] == targedepth)
		{
			check = true;
			cout << i  << " ";
		}
	 
	}

	if (!check)
		cout << "-1";
	
return 0;

}
