#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
bool compare(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    long long sum=0;
    for(int i=0;i<food_times.size();i++){
        sum+=food_times[i];
    }
    if(sum<=k) return -1;

    priority_queue<pair<int,int>> pq;
    for(int i=0;i<food_times.size();i++){
        pq.push({-food_times[i],i+1}); // 최소힙
    }

    sum=0;
    long long previous=0;
    long long length=food_times.size();
    while(sum+((-pq.top().first - previous)*length)<=k){
        int now=-pq.top().first;
        pq.pop(); //다먹음
        sum+=(now-previous)*length;
        length-=1;
        previous=now;
    }
    vector<pair<int,int>> result;
    while(!pq.empty()){
        int food_time=-pq.top().first;
        int num=pq.top().second;
        pq.pop();
        result.push_back({food_time,num});
    }
    sort(result.begin(),result.end(),compare);
    return result[(k-sum)%length].second;

}
