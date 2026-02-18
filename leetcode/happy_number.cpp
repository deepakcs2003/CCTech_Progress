#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int val=n;
        while(!s.count(val)){
            int num=0;
            s.insert(val);
            while(val>0){
                int rem=val%10;
                num+=rem*rem;
                val/=10;
            }  
            if(num==1){
                return true;
            } 
            val=num;    
        }
        return false;
    }
};
int main() {

    

    return 0;
}