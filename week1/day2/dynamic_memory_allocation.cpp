#include <iostream>
using namespace std;
int main(){
    int* numptr=new int(30);
    cout<<numptr<<endl;
    cout<<*numptr<<endl;
    delete numptr;
    numptr=nullptr;
    cout<<numptr<<endl;
    int size=4;
    int* dynarr=new int[size];
    for(int i=0;i<size;i++){
        dynarr[i]=i+10;
        cout<<dynarr[i]<<endl;
    }
    cout<<endl;
    delete[] dynarr;

}