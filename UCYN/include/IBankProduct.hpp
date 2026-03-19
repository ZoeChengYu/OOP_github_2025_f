#ifndef IBANKPRODUCT_HPP
#define IBANKPRODUCT_HPP

#include "ProductType.hpp"
#include <string>

class IBankProduct{
private:
    ProductType type;
    int Fee;
    std::string Name;
public:
    virtual ProductType GetProductType() = 0;
    virtual int GetMonthlyFee() = 0;
    virtual std::string GetName() = 0;
};

#endif
