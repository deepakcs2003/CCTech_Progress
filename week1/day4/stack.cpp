#include <bits/stdc++.h>
using namespace std;

int main() {

    stack<int> s;
    string str="123*+4-";
    for(char ch:str){
        if(isdigit(ch)){
            s.push(ch-'0');
        }else{
            int op2=s.top();s.pop();
            int op1=s.top();s.pop();
            if(ch=='+'){
                s.push(op1+op2);
            }else if(ch=='-'){
                s.push(op1-op2);
            }else if(ch=='*'){
                s.push(op1*op2);
            }
        }
    }
     cout << "Result: " << s.top();
    return 0;
}