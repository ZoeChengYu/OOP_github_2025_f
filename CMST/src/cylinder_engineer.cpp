#include "cylinder_engineer.hpp"

#include <stdexcept>

CylinderEngineer::CylinderEngineer(std::string name, std::string phone, int ext, StaffLevel level):Staff(name,Title::CYLINDER_ENGINEER,phone,ext,StaffNo::E,level) {
    if (ext<0) {
        throw std::invalid_argument("");
    }
}