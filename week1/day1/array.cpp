#include <iostream>
using namespace std;


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "You entered: " << n << endl;
    int arr[n]={};
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        arr[i]=i;
        cout<<arr[i]<<" ";
    }
    cout<<arr<<endl;
    return 0;
}
