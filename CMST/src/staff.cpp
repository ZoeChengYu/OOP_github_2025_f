#include "staff.hpp"

#include <stdexcept>

#include "person.hpp"
#include "staff_level.hpp"
#include "staff_no.hpp"

Staff::Staff(std::string name, Title title, std::string phone, int ext, StaffNo staffNo, StaffLevel level):Person(name,title,phone,ext){
    this->staffNo = staffNo;
    this->level = level;
}

StaffNo Staff::GetStaffNo(){
    return staffNo;
}

StaffLevel Staff::GetStaffLevel(){
    return level;
}

int Staff::GetBasicSalary(){
    if (GetStaffNo() == StaffNo::M) {
        if (GetStaffLevel()==StaffLevel::L3) {
            return 120000*2.32*16;
        }else if (GetStaffLevel()==StaffLevel::L2) {
            return 120000*1.68*16;
        }else if (GetStaffLevel()==StaffLevel::L1) {
            return 120000*16;
        }else {
            return 0;
        }
    }else if (GetStaffNo() == StaffNo::S) {
        if (GetStaffLevel()==StaffLevel::L3) {
            return 73000*1.32*16;
        }else if (GetStaffLevel()==StaffLevel::L2) {
            return 73000*1.17*16;
        }else if (GetStaffLevel()==StaffLevel::L1) {
            return 73000*16;
        }else {
            return 0;
        }
    } else if (GetStaffNo()==StaffNo::E){
        if (GetStaffLevel()==StaffLevel::L3) {
            return 93000*1.82*16;
        }else if (GetStaffLevel()==StaffLevel::L2) {
            return 93000*1.43*16;
        }else if (GetStaffLevel()==StaffLevel::L1){
            return 93000*16;
        }else {
            return 0;
        }
    }else if (GetStaffNo()==StaffNo::N) {
        if (GetStaffLevel()==StaffLevel::L3) {
            return 55000*1.24*16;
        }else if (GetStaffLevel()==StaffLevel::L2) {
            return 55000*1.12*16;
        }else if (GetStaffLevel()==StaffLevel::L1) {
            return 55000*16;
        }else {
            return 0;
        }
    }else {
        return 0;
    }
}

int Staff::GetTotalSalary(){
    return GetBasicSalary()+GetBonus();
}

int Staff::GetBonus() {
    if (GetTitle()==Title::STAFF_SALES) {
        if (Getcount()<=10&&Getcount()>0) {
            return GettotalSales()*0.1;
        }else if (Getcount()<=20) {
            return GettotalSales()*0.15;
        }else if (Getcount()>20) {
            return GettotalSales()*0.2;
        }else {
            return 0;
        }
    }else if (GetStaffNo()==StaffNo::M) {
        if (GetStaffLevel()==StaffLevel::L1) {
            return 60000;
        }else if (GetStaffLevel()==StaffLevel::L2) {
            return 73000;
        }else if (GetStaffLevel()==StaffLevel::L3) {
            return 94000;
        }
    }else if (GetStaffNo()==StaffNo::E) {
        if (GetStaffLevel()==StaffLevel::L1) {
            return 56000;
        }else if (GetStaffLevel()==StaffLevel::L2) {
            return 64000;
        }else if (GetStaffLevel()==StaffLevel::L3) {
            return 83000;
        }
    }else {
        return 0;
    }
    return 0;
}