#include <bits/stdc++.h>
using namespace std;

class Math 
{
    private:
    int val;
    public:
    virtual const int fun( int &a,const int &b)
    {
        val=100;
        int sum=a+b;
        a=10;
        cout<<sum<<endl;
        return sum;
    }
};
// class DeriveMath:public Math{
//     public:
//     const int fun(int &a,int &b ) override{

//     }
    
// };


int main() {
    const int pi=3.14;
    cout<<pi<<endl;
    int a=3;
    int b=5;
    Math m;
    m.fun(a,b);
    return 0;
}