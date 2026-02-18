#include <bits/stdc++.h>
using namespace std;
namespace outer{
    int max(int a,int b){
        if(a>b){
            return a;
        }else{
            return b;
        }
    }
    namespace inner{
        int min(int a,int b){
            if(a>b){
                return b;
            }else{
                return a;
            }
        }
    }
}
using namespace outer;


int main() {

    cout<<max(12.3,23.3)<<endl;
    cout<<inner::min(2,4)<<endl;
    cout<<max(12.3,23.3)<<endl;
    return 0;
}