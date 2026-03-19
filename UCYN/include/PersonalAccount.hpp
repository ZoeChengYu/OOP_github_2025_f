#ifndef PERSONAL_ACCOUNT_HPP
#define PERSONAL_ACCOUNT_HPP

#include "Account.hpp"

class PersonalAccount:public Account{
    std::shared_ptr<Account> dest;
public:
    PersonalAccount(int balance, std::string owner);
    int Withdraw(int amount) override;
    void Transfer(std::shared_ptr<Account> dest, int amount) override;
};

#endif