#include <bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(pair<int,int> a,pair<int,int>b){
        return a.second-b.second;
    }
};

int main() {

    priority_queue<int> pq;
    pq.push(3);
    pq.push(4);
    pq.push(10);
    pq.push(14);
    cout<<pq.top()<<endl;
    pq.pop();
    pq.emplace(30);
    cout<<pq.empty()<<endl;
    cout<<pq.size()<<endl;
    while(pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    priority_queue<int,vector<int>,greater<int>> maxpq;
    maxpq.push(3);
    maxpq.push(10);
    cout<<maxpq.top()<<endl;
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> customepq;
    customepq.push({1,200});
    customepq.push({10,20});
    cout<<customepq.top().first<<endl;
    return 0;
}