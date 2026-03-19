#include "product_3c.hpp"

#include <stdexcept>

#include "cost_ratio.hpp"
#include "coupon.hpp"
 Product3C::Product3C(
    std::string name,
    int         price,
    int         warrentyYear,
    int         warrentyMonth
) :WarrentyProduct(name,price*PRODUCT_3C_COST_RATIO,price,warrentyYear,warrentyMonth){
    if (price<0) {
        throw std::invalid_argument("");
    }
}

void Product3C::ApplyCoupon(Coupon coupon) {
     if (coupon==BACK2SCHOOL) {
         SetPrice(GetPrice()*0.8);
     }else if (coupon==TECHLIFE80||coupon==FESTIVE80) {
         SetPrice(GetPrice()*0.8);
     }else if (coupon==HEALTHY90) {
         SetPrice(GetPrice()*0.9);
     }else if (coupon==OOPALLPASS) {
         SetPrice(GetPrice()*1);
     }else if (coupon==OOPALLFAILED) {
         SetPrice(GetPrice()*0);
     }
}