#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//시각   
using namespace std;

int main()
{
	 
	int hour;
	int result = 0;
	string current;
	cin >> hour;
	cin.ignore();

	for (int h = 0; h <= hour; h++)
	{
		for (int m = 0; m < 60; m++)
		{
			for (int s = 0; s < 60; s++)
			{
				//h / 10 ==3 체크하지 않는 이유는 30이상 되지 않으니깐
				if ( h % 10 == 3 || m % 10 == 3 || m / 10 == 3 || s % 10 == 3 || s / 10 == 3)
				{
					printf("%d %d %d\n", h, m, s);
					result++;
				}
			}
		}
	}
	cout << result;

	return 1;

}
