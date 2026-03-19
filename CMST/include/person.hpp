#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include "title.hpp"

class Person {
    std::string name;
    Title title;
    std::string phone;
    int ext;
    int count;
    int totalSales;
public:
    Person(std::string name, Title title, std::string phone, int ext);

    std::string GetName();
    Title GetTitle();
    std::string GetPhone();
    int GetExt();
    void SetName(std::string name);
    void SetTitle(Title title);
    void SetPhoneExt(std::string phone, int ext);
    bool HaveEMPermission();
    int Getcount();
    void Setcount(int count);
    int GettotalSales();
    void SettotalSales(int totalSales);

};

#endif