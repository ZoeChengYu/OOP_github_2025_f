#include "extern_sales.hpp"

#include <stdexcept>

#include "vendor.hpp"

ExternSales::ExternSales(std::string name, std::string phone, int ext):Vendor(name,Title::EXTERN_SALES,phone,ext){
    if (ext<0) {
        throw std::invalid_argument("");
    }
}

void ExternSales::ApplyBonus(int totalSales, int count){
    SettotalSales(totalSales);
    Setcount(count);
}