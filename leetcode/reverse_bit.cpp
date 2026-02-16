#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int reverseBits(int n) {
        string s;
        while(n>0){
            int rem=n%2;
            n/=2;
            s.append(to_string(rem));
        }
        while(s.size()<32){
            s.append(to_string(0));
        }
        reverse(s.begin(),s.end());
        int ans=0;
        for(int i=0;i<s.size();i++){
            char ch=s.at(i);
            if(ch=='1'){
                ans+=(1<<i);
            }
        }
        cout<<s<<endl;
        cout<<ans<<endl;
        return 0;
    }
};
int main(){
    Solution sol;
    sol.reverseBits(43261596);
    return 0;
}