#include "infrastructure_engineer.hpp"

#include <stdexcept>

#include "vendor.hpp"

InfrastructureEngineer::InfrastructureEngineer(std::string name, std::string phone, int ext):Vendor(name,Title::INFRASTRUCTURE_ENGINEER,phone,ext){
    if (ext<0) {
        throw std::invalid_argument("");
    }
}