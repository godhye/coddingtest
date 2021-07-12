#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
 
    
    for(int i =1 ; i < s.size()/2+1 ; i++)
    {
        string compressed = "";
        string nstr = s.substr(0,i);
        int cnt =1;
        for(int j =i ; j < s.size(); j+=i)
        {
            if(nstr == s.substr(j, i)) cnt +=1;
            else
            {
                compressed +=(cnt >=2)? to_string(cnt)+nstr :nstr;
                nstr = s.substr(j,i);
                cnt = 1;
            }
        }
        compressed += (cnt >=2)? to_string(cnt) + nstr : nstr;
        answer = min(answer , (int)compressed.size());
    }
    return answer;
}
