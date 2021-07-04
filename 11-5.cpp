#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
 
8 5
1 5 4 3 2 4 5 2
*/
 
using namespace std;

int main() {
	int n,m;
	cin >> n >> m; //n의 숫자수 , m은 최대무게 
	vector<int> v;
	int result = 0;
	int weigharray[10] = { 0 ,};
	for (int i = 0; i < n; i++)
	{
		int inum;
		cin >> inum;
		v.push_back(inum);
	}

	//무게별로 몇개있는지 확인
	for (int i = 0; i < n; i++)
		weigharray[v[i]]++;


	for (int i = 1; i < m; i++)
	{
		n -= weigharray[i];
		result += weigharray[i] * n;
	}

	cout << result;
	return 0;
}
