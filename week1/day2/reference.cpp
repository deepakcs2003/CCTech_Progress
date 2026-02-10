#include <iostream>
using namespace std;
int main(){
    int val=10;
    int& ref=val;
    cout<<val<<endl;
    ref=20;
    cout<<val<<endl;
}