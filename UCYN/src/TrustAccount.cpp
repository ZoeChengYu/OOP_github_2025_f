#include "TrustAccount.hpp"
TrustAccount::TrustAccount(
    int         balance,
    std::string owner,
    std::string beneficiary
):Account(AccountType::TrustAccount,balance,owner) {
    this->beneficiary=beneficiary;
}
std::string TrustAccount::GetBeneficiary() {
    return beneficiary;
}
void TrustAccount::Deposit(int amount) {
    throw std::invalid_argument("XXX");
}
int TrustAccount::Withdraw(int amount) {
    throw std::invalid_argument("xxx");
}
void TrustAccount::Transfer(std::shared_ptr<Account> dest, int amount) {
    if (amount<0) {
        throw std::invalid_argument("am<0");
    }
    if(GetBalance()<amount){
        throw std::invalid_argument("00");
    }
    if (dest->GetOwner()!=beneficiary) {
        throw std::invalid_argument("not empty");
    }
    dest->SetBalance(amount);
    SetBalance(-1*amount);
}
