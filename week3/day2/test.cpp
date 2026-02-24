#include<iostream>
using namespace std;
template<typename T>
class Cal{
    T a;
    T b;
    public:
    Cal(T a,T b):a(a),b(b){};
    T add(){
        return a+b;
    }
};
int main(){
    Cal<int> c(2,3);
    int ans=c.add();
    cout<<ans;
    return 0;
};