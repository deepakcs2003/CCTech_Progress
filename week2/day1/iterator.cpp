#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v={10,20,30,40};
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it <<" ";
    }
    cout<<endl;

    cout<<"forward iterator"<<endl;
    for(auto it=v.begin();it!=v.end();it++){
        if(*it%20==0){
            *it-=5;
        }
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"forward(read only) iterator"<<endl;
    for(auto it=v.cbegin();it!=v.cend();it++){
        cout<<*it<<" ";
    }

    cout<<endl;
    cout<<"reverse iterator"<<endl;
    for(auto it=v.rbegin();it!=v.rend();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    auto it1=v.begin();
    cout<<"befor updating: "<<*it1<<endl;
    *it1=21;
    cout<<"after updating: "<<*it1<<endl;
    ++it1;
    cout<<"after increament: "<<*it1<<endl;
    --it1;
    cout<<"after decreament: "<<*it1<<endl;
    it1=it1+2;
    cout<<"adding :"<<*it1<<endl;
     it1=it1-2;
    cout<<"minus :"<<*it1<<endl;
    auto it2=v.begin()+2;
    cout<<"distance between iterator: "<<it2-it1<<endl;
    return 0;

}