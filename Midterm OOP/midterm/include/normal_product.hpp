#ifndef NORMAL_PRODUCT_HPP
#define NORMAL_PRODUCT_HPP

#include "cost_ratio.hpp"
#include "product.hpp"
#include "coupon.hpp"

class NormalProduct:public Product{
public:
    NormalProduct(std::string name,int cost, int price);
    NormalProduct(std::string name,int price);
    int GetCost() override;
    void ApplyCoupon(Coupon coupon);
};

#endif