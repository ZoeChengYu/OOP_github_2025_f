#ifndef INSURANCE_PRODUCT_HPP
#define INSURANCE_PRODUCT_HPP

#include "IRevenueGeneratable.hpp"
#include "IRiskEvaluable.hpp"
#include "IBankProduct.hpp"

class InsuranceProduct:public IBankProduct,public IRevenueGeneratable,public IRiskEvaluable{
    std::string name;
    double rate;
    int fee;
    int risk;
public:
    InsuranceProduct(std::string name, double rate, int fee, int risk);
    double GetRate();
    ProductType GetProductType();
    int GetMonthlyFee() ;
    std::string GetName();
    int GetRiskLevel() ;
    int EstimateRevenue(int months);
};

#endif