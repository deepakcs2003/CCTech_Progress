#include <bits/stdc++.h>
using namespace std;


class Rectangle {
    int length, breadth;

public:
    Rectangle(int l, int b) : length(l), breadth(b) {
        cout << "Constructor called\n";
    }

    ~Rectangle() {
        cout << "Destructor called\n";
    }

    int area() {
        return length * breadth;
    }
};

int main() {

    // while(true){
    //     int*  ptr=new int(10);
    // }

    // int *ptr=new int(10);
    // delete ptr;
    // cout<<*ptr;
    // unique_ptr<Rectangle> p1(new Rectangle(10,20));
    // unique_ptr<Rectangle> p2=move(p1);
    // cout<<p2->area()<<endl; 

    shared_ptr<Rectangle> p1(new Rectangle(20,12));
    cout << "Use count: " << p1.use_count() << endl;
    shared_ptr<Rectangle> p2=p1;
    cout << "Use count after copy: " << p1.use_count() << endl;
    cout << "Area: " << p2->area() << endl;
    weak_ptr<Rectangle> p3=p1;
     cout << "Shared count: " << p1.use_count() << endl;


    return 0;
}