#include <iostream>
#include <string>
using namespace std;

int* getptr(){
    int local=10;
    return &local;
}
int main(){
    int num=10;
    int* ptr=&num;
    cout<<num<<endl;
    cout<<&num<<endl;
    cout<<ptr<<endl;
    double value=3.14;
    double* dblptr=&value;
    cout<<value<<" this is address: " << *dblptr<<endl;
    *dblptr=20;
    cout<<"change value:" <<value<<endl;
    int arr[3]={1,2,3};
    int* arrptr= arr;
    cout<<*arrptr<<endl;
    arrptr+=4;
    cout<<*arrptr<<endl;
    char name[]="deepak";
    char* charptr=name;
    for(int i=0;i<sizeof(name);i++){
        cout<<*(charptr+i)<<endl;
    }
    cout<<endl;
    int x=100;
    int* newptr=&x;
    int** dbtptr=&newptr;
    cout<<newptr<<endl;
    cout<<dbtptr<<endl;
    cout<<**dbtptr<<endl;
    int* nptr=nullptr;
    if(nptr==nullptr){
        cout<<"safe null pointer" <<endl;
    };
    int* dangptr=getptr();
    cout<<dangptr<<endl;
    return 0;
}

