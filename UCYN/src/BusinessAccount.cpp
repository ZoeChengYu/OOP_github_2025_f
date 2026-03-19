#include "BusinessAccount.hpp"
BusinessAccount::BusinessAccount(int balance, std::string owner):Account(AccountType::BusinessAccount,balance,owner) {
    if (balance<0) {
        throw std::invalid_argument("error bal<0");
    }
}
int BusinessAccount::Withdraw(int amount) {
    if (amount<0) {
        throw std::invalid_argument("am<0");
    }
    if(GetBalance()<amount){
        throw std::invalid_argument("00");
    }
    SetBalance(-1*amount);
    return amount;
}
void BusinessAccount::Transfer(std::shared_ptr<Account> dest, int amount) {
    if (amount<0) {
        throw std::invalid_argument("am<0");
    }
    if(GetBalance()<amount){
        throw std::invalid_argument("00");
    }
    dest->SetBalance(amount);
    SetBalance(-1*amount);
}