#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

/*
 
 
1 5 4 3 2 4 5 2
*/
 
using namespace std;

int main() {
	 
	string strn;
	getline(cin ,strn);

	int nsize = strn.size()/2;
	int nlefttotal = 0;
	int nrighttotal = 0;

	for (int i = 0; i < nsize; i++)
	{
		nlefttotal += strn[i];
	}

	for (int i = strn.size(); i >= nsize; i--)
	{
		nrighttotal += strn[i];
	}


	if (nlefttotal == nrighttotal)
		cout << "LUCKY" << endl;

	else
		cout << "READY" << endl;
	return 0;
}
