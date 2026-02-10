#include <bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
    Vehicle(){
        cout<<"this is vehicle"<<endl;
    }
};
class Speaker{
    public:
    Speaker(){
        cout<<"vehicles use speaker"<<endl;
    }
};
class FourWheeler:public Vehicle{

    public:
    FourWheeler(){
        cout<<"this is four wheeler"<<endl;
    }
};
class Car:public Speaker,public FourWheeler{
    public:
    Car(){
        cout<<"this is car"<<endl;
    }
};

class Base{
    public:
    int value=100;
};
class Child1:public virtual Base{

};
class Child2:public virtual Base{

};
class GrandChild:public Child1,public Child2{
};
int main() {

    // vehicle class 
    Car obj;
    GrandChild gc;
    cout<<"value: "<<gc.value<<endl;
    return 0;
}