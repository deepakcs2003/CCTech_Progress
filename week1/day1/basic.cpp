#include <iostream>
#include <array>
using namespace std;
int main(){
    cout << "hello world" << endl;
    const int max=1e10;
    cout<< "Max value: " << max << endl;
    int x=10;
    float y=3.14;
    int i=static_cast<int>(y);
    cout << "Integer value of y: " << i << endl;
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Size of array: " << size << endl;
    char z='A';
    bool isTrue=true;
    int* p=&x;
    cout<< "x: " << x << endl;
    cout<< "y: " << y << endl;
    cout<< "z: " << z << endl;
    cout<< "isTrue: " << isTrue << endl;
    cout<< "Pointer p points to value: " << p << endl;
    cout<< "hello\nworld" << endl;
    cout<< sizeof(int) << endl;
    int a=10;
    int b=20;
    int res=a>b?a:b;
    cout << "Max of a and b: " << res << endl;
    return 0;
}