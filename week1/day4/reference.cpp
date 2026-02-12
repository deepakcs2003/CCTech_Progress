#include <bits/stdc++.h>
using namespace std;

int calByValue(int x){
    x++;
    return x;
}
int callByRef(int &x){
    x++;
    return x;
}
int swapCallByValue(int a,int b){
    int t=a;
     a=b;
    b=t;
}
int callByRefConst(const int &x){
    return (x+1);
}
int swapCallByRef(int &a,int &b){
    int t=a;
     a=b;
     b=t;
}
int main() {

    int i=10;
    int &j=i;
    i++;
    j++;
    cout<<i<<" "<<&i<<" "<<j<<" "<<&j<<endl;

    // wrong way
    // int &r=10;
    // int &r;

    const int &r=10;
    cout<<r<<" "<<&r<<endl;

    int a=10;
    int b=20;
    const int &c=a+b;
    cout<<c<<" "<<&c<<endl;
    int x=10;
    cout<<x<<" "<<calByValue(x)<<endl;
    cout<<x<<" "<<callByRef(x)<<endl;

    cout<<a<<" "<<b<<" after swap "<<endl;
    swapCallByValue(a,b);
    cout<<a<<" "<<b<<endl;
    swapCallByRef(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}