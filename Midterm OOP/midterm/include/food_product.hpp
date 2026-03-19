#ifndef FOOD_PRODUCT_HPP
#define FOOD_PRODUCT_HPP

#include <string>

#include "product.hpp"

class FoodProduct :public Product{
    int expiredYear,expiredMonth,expiredDay;
public:
    FoodProduct(std::string name, int cost, int price, int expiredYear, int expiredMonth, int expiredDay);
    bool CheckExpired(int year, int month, int day);
};

#endif