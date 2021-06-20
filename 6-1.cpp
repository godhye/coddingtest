#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

//성적 낮은순서
using namespace std;
 

class Student {
public:
	string name;
	int score;
	Student(string name, int score)
	{
		this->name = name;
		this->score = score;
	}

	bool operator <(Student &Other) {
		return this->score < Other.score;
	}


};
int main()
{
	int total;
	cin >> total;
	cin.ignore();

	vector<Student > list;

	for (int i = 0; i < total; i++)
	{
		string line;
		int score;
		 
		cin >> line >> score;
		list.push_back(Student( line, score ));
	}

	sort(list.begin(), list.end());

	for (int i = 0; i < total; i++)
		cout << list[i].name << endl;



	return 1;
}
