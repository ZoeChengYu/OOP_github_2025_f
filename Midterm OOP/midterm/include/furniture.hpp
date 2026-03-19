#ifndef FURNITURE_HPP
#define FURNITURE_HPP

#include <string>
#include "coupon.hpp"

class Furniture {
public:
    Furniture(std::string name, int price, int warrentyYear, int warrentyMonth) {}
    void ApplyCoupon(Coupon coupon);
};

#endif