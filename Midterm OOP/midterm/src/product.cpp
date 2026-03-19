#include "product.hpp"

#include <stdexcept>
#include <string>

 Product::Product(std::string name, int cost, int price) {
     if (cost<0||price<0) {
         throw std::invalid_argument("");
     }
    this->name=name;
     this->price=price;
     this->cost=cost;
}

 Product::~Product() {

}


std::string Product::GetName() {
    return name;
}

int Product::GetCost() {
    return cost;
}

int Product::GetPrice(){
    return price;
}

int Product::GetDay() {
    return day;
}

int Product::GetMonth() {
    return month;
}

int Product::GetYear() {
    return year;
}


void Product::SetName(std::string name){
    this->name=name;
}

void Product::SetCost(int cost){
     if (cost<0) {
         throw std::invalid_argument("");
     }
    this->cost=cost;
}

void Product::SetPrice(int price){
     if (price<0) {
         throw std::invalid_argument("");
     }
    this->price=price;
}

void Product::SetDay(int day) {
    this->day=day;
}

void Product::SetMonth(int month) {
    this->month=month;
}

void Product::SetYear(int year) {
    this->year=year;
}
