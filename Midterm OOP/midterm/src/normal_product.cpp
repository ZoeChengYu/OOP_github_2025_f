#include "normal_product.hpp"

#include <stdexcept>

NormalProduct::NormalProduct(std::string name, int cost, int price) :Product(name,cost,price){
     if (cost<0||price<0) {
         throw std::invalid_argument("");
     }
}
NormalProduct::NormalProduct(std::string name, int price)
    : Product(name,price*NORMAL_PRODUCT_COST_RATIO,price) {
    if (price < 0) { throw std::invalid_argument(""); }
}

int NormalProduct::GetCost() {
    return GetPrice()*NORMAL_PRODUCT_COST_RATIO;
}

void NormalProduct::ApplyCoupon(Coupon coupon){
    if (coupon==FESTIVE80) {
        SetPrice(GetPrice()*0.8);
    }else if (coupon==OOPALLPASS) {
        SetPrice(GetPrice()*1);
    }else if (coupon==OOPALLFAILED) {
        SetPrice(GetPrice()*0);
    }
}