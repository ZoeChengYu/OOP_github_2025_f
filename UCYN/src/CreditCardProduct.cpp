#include "CreditCardProduct.hpp"
#include <stdexcept>
CreditCardProduct::CreditCardProduct(
    std::string name,
    double      rate,
    int         payment
) {
    if (rate<0||payment<0) {
        throw std::invalid_argument("ERROR");
    }
    this->name=name;
    this->rate=rate;
    this->payment=payment;
}
int CreditCardProduct::EstimateRevenue(int months) {
    if (months<0) {
        throw std::invalid_argument("000");
    }
    return payment*rate*months;
}
std::string CreditCardProduct::GetName() {
    return name;
}
double CreditCardProduct::GetRate() {
    return rate;
}
int CreditCardProduct::GetMonthlyFee() {
    return payment;
}
ProductType CreditCardProduct::GetProductType() {
    return ProductType::CreditCard;
}