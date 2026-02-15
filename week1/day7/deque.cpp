#include <bits/stdc++.h>
using namespace std;

int main() {

    deque<int> d={1,2,3,4};
    d.push_back(2);
    d.push_front(3);
    d.pop_back();
    d.pop_front();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    cout<<d[0]<<endl;
    cout<<d.size()<<endl;
    cout<<d.empty()<<endl;
    d.clear();
    d.insert(d.begin()+3,3);
    d.erase(d.begin()+3);
    return 0;
}