#ifndef WARRENTY_PRODUCT_HPP
#define WARRENTY_PRODUCT_HPP

#include <string>
#include "product.hpp"

class WarrentyProduct:public Product{
private:
    int warrentyYear;
    int warrentyMonth;
public:
    WarrentyProduct(std::string name, int cost, int price, int warrentyYear, int warrentyMonth);
    //~WarrentyProduct();
    bool IsExpired(int year, int month, int day);
};

#endif