#include <bits/stdc++.h>
using namespace std;

int main() {

    map<int,int> m;
    m.insert({1,2});
    m.insert({3,4});
    m.insert({4,5});
    cout<<m[1]<<endl;
    cout<<m[3]<<endl;
    cout<<m[4]<<endl;
    m.insert({10,4});
    m[3]=10;
    for(auto& p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    auto it=m.find(3);
    if(it!=m.end()){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"key not found"<<endl;
    }
    for(auto it=m.begin();it!=m.end();it++){
            cout << it->first << " " << it->second<< endl;
    }
    multimap<int,string> mm;
     mm.insert({1, "Apple"});
    mm.insert({1, "Avocado"});   
    mm.insert({2, "Banana"});
    mm.insert({1, "Apricot"}); 
     for (auto p : mm){
        cout << p.first << " -> " << p.second << endl;
     }
    
    auto range = mm.equal_range(1);
    cout<<range.first->first<<" "<<range.first->second<<endl;

    return 0;
}