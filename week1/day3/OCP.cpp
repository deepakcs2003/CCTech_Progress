#include <bits/stdc++.h>
using namespace std;


// // bad way
// class PaymentProcess{
//     public:
//     void paymentProcess(string type,double amount){
//             if(type=="CreditCard"){
//                   cout << "Processing Credit Card payment of $" << amount << endl;
//             }else if (type=="Paypal"){
//                 cout << "Processing PayPal payment of $" << amount << endl;
//             }else{
//                  cout << "Invalid Payment Type!" << endl;
//             }
//     }
// };

class PaymentProcess{
    public:
    virtual void processPayment(double amount)=0;
};
class Paypal:public PaymentProcess{
    public:
    void processPayment(double amount) override{
        cout << "Processing Credit Card payment of $" << amount << endl;
    }
};
class CreditCard: public PaymentProcess{
    public:
    void processPayment(double amount){
          cout << "Processing PayPal payment of $" << amount << endl;
    }
};
int main() {
    // bad way
    // PaymentProcess process;
    // process.paymentProcess("CreditCard", 100.0);
    // process.paymentProcess("PayPal", 200.0);

    // good way
    CreditCard c;
    Paypal p;
    c.processPayment(1000.0);
    p.processPayment(300.0);
    return 0;
}