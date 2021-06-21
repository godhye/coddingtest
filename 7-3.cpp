#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 
using namespace std;
 
vector<int> savedlist;
vector<int> findlist;

int binarysearch(vector<int> list, int start, int end, int target)
{
	if (start > end)
		return -1;

	int middle = (start + end) / 2;

	if (list[middle] == target)
		return target;

	else if (list[middle] > target)
		return binarysearch(list, start, middle - 1, target);
		
	else
		return binarysearch(list, middle + 1, end, target);
		
}

int main()
{
 
	int N, K;
	cin >> N  ;

	
	for (int i = 0; i < N; i++)
	{
		int c;
		cin >> c;
		savedlist.push_back(c);
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int c;
		cin >> c;
		findlist.push_back(c);
	}

	sort(savedlist.begin(), savedlist.end());

	for (int i = 0; i < K; i++)
	{
		int n = findlist[i];
		int nresult = binarysearch(savedlist, 0, savedlist.size()-1, n);


		if (nresult == -1)
			cout << "no ";
		else
			cout << "yes ";


	}


 
 ;
	return 1;

}
