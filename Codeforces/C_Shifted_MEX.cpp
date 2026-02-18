#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;
    while (t-->0)
    {
        int n;
        cin>>n;
        vector<int> v;
        set<int> s;
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            if(!s.count(num)){
                v.push_back(num);
            }
            s.insert(num);
        }
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        int st=0;
        int ans=0;
        sort(v.begin(),v.end());
        int i;
        for(i=1;i<v.size();i++){
            int pre=v[i-1];
            int curr=v[i];
            if(pre+1!=curr){
                ans=max(ans,(v[i-1]-v[st])+1);
                st=i;
            }
        }
        ans=max(ans,(v[i-1]-v[st])+1);
        cout<<ans<<endl;
    }
    

    return 0;
}