#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
    int salary;

    protected:
    string adresss;

    public:
        string name;
        int age;
    void display() {
        cout<<"name : "<<name<<" age: "<<age<<endl;
    };
    void setSalary(int a){
        if(a>0){
            salary=a;
        }else{
            cout<<"salary is not negative" <<endl;
        }
    }
    int getSalary(){
        cout<<"this is salary of: "<<name<<" salary: "<<salary<<endl;
        return salary;
    }
    
};

class Ractangle{
    public:
    int len,wid;
    Ractangle(){
        len=0;
        wid=0;
        cout<<"default contrauction is call"<<endl;
    }
    Ractangle(int l,int r){
        len=l;
        wid=r;
        cout<<"Parameterized constructor called" <<endl;
    }
    ~Ractangle(){
        cout<<"Destructor is called"<<endl;
    }
    int ares(){
        return len*wid;
    }
};

class Box{
    private:
    int size;
    public:
     Box& setSize(int size){
        this->size=size;
        return *this;
     }
     int getSize(){
        cout<<"size: "<<size<<endl;
        return size;

     }
};
class Item {
public:
    static int count;  // Static data member
    
    Item() {
        count++;
    }
};
int Item::count=0;

class Distance{
    int meters;
    public:
    Distance(int m){
        meters=m;
    }
    void getMeters(){
        cout<<"this is value: "<<meters<<endl;
    }
    friend void addMeters(Distance &d,int extra);
};

void addMeters(Distance &d,int extra){
    d.meters+=extra;
}


class A{
    int secret=42;
    public:
    friend class B;
     void showSecret(){
        cout<<"secret: "<<secret<<endl;
    }
};
class B{
    public:
    void showSecret(A& obj){
        obj.secret=32;
        cout<<"secret: "<<obj.secret<<endl;
    }
};
int main(){

    // person class
    Person p1;
    p1.name="deepak";
    p1.age=23;
    p1.setSalary(50000);
    p1.display();
    p1.getSalary();
    Person p2;
    p2.name="ashish";
    p2.age=23;
    p2.setSalary(100000);
    p2.display();
    p2.getSalary();

    // ractangle class;
    Ractangle r1;
    cout<<"area is: "<<r1.ares()<<endl;

    Ractangle r2(10,2);
    cout<<"area is: " << r2.ares()<<endl;

    // box class
    Box b1;
    b1.setSize(40).getSize();
    b1.getSize();

    // Items class;
    Item i1, i2, i3;
    cout << "Total items: " << Item::count <<endl;

    // friend funtion;
    Distance d(20);
    d.getMeters();
    addMeters(d,20);
    d.getMeters();

    // friend class
    A a;
    B b;
    b.showSecret(a);
    a.showSecret();
    return 0;
}