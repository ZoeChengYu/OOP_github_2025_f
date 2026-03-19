#include "PowerSwitch/NormalPowerSwitch.hpp"
#include <stdexcept>

NormalPowerSwitch::NormalPowerSwitch(std::string name) : PowerSwitch(name) {
    this->device = nullptr; 
    this->state = PowerSwitchState::Off;
}

NormalPowerSwitch::NormalPowerSwitch(std::string name, std::shared_ptr<Device> device) : PowerSwitch(name) {
    this->device = device; 
    this->state = PowerSwitchState::Off;
}

std::shared_ptr<Device> NormalPowerSwitch::getDevice() {
    return this->device;
}

std::string NormalPowerSwitch::getDeviceName() {
    if (this->device != nullptr) {
        return this->device->getName();
    }
    return "";
}

void NormalPowerSwitch::addDevice(std::shared_ptr<Device> device) {
    if (this->device != nullptr) {
        throw std::invalid_argument("Device already exists.");
    }
    this->device = device;
}

std::shared_ptr<Device> NormalPowerSwitch::removeDevice() {
    if (this->device == nullptr) {
        throw std::invalid_argument("No device to remove.");
    }
    std::shared_ptr<Device> temp = this->device;
    this->device = nullptr;
    return temp;
}

std::shared_ptr<Device> NormalPowerSwitch::changeDevice(std::shared_ptr<Device> device) {
    if (this->device == nullptr) {
        throw std::invalid_argument("No device to change.");
    }
    std::shared_ptr<Device> temp = this->device;
    this->device = device;
    return temp;
}

PowerSwitchState NormalPowerSwitch::getState() {
    return this->state;
}

void NormalPowerSwitch::turnOn() {
    this->state = PowerSwitchState::On;
}

void NormalPowerSwitch::turnOff() {
    this->state = PowerSwitchState::Off;
}

void NormalPowerSwitch::flip() {
    if (this->state == PowerSwitchState::On) {
        this->state = PowerSwitchState::Off;
    } else {
        this->state = PowerSwitchState::On;
    }
}

int NormalPowerSwitch::countPower() {
    if (this->device == nullptr) {
        return 0;
    }
    if (this->state == PowerSwitchState::On) {
        return this->device->getPower();
    } else {
        return 0;
    }
}