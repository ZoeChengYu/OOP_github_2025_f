#include "InsuranceProduct.hpp"
#include <stdexcept>
#include <vector>
InsuranceProduct::InsuranceProduct(
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
int InsuranceProduct::EstimateRevenue(int months) {
    if (months<0) {
        throw std::invalid_argument("000");
    }
    return fee*(1+rate)*months;
}
double InsuranceProduct::GetRate() {
    return rate;
}
std::string InsuranceProduct::GetName() {
    return name;
}
int InsuranceProduct::GetMonthlyFee() {
    return fee;
}
ProductType InsuranceProduct::GetProductType() {
    return ProductType::Insurance;
}
int InsuranceProduct::GetRiskLevel() {
    return risk;
}
