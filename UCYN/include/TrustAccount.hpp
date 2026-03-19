#ifndef TRUST_ACCOUNT_HPP
#define TRUST_ACCOUNT_HPP

#include "Account.hpp"

class TrustAccount:public Account{
    std::string beneficiary;
public:
    TrustAccount(int balance, std::string owner, std::string beneficiary);
    int  Withdraw(int amount) override;
    void Deposit(int amount) override;
    void Transfer(std::shared_ptr<Account> dest, int amount) override;
    std::string GetBeneficiary();
};

#endif