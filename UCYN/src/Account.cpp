#include "Account.hpp"
Account::Account(AccountType type, int balance, std::string owner) {
    if (balance<0) {
        throw std::invalid_argument("Error bal<0");
    }
    this->type=type;
    this->balance=balance;
    this->owner=owner;
}
AccountType Account::GetType() {
    return type;
}
int Account::GetBalance() {
    return balance;
}
std::string Account::GetOwner() {
    return owner;
}
void Account::Deposit(int amount) {
    if (amount<0) {
        throw std::invalid_argument("error am<0");
    }
    balance+=amount;
}
int Account::Withdraw(int amount) {
    if (amount<0) {
        throw std::invalid_argument("am<0");
    }
    return amount;
}
void Account::Transfer(std::shared_ptr<Account> dest, int amount) {
    if (amount<0) {
        throw std::invalid_argument("am<0");
    }
}
void Account::SetBalance(int amount) {
    balance+=amount;
}
