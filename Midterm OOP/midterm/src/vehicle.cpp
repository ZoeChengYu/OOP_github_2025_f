#include "vehicle.hpp"

#include <stdexcept>

#include "cost_ratio.hpp"

Vehicle::Vehicle(
    std::string name,
    int         price,
    int         warrentyYear,
    int         warrentyMonth
) :WarrentyProduct(name,price*VEHICLE_COST_RATIO,price,warrentyYear,warrentyMonth){
    if (price<0||warrentyYear<0||warrentyMonth<0) {
        throw std::invalid_argument("");
    }
}


void Vehicle::CheckAge(int ages){
}

void Vehicle::ApplyCoupon(Coupon coupon){
}