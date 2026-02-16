#include <bits/stdc++.h>
using namespace std;

// funtion tempalte
template <typename T> constexpr T pi=3.14;
template <typename T> T myFun(const T &x,const T &y){
    return (x>y)?x:y;
} 
int fun(int &a,int &b){
    return (a>b)?a:b;
}
// class template
template<typename T1,typename T2=string> class deep{
    public:
    T1 x;
    T2 y;
    deep(T1 val1,T2 val2):x(val1),y(val2){
        cout<<"contrutor is created"<<endl;
    }
    void print(){
        cout<<x<<" "<<y<<endl;
    }
};

//Template Non-Type Arguments
template<class T,int max> int arrMin(T arr[],int n){
    int m=max;
    for(int i=0;i<n;i++){
        if(arr[i]<m){
            m=arr[i];
        }
    }
    return m;
}
int main() {

    
   cout<<myFun<int>(3,4)<<endl;
   cout<<myFun<double>(4.5,2.4)<<endl;
   cout<<myFun<char>('e','u')<<endl;
   int a=3,b=4;
   cout<<fun(a,b)<<endl;
   deep<int> d1(3,"ashish");

   d1.print();
   deep<int,string> d2(21,"deepak");
   d2.print();
   cout<<"pi is double: "<<pi<double><<endl;
   cout<<"pi is float: "<<pi<double><<endl;
   cout<<"pi is int: "<<pi<int><<endl;

   int arr1[] = {10, 20, 15, 12};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    char arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << arrMin<int, 10000>(arr1, n1) << endl;
    cout << arrMin<char, 256>(arr2, n2)<<endl;

    cout<<max(2,3)<<endl;
    cout<<myFun(3,5)<<endl;

    
    return 0;
}