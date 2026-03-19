#include "food_product.hpp"

#include <stdexcept>

FoodProduct::FoodProduct(
    std::string name,
    int         cost,
    int         price,
    int         expiredYear,
    int         expiredMonth,
    int         expiredDay
) :Product(name,cost,price){
     if (cost<0||price<0||expiredMonth<0||expiredYear<0||expiredDay<0) {
         throw std::invalid_argument("");
     }
    this->expiredDay=expiredDay;
     this->expiredMonth=expiredMonth;
     this->expiredYear=expiredYear;
}


bool FoodProduct::CheckExpired(int year, int month, int day) {
     if (year>expiredYear||(year==expiredYear&&month>expiredMonth)||
         (year==expiredYear&&month==expiredMonth&&day>expiredDay)) {
         SetPrice(0);
         return true;
     }
     return false;
}