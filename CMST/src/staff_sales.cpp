#include "staff_sales.hpp"

#include <stdexcept>

#include "title.hpp"

StaffSales::StaffSales(std::string name, std::string phone, int ext, StaffLevel level):Staff(name,Title::STAFF_SALES,phone,ext,StaffNo::S,level){
    if(ext==0) {
        throw std::invalid_argument("");
    }
}

void StaffSales::ApplyBonus(int totalSales, int count){
    SettotalSales(totalSales);
    Setcount(count);
}