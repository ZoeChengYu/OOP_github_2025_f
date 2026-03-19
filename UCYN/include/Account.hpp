#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <memory>
#include <string>
#include <stdexcept>
#include "AccountType.hpp"

class Account{
    AccountType type;
    int balance;
    std::string owner;
public:
    Account(AccountType type, int balance, std::string owner);
    AccountType GetType();
    int GetBalance();
    std::string GetOwner();
    void SetBalance(int amount);
    virtual void Deposit(int amount);
    virtual int Withdraw(int amount) = 0;
    virtual void Transfer(std::shared_ptr<Account> dest, int amount) = 0;
};

#endif
