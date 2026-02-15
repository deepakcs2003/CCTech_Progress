#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_set<int> us={1,2,3,4,5};
    for(auto x:us){
        cout<<x<<" ";
    }
    cout<<endl;
    us.insert(2);
    us.insert(4);
    us.erase(4);
       for(auto x:us){
        cout<<x<<" ";
    }
    cout<<endl;
    auto it=next(us.begin(),3);
    cout << *it;
    auto itr=us.find(2);
    cout<<endl;
     if (itr != us.end())
        cout << *itr;
    else
        cout << "Element not Found!";
    return 0;
}