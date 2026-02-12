#include <bits/stdc++.h>
using namespace std;

bool compare(int a,int b){
    return a>b;
}

struct student
{
    string name;
    int marks;
};

bool studentCompre(student s1,student s2){
    return s1.marks<s2.marks;

};
int main() {

    int arr[]={2,3,1,4,3};
    sort(arr,arr+5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;

    sort(arr,arr+5,compare);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
        cout<<endl;

    student s[]={
        {"deepak",23},
        {"ashish",34},
        {"magam",45}
    };
    sort(s,s+3,studentCompre);
    for(int i = 0; i < 3; i++){
        cout << s[i].name << " " << s[i].marks << endl;
    }

    int* a=lower_bound(arr,arr+5,3);
    int* b=upper_bound(arr,arr+5,3);

    cout << "Lower index: " << arr[(a - arr)] << endl;
    cout << "Upper index: " << arr[(b - arr)] << endl;
    replace(arr,arr+5,3,10);
    rotate(arr,arr+2,arr+5);
    return 0;
}