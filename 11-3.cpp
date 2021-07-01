#include "bits/stdc++.h"

using namespace std;

int main(){
    string strn;
	cin >> strn;
	int result0 = 0; //0뒤집기
	int result1 = 0; //1뒤집기
    
    //첫번째 문자열에 대해서 처리하기
    if(strn[0] -48  == 0)
        result1++;
    else
       result0++; 
    
	for (int i = 0; i<strn.length() - 1; i++)
	{
		//1뒤집기
		if (int(strn[i]) != int(strn[i + 1]) )
            {
                if((strn[i+1] -48) == 1)
                    result0++;
                else
                    result1++;
                
            }

	}

	cout << min(result0, result1);
	return 0;
}
