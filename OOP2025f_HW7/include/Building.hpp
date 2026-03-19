#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "Company.hpp"
#include <vector>

class Building {
    int totalFloors;
    std::vector<std::shared_ptr<Company>> companies;
public:
    Building(int totalFloors);
    ~Building();

    int getTotalFloors();
    std::vector<std::shared_ptr<Company>> getCompanies();

    int CountWorkingCompanies();
};

#endif
