#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 
using namespace std;
int N, K;
int cnt = 0;
//이진탐색
bool binarysearch(vector<int> list, int start, int end)
{
	int middle = (start + end) / 2;
	cnt++;

	if (list[middle] == K)
		return cnt;

	else if (list[middle] > K)
		return binarysearch(list, start, middle - 1);
	else
		return binarysearch(list,  middle+1 , end);
}


int main()
{
 

	cin >> N >> K;

	vector <int> list;
	for (int i = 0; i < N; i++)
	{
		int c;
		cin >> c;
		list.push_back(c);
	}

	binarysearch(list, 0, list.size() - 1);

	cout << cnt << endl;
	return 1;

}
