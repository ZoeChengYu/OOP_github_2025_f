#ifndef MUTUALFUND_PRODUCT_HPP
#define MUTUALFUND_PRODUCT_HPP

#include "ProductType.hpp"
#include "IBankProduct.hpp"
#include "IRiskEvaluable.hpp"
#include "IRevenueGeneratable.hpp"

class MutualFundProduct : public IBankProduct, public IRiskEvaluable, public IRevenueGeneratable{
private:
    ProductType type;
    std::string name;
    double rate;
    int fee;
    int risk;
public:
    MutualFundProduct(std::string name, double rate, int fee, int risk);
    ProductType GetProductType() override;
    int GetMonthlyFee() override;
    std::string GetName() override;
    int GetRiskLevel() override;
    int EstimateRevenue(int months) override;
    double GetRate();
};

#endif
