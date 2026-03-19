#ifndef FIXED_DEPOSIT_PRODUCT_HPP
#define FIXED_DEPOSIT_PRODUCT_HPP

#include "ProductType.hpp"
#include <string>
#include "IBankProduct.hpp"

class FixedDepositProduct:public IBankProduct{
    std::string name;
    double rate;
    int fee;
public:
    FixedDepositProduct(std::string name, double rate, int fee);
    ProductType GetProductType();
    int GetMonthlyFee();
    std::string GetName();
};

#endif