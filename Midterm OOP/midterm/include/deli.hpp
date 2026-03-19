#ifndef DELI_HPP
#define DELI_HPP

#include <string>
#include "coupon.hpp"

class Deli {
public:
    Deli(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay) {}
    void ApplyCoupon(Coupon coupon);
    void ApplyExpireCoupon();
};

#endif