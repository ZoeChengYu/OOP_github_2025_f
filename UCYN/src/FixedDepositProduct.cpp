#include "FixedDepositProduct.hpp"
#include <stdexcept>
FixedDepositProduct::FixedDepositProduct(
    std::string name,
    double      rate,
    int         fee
) {
    if (rate<0||fee<0) {
        throw std::invalid_argument("Error");
    }
    this->name=name;
    this->rate=rate;
    this->fee=fee;
}
int FixedDepositProduct::GetMonthlyFee() {
    return fee*(1+rate)/12;
}
std::string FixedDepositProduct::GetName() {
    return name;
}
ProductType FixedDepositProduct::GetProductType() {
    return ProductType::FixedDeposit;
}
