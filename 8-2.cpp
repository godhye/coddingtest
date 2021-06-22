#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

 
using namespace std;
 
 
int cntarray[30001] = { 0, };
vector<int> vsize;

int main()
{

	int n;
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int size;
		cin >> size;

		vsize.push_back(size);
	}
	 
	while (1)
	{
		int max = 0;
		int maxindex = -1;

		if (vsize.size()<= 1)
			break;


		for (int i = 0; i < vsize.size(); i++)
		{
			if (max < vsize[i])
			{
				max = vsize[i];
				maxindex = i;
			}

		}
		 

		result += vsize[maxindex];
		cout << maxindex << vsize[maxindex] << endl;

	
 
		
		if (maxindex + 1 < vsize.size() && vsize.size() != 1)
		{
			vsize.erase(vsize.begin() + maxindex+1);
		}
		// 양옆 , 해당 칸 0으로
		vsize.erase(vsize.begin() + maxindex);
		if (maxindex - 1 >= 0 && vsize.size() != 1)
		{
			vsize.erase(vsize.begin() + maxindex - 1);
		}
	}
	cout << result;

	return 1;
}
