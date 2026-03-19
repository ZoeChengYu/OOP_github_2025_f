#include "Company.hpp"
#include "PowerSwitch/MainPowerSwitch.hpp"
#include <stdexcept>
Company::Company(std::string name, int floorNumber) {
    this->name = name;
    this->floorNumber = floorNumber;
    this->isWorking = false;
    std::string mainSwitchName = "company"+std::to_string(floorNumber)+"_mainPowerSwitch" ;
    this->powerSwitches.clear();
    this->powerSwitches.push_back(std::make_shared<MainPowerSwitch>(mainSwitchName));
}
Company::~Company() {

}
std::string Company::getName() {
    return this->name;
}
int Company::getFloorNumber() {
    return this->floorNumber;
}
bool Company::isWork() {
    return this->isWorking;
}
void Company::addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
    auto baseSwitch = getMainSwitch();
    auto mainSwitch = std::dynamic_pointer_cast<MainPowerSwitch>(baseSwitch);
    if (mainSwitch) {
        mainSwitch->addPowerSwitch(powerSwitch);
    }
}
void Company::work() {
    isWorking = true;
    auto main = getMainSwitch();
    if (main) {
        main->turnOn();
    }
}
void Company::offWork() {
    isWorking = false;
    auto main = getMainSwitch();
    if (main) {
        main->turnOff();
    }
}
void Company::removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
    auto baseSwitch = getMainSwitch();
    if (powerSwitch==baseSwitch) {
        throw std::invalid_argument("The power switch already exists");
    }
    auto mainSwitch = std::dynamic_pointer_cast<MainPowerSwitch>(baseSwitch);
    if (mainSwitch) {
        mainSwitch->removePowerSwitch(powerSwitch);
    }
}
int Company::countPower() {
    if (auto main =getMainSwitch()) {
        return main->countPower();
    }
    return 0;
}
std::shared_ptr<PowerSwitch> Company::getMainSwitch() {
    if (!powerSwitches.empty()) {
        return powerSwitches.at(0);
    }
    return nullptr;
}
std::vector<std::shared_ptr<Device>> Company::findDeviceByName(
    std::string name
) {
   auto baseSwitch = getMainSwitch();
    auto mainSwitch = std::dynamic_pointer_cast<MainPowerSwitch>(baseSwitch);
    if (mainSwitch) {
        return mainSwitch->findDeviceByName(name);
    }
    return {};
}
std::vector<std::shared_ptr<Device>> Company::findDeviceByType(
    DeviceType type
) {
    auto baseSwitch = getMainSwitch();
    auto mainSwitch = std::dynamic_pointer_cast<MainPowerSwitch>(baseSwitch);
    if (mainSwitch) {
        return mainSwitch->findDeviceByDeviceType(type);
    }
}
std::vector<std::shared_ptr<PowerSwitch>> Company::findPowerSwitchByName(
    std::string name
) {
    auto baseSwitch = getMainSwitch();
    auto mainSwitch = std::dynamic_pointer_cast<MainPowerSwitch>(baseSwitch);
    if (mainSwitch) {
        return mainSwitch->findPowerSwitchByName(name);
    }
}
