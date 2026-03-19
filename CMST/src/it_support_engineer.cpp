#include "it_support_engineer.hpp"

#include <stdexcept>

ITSupportEngineer::ITSupportEngineer(std::string name, std::string phone, int ext):Vendor(name,Title::IT_SUPPORT_ENGINEER,phone,ext){
    if(ext<0) {
        throw std::invalid_argument("");
    }
}