#include <bits/stdc++.h>
using namespace std;


// bad way
// class IManu{
//     public:
//     virtual vector<string> getVegItems()=0;
//     virtual vector<string> getNonVegItems()=0;
//     virtual vector<string> getDrinkItmes()=0;
//     virtual vector<string> getSweets()=0;
// };
// class VegCustomer:public IManu{
//     public:
//     vector<string> getVegItems() override{
//         cout<<"this is veg manu"<<endl;
//     }
//     vector<string> getNonVegItems() override{
//         cout<<"this is non veg manu"<<endl;
//     }
//      vector<string> getDrinkItmes() override{
//         cout<<"this is drink manu"<<endl;
//     }
//     vector<string> getSweets() override{
//         cout<<"this is sweet manu"<<endl;
//     }
// };



class IVegetarianMenu {
public:
    virtual vector<string> getVegetarianItems() = 0;
};

class INonVegetarianMenu {
public:
    virtual vector<string> getNonVegetarianItems() = 0;
};
class IDrinkMenu {
public:
    virtual vector<string> getDrinkItems() = 0;
};
class ISweetManu{
    public:
    virtual vector<string> getSweetItems()=0;
};

class VegetarianMenu : public IVegetarianMenu {
public:
    vector<string> getVegetarianItems() override {
        return {"Vegetable Curry", "Paneer Tikka", "Salad"};
    }
};

class NonVegetarianMenu : public INonVegetarianMenu {
public:
    vector<string> getNonVegetarianItems() override {
        return {"Chicken Curry", "Fish Fry", "Mutton Biryani"};
    }
};

int main() {

    VegetarianMenu vm;
    vector<string> manu1=vm.getVegetarianItems();
    for(const string& item:manu1){
        cout<<item<<endl;
    }
    return 0;
}