#include "bits/stdc++.h"

using namespace std;

int main(){
    string strn;
    cin>>strn;
    int result0 =0;
    int result1 =0;
    
 
    for(int i =0; i<strn.length()-1;i++)
    {
        //1뒤집기
        if((int(strn[i])-48 != 0 )&& int(strn[i+1])-48 ==0)
            result0++;
         //0뒤집기
        if(int(strn[i])-48 != 1 && int(strn[i])-48 == 1)
        result1++;
        
    }
 
    cout <<min(result0 , result1);
    return 0;
}
