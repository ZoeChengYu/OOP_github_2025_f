#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

class Product {
    std::string name;
    int cost;
    int price;
    int year,month,day;
public:
    Product(std::string name, int cost, int price);
    ~Product();
    std::string GetName();
    virtual int GetCost();
    int GetPrice();
    int GetYear();
    int GetMonth();
    int GetDay();
    void SetName(std::string name);
    void SetCost(int cost);
    void SetPrice(int price);
    void SetYear(int year);
    void SetMonth(int month);
    void SetDay(int day);
};

#endif