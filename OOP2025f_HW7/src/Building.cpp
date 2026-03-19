#include "Building.hpp"
Building::Building(int totalFloors) {
    this->totalFloors = totalFloors;
    for (int i = 1; i <= totalFloors; i++) {
        std::string CompanyName = "company"+std::to_string(i);
        auto newCompany=std::make_shared<Company>(CompanyName,i);
        this->companies.push_back(newCompany);
    }
}
Building::~Building() {

}
int Building::getTotalFloors() {
    return this->totalFloors;
}
std::vector<std::shared_ptr<Company>> Building::getCompanies() {
    return this->companies;
}
int Building::CountWorkingCompanies() {
    int counts = 0;
    for (const auto& company : this->companies) {
        if (company->isWork()) {
            counts++;
        }
    }
    return counts;
}
