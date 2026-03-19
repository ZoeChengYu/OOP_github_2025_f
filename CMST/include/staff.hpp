#ifndef STAFF_HPP
#define STAFF_HPP

#include <string>
#include "staff_level.hpp"
#include "person.hpp"
#include "staff_no.hpp"
#include "title.hpp"

class Staff :public Person{
    StaffNo staffNo;
    StaffLevel level;

public:
    Staff(std::string name, Title title, std::string phone, int ext, StaffNo staffNo, StaffLevel level);
    StaffNo GetStaffNo();
    StaffLevel GetStaffLevel();
    int GetBasicSalary();
    int GetTotalSalary();
    int GetBonus();
};

#endif