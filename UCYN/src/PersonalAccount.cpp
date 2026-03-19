#include "PersonalAccount.hpp"
PersonalAccount::PersonalAccount(int balance, std::string owner):Account(AccountType::PersonalAccount,balance,owner) {
    if (balance<0) {
        throw std::invalid_argument("error bal<0");
    }
}
int PersonalAccount::Withdraw(int amount) {
    if (amount<0) {
        throw std::invalid_argument("am<0");
    }else if(GetBalance()<amount){
        throw std::invalid_argument("00");
    }
    SetBalance(-1*amount);
    return amount;
}
void PersonalAccount::Transfer(std::shared_ptr<Account> dest, int amount) {
    if (amount<0) {
        throw std::invalid_argument("am<0");
    }
    if(GetBalance()<amount){
        throw std::invalid_argument("00");
    }
    if (dest->GetType()!=AccountType::PersonalAccount) {
        throw std::invalid_argument("Type error");
    }
    dest->SetBalance(amount);
    SetBalance(-1*amount);
}
