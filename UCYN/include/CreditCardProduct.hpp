#ifndef CREDIT_CARD_PRODUCT_HPP
#define CREDIT_CARD_PRODUCT_HPP

#include "IBankProduct.hpp"
#include "IRevenueGeneratable.hpp"

class CreditCardProduct:public IBankProduct,public IRevenueGeneratable{
    std::string name;
    double rate;
    int payment;
public:
    CreditCardProduct(std::string name, double rate, int payment);
    ProductType GetProductType();
    int GetMonthlyFee();
    std::string GetName();
    int EstimateRevenue(int months);
    double GetRate();
};

#endif