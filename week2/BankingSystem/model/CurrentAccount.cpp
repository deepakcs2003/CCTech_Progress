#include "CurrentAccount.h"
#include <stdexcept>

 CurrentAccount::CurrentAccount(string accNo,string name,double bal,double overdraft):
 Account(accNo,name,bal),overdraftLimit(overdraft)
 {
 };


 
void CurrentAccount::withdraw(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Invalid withdrawal");

    if (balance + overdraftLimit < amount)
        throw std::runtime_error("Overdraft exceeded");

    balance -= amount;
    transactions.emplace_back("Withdraw", amount);
}

double CurrentAccount::calculateInterest() const {
    return 0;
}

std::unique_ptr<Account> CurrentAccount::clone() const {
    return std::make_unique<CurrentAccount>(*this);
}