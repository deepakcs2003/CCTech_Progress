#include <bits/stdc++.h>
using namespace std;
// // bad design;
// class Bird{
//     public:
//     virtual void fly(){
//         cout<<"bird is flying"<<endl;
//     }
// };
// class Sparrow:public Bird{
//     public:
//     void fly() override{
//         cout<<"Sparrow is flying"<<endl;
//     }
// };
// class Penguin:public Bird{
//     public:
//     void fly() override{
//         throw runtime_error("Penguin Can't Fly");
//     }
// };


class Bird{
    public:
    virtual void eat(){
        cout<<"bird is eating"<<endl;
    }
};
class Flyingbird:public Bird{
    public:
    virtual void fly(){
        cout<<"bird is flying"<<endl;
    }
};
class Sparrow:public Flyingbird{
    public:
    void fly() override{
        cout<<"Sparrow is flying"<<endl;
    }
};
class Penguin:public Bird{
    public:
    void swin() {
        cout<<"Penguin swimming"<<endl;
    }
};
int main() {

    // bad design;
    Sparrow sparrow;
    Penguin penguin;
    sparrow.fly();
    penguin.swin();
    sparrow.eat();
    penguin.eat();
    return 0;
}