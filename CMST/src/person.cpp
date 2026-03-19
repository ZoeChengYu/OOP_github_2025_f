
#include "person.hpp"

#include <stdexcept>

#include "title.hpp"

Person::Person(std::string name, Title title, std::string phone, int ext) {
    this->name=name;
    this->title=title;
    this->phone=phone;
    if (ext<0) {
        throw std::invalid_argument("ext<0");
    }
    this->ext=ext;
}

std::string Person::GetName(){
    return name;
}

Title Person::GetTitle(){
    return title;
}

std::string Person::GetPhone(){
    return phone;
}

int Person::GetExt(){
    return ext;
}

void Person::SetName(std::string name){
    this->name=name;
}

void Person::SetTitle(Title title){
    this->title=title;
}

void Person::SetPhoneExt(std::string phone, int ext){
    this->phone=phone;
    this->ext=ext;
}

bool Person::HaveEMPermission(){
    if (title==Title::PROJECT_MANAGER || title==Title::INFRASTRUCTURE_ENGINEER ||
    title==Title::CYLINDER_ENGINEER) {
        return true;
    } else {
        return false;
    }
}

int Person::Getcount() {
    return count;
}

void Person::Setcount(int count) {
    this->count = count;
}

int Person::GettotalSales() {
    return totalSales;
}

void Person::SettotalSales(int totalSales) {
    this->totalSales = totalSales;
}