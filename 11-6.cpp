#include <string>
#include <vector>
#include <iostream>
using namespace std;

 
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int index =0;
    while(k >0)
    {
        for(int i =0 ; i < food_times.size();i++, index++)
        {
            if(food_times[index%3] > 0)
            {
                food_times[index%3]--;
                index++;
                break;
            }
            
            if(food_times[index%3] == 0)
                continue;
            
          
        }
        
        k--;
        if(isfinished(food_times) == true)
               return -1;
    }
    
    
       for(int i =0 ; i < food_times.size(); i++, index++)
        {
            if(food_times[index%3] > 0)
            {
                return (index%3 +1 );
            }
         }
    
}
