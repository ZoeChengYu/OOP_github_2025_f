#ifndef BUSINESS_ACCOUNT_HPP
#define BUSINESS_ACCOUNT_HPP

#include "Account.hpp"

class BusinessAccount:public Account{
public:
    BusinessAccount(int balance, std::string owner);
    int  Withdraw(int amount) override;
    void Transfer(std::shared_ptr<Account> dest, int amount) override;
};

#endif