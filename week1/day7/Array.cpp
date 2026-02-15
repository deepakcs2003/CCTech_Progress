#include <bits/stdc++.h>
using namespace std;

int main() {

    array<int,5> arr={20,102,102,30};
    array<int,5> arr1={1,2,3,4,5};
    cout<<"first element: "<<arr[0]<<endl;

    cout<<arr.at(0)<<endl;
    cout<<arr.at(1)<<endl;

    cout<<get<0>(arr)<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.back()<<endl;
    cout<<arr.size()<<endl;
    cout<<arr.max_size()<<endl;
    arr.swap(arr1);
    for(auto i:arr){
        cout<<i<<" ";
    }

    // cout<<arr.at(10)<<endl; array out of range
    return 0;
}