#include <iostream>
using namespace std;
double inc(int& x){
    x++;
    return x;
}
int add(int a,int b){
    return a+b;
}
double add(double a,double b){
    return a+b;
} 

int fac(int a){
    if (a<=1){
        return a;
    }
    return a*fac(a-1);
}
int main(){
    cout<<"hello deepak"<<endl;
    int n;
    cin >> n;
    cout<<n;
    int x=10;
    int y=20;
    cout<<add(1,3)<<endl;
    cout<<add(2.2,1.4)<<endl;
    cout<<fac(5)<<endl;
    return 0;
}
