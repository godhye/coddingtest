#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*


7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4 
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4

*/
int parent[10001] = { 0, };

int find_parent(int n)
{
	if (n == parent[n])
		return n;
	else
		return parent[n] = find_parent(parent[n]);
}
int main()
{
	int nnode, edge;
	vector<pair<int ,pair<int, int>>> v;

	//노드당 유지비용
	int indegree[10001] = { 0, };
	int visited[10001] = { 0, };

	


	vector<int> totalvalue ;
	cin >> nnode >> edge;

	for (int i = 0; i < edge; i++)
	{
		int start, end, value;

		cin >> start >> end>> value;
		if (start < end)
		{
			v.push_back({value ,{ start , end } });
			
			}
		else
		{

			v.push_back({ value ,{ end , start } });
		}
	}

	for (int i = 1; i <= nnode; i++)
	{
		parent[i] = i;
	}
	sort(v.begin(), v.begin() + v.size());

	
	for (auto it = v.begin(); it != v.end();it++ )
	{
		auto a = it;
		int value = a->first;
		auto node = a->second;

		int m = find_parent(node.first);
		int k = find_parent(node.second);

		if (m == k)
			continue;
		else
		{
			if (m < k)
				parent[k] = m;
			else
				parent[m] = k;
			cout << value << ", ";
			totalvalue.push_back( value);
		}
	}
	int totalv =0;
	for (int i = 0; i < totalvalue.size() - 1; i++)
		totalv += totalvalue[i];

	cout << totalv;
 	return 1;
}
