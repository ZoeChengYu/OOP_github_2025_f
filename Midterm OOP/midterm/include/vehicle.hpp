#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include "coupon.hpp"
#include "warrenty_product.hpp"

class Vehicle :public WarrentyProduct{

public:
    Vehicle(std::string name, int price, int warrentyYear, int warrentyMonth)

    void CheckAge(int ages);
    void ApplyCoupon(Coupon coupon);
};

#endif