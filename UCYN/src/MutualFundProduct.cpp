#include "MutualFundProduct.hpp"
#include <stdexcept>
MutualFundProduct::MutualFundProduct(
    std::string name,
    double      rate,
    int         fee,
    int         risk
) {
    if (rate<0||fee<0||risk<0) {
        throw std::invalid_argument("<0!!!");
    }
    this->name=name;
    this->rate=rate;
    this->fee=fee;
    this->risk=risk;
}
int MutualFundProduct::EstimateRevenue(int months) {
    if (months<0) {
        throw std::invalid_argument("000");
    }
    return fee*(1+rate)*months;
}
ProductType MutualFundProduct::GetProductType() {
    return ProductType::MutualFund;
}
double MutualFundProduct::GetRate() {
    return rate;
}
std::string MutualFundProduct::GetName() {
    return name;
}
int MutualFundProduct::GetMonthlyFee() {
    return fee;
}
int MutualFundProduct::GetRiskLevel() {
    return risk;
}
