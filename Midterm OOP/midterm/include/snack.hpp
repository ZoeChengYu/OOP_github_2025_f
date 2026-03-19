#ifndef SNACK_HPP
#define SNACK_HPP

#include <string>
#include "coupon.hpp"

class Snack {
public:
    Snack(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay) {}

    void ApplyCoupon(Coupon coupon);
};

#endif
