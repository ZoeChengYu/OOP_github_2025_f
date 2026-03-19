#include "warrenty_product.hpp"

#include <stdexcept>

WarrentyProduct::WarrentyProduct(
    std::string name,
    int         cost,
    int         price,
    int         warrentyYear,
    int         warrentyMonth
) :Product(name,cost,price){
     if (cost<0||price<0||warrentyMonth<0||warrentyYear<0) {
         throw std::invalid_argument("");
     }
    this->warrentyMonth=warrentyMonth;
     this->warrentyYear=warrentyYear;
}

bool WarrentyProduct::IsExpired(int year, int month, int day){
    if (year>warrentyYear||(year==warrentyYear&&month>warrentyMonth)) {
        return true;
    }
    return false;

}