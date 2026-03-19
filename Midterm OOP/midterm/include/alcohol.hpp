#ifndef ALHOCOL_HPP
#define ALHOCOL_HPP

#include <string>
#include "coupon.hpp"
class Alcohol {
public:
    Alcohol(std::string name, int price, int expiredYear, int expiredMonth, int expiredDay) {}
    void CheckAge(int ages);
    void ApplyCoupon(Coupon coupon);
};

#endif