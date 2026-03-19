#include "PowerSwitch/MainPowerSwitch.hpp"
#include "PowerSwitch/NormalPowerSwitch.hpp"
#include <algorithm> 

MainPowerSwitch::MainPowerSwitch(std::string name) : PowerSwitch(name) {
}

MainPowerSwitch::MainPowerSwitch(std::string name, std::vector<std::shared_ptr<PowerSwitch>> powerSwitches) 
    : PowerSwitch(name) {
    for (auto& ps : powerSwitches) {
        this->addPowerSwitch(ps);
    }
}

void MainPowerSwitch::addPowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
    this->powerSwitches.push_back(powerSwitch);
}

void MainPowerSwitch::removePowerSwitch(std::shared_ptr<PowerSwitch> powerSwitch) {
    auto it = std::remove(this->powerSwitches.begin(), this->powerSwitches.end(), powerSwitch);
    this->powerSwitches.erase(it, this->powerSwitches.end());
}

PowerSwitchState MainPowerSwitch::getState() {
    if (this->powerSwitches.empty()) {
        return PowerSwitchState::NotDefined;
    }

    int onCount = 0;
    int offCount = 0;

    for (const auto& ps : powerSwitches) {
        PowerSwitchState s = ps->getState();
        if (s == PowerSwitchState::On) onCount++;
        else if (s == PowerSwitchState::Off) offCount++;
    }

    if (onCount == this->powerSwitches.size()) return PowerSwitchState::On;
    if (offCount == this->powerSwitches.size()) return PowerSwitchState::Off;
    
    return PowerSwitchState::Mixed;
}

void MainPowerSwitch::turnOn() {
    for (auto& ps : powerSwitches) {
        ps->turnOn();
    }
}

void MainPowerSwitch::turnOff() {
    for (auto& ps : powerSwitches) {
        ps->turnOff();
    }
}

void MainPowerSwitch::flip() {
    for (auto& ps : powerSwitches) {
        ps->flip();
    }
}

int MainPowerSwitch::countPower() {
    int total = 0;
    for (const auto& ps : powerSwitches) {
        total += ps->countPower();
    }
    return total;
}

std::vector<std::shared_ptr<PowerSwitch>> MainPowerSwitch::findPowerSwitchByName(const std::string name) {
    std::vector<std::shared_ptr<PowerSwitch>> result;

    for (auto& ps : powerSwitches) {
        if (ps->getName() == name) {
            result.push_back(ps);
        }else{
            auto mainPS = std::dynamic_pointer_cast<MainPowerSwitch>(ps);
            if (mainPS) {
                auto subResult = mainPS->findPowerSwitchByName(name);
                result.insert(result.end(), subResult.begin(), subResult.end());
            }
        }
    }
    return result;
}

std::vector<std::shared_ptr<Device>> MainPowerSwitch::findDeviceByName(std::string name) {
    std::vector<std::shared_ptr<Device>> result;

    for (auto& ps : powerSwitches) {
        auto normalPS = std::dynamic_pointer_cast<NormalPowerSwitch>(ps);
        if (normalPS) {
            auto dev = normalPS->getDevice();
            if (dev != nullptr && dev->getName() == name) {
                result.push_back(dev);
            }
        }

        auto mainPS = std::dynamic_pointer_cast<MainPowerSwitch>(ps);
        if (mainPS) {
            auto subResult = mainPS->findDeviceByName(name);
            result.insert(result.end(), subResult.begin(), subResult.end());
        }
    }
    return result;
}

std::vector<std::shared_ptr<Device>> MainPowerSwitch::findDeviceByDeviceType(DeviceType type) {
    std::vector<std::shared_ptr<Device>> result;

    for (auto& ps : powerSwitches) {
        auto normalPS = std::dynamic_pointer_cast<NormalPowerSwitch>(ps);
        if (normalPS) {
            auto dev = normalPS->getDevice();
            if (dev != nullptr && dev->getDeviceType() == type) {
                result.push_back(dev);
            }
        }

        auto mainPS = std::dynamic_pointer_cast<MainPowerSwitch>(ps);
        if (mainPS) {
            auto subResult = mainPS->findDeviceByDeviceType(type);
            result.insert(result.end(), subResult.begin(), subResult.end());
        }
    }
    return result;
}