#ifndef BANK_HPP
#define BANK_HPP

#include "Account.hpp"
#include "IBankProduct.hpp"
#include <vector>

class Bank:public IBankProduct{
    long long initialCapital;
    double interestRate;
public:
    Bank(long long initialCapital, double interestRate);
    void SetRate(double rate);
    double GetRate();
    void AddCapital(long long capital);
    long long GetCapital();
    void AddAccount(std::shared_ptr<Account> acc);
    std::shared_ptr<Account> FindAccountByName(std::string name);
    std::vector<std::shared_ptr<Account>> FindAccountByType(AccountType type);
    void TransferByName(std::string src, std::string dest, int amount);
    void AddProduct(std::shared_ptr<IBankProduct> product);
    std::shared_ptr<IBankProduct> FindProductByName(const std::string& name);
    std::vector<std::shared_ptr<IBankProduct>> FindProductsByType(ProductType type);
    int EstimateTotalRevenue(int months);
    int EstimateRiskCount();
    std::shared_ptr<IBankProduct> MakeCreditCardProduct(std::string name, int payment);
    std::shared_ptr<IBankProduct> MakeFixedDepositProduct(std::string name, int fee);
    std::shared_ptr<IBankProduct> MakeInsuranceProduct(std::string name, int fee, int risk);
    std::shared_ptr<IBankProduct> MakeMutualFundProduct(std::string name, int fee, int risk);
};

#endif
