#include "Bank.hpp"
#include "InsuranceProduct.hpp"
#include "CreditCardProduct.hpp"
#include "FixedDepositProduct.hpp"
#include "MutualFundProduct.hpp"

Bank::Bank(long long initialCapital, double interestRate) {
    if (initialCapital<0||interestRate<0) {
        throw std::invalid_argument("mmmm");
    }
    this->initialCapital=initialCapital;
    this->interestRate=interestRate;
}
void Bank::SetRate(double rate) {
    if (rate<0) {
        throw std::invalid_argument("");
    }
    this->interestRate=rate;
}
double Bank::GetRate() {
    return interestRate;
}
void Bank::AddCapital(long long capital) {
    if (capital<0) {
        throw std::invalid_argument("");
    }
    this->initialCapital=capital;
}
long long Bank::GetCapital() {
    return initialCapital;
}
void Bank::AddAccount(std::shared_ptr<Account> acc) {

}
