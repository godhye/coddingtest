#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*


7 9
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25

*/

int parent[101];
 
int find_parent(int n)
{
	if (parent[n] == n)
		return n;
	else
		return parent[n] = find_parent(parent[n]);
}
int main()
{
	int nnode , edge;
	vector<pair<int, int>> info[1001];
	priority_queue<pair<int, int>> q;
	 
	int totalvalue =0;
	cin >> nnode >> edge;

	for (int i = 0; i < edge; i++)
	{
		int start, end, value;

		cin >> start >> end >> value;
		info[start].push_back({  end, value });
		q.push({ -value , start });
	}

	for (int i = 1; i <= nnode; i++)
	{
		parent[i] = i;
	}



	//value 순으로 정렬
	while (!q.empty())
	{
		//작은거 순대로 뽑아서 
		auto node = q.top();
		q.pop();

		int value =  -(node.first);
		int nnode = node.second;

		for (int i = 0; i < info[nnode].size(); i++)
		{
			auto node = info[nnode][i];

			int end = node.first;
			int infovalue = node.second;
			if (infovalue == value)
			{
				int m = find_parent(nnode);
				int p = find_parent(end);
				//사이클 여부 확인 
				if (m == p)
					continue;

				if (m < p)
					parent[p] = m;
				else
					parent[m] = p;
				
				totalvalue += infovalue;
				cout << infovalue << " = " << nnode << ", " << end << endl;
			}
		}
	}
	

	cout << totalvalue;

 	return 1;
}
