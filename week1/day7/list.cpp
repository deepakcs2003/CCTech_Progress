#include <bits/stdc++.h>
using namespace std;

int main() {

    
    list<int> l={1,2,3,4};
    l.push_back(2);
    l.push_front(4);
    l.pop_back();
    l.pop_front();
    cout<<l.front()<<endl;
    cout<<l.back()<<endl;
    auto it = l.begin();
    advance(it, 2);
    l.insert(it, 9);
    auto itr=next(l.begin(),3);
    cout<<*itr<<endl;
    auto fnd=find(l.begin(),l.end(),3);
    cout<<*fnd<<endl;
    auto a=l.begin();
    advance(a,3);
    l.erase(a);
    for(int x:l){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<l.size()<<endl;
    return 0;
}