#include <iostream>
#include <string>
using namespace std;
 

class BreadBaker{
    public:
    void bakeBread(){
        cout<<"only responsibilty to bake bread"<<endl;
    };
};
class InventoryManager{
    public:
    void manageInventory(){
        cout<<"only responsibilty to manage bakery"<<endl;
    }
};
class CustomerService{
    public:
    void customerServe(){
        cout<<"only serve customer"<<endl;
    }
};
int main(){
    BreadBaker b;
    InventoryManager i;
    CustomerService c;
    b.bakeBread();
    i.manageInventory();
    c.customerServe();
}