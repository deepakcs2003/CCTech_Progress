#include <iostream>
#include <string>
using namespace std;
int main(){
    string s="deepak";
    s.append(" vishwakarma");
    cout<<s<<endl;
    cout<<s.length()<<endl;
    cout<<s[3]<<endl;
    cout<<s.substr(1,2);

    return 0;
}