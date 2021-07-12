#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
 
 
K1KA5CB7
*/
 
using namespace std;

int main() {
	 
	string strn;
	getline(cin ,strn);

	priority_queue<pair<int , char>> q;

	int ntotal = 0;

	for (int i = 0; i < strn.size(); i++)
	{
		if (strn[i] > 47 && strn[i] < 58) //숫자이면 유니코드표 참고
			ntotal += strn[i] - 48;

		else if (strn[i] > 64 && strn[i] < 91) //알파벳이면
		{
			int nvalue =-( strn[i]); //최소힙 동작위해 
			 
			q.push({ nvalue ,strn[i] }); // 정렬위해 힙에 넣어줌 
		}
	}

	 
	while (!q.empty())
	{
		auto a = q.top();
		q.pop();
		
			printf("%c", a.second);
	}

	printf("%d\n", ntotal);
	return 0;
}
