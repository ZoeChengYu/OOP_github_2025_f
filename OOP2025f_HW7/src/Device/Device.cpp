#include "Device/Device.hpp"
Device::Device(DeviceType deviceType, std::string name, int power) {
    this->deviceType = deviceType;
    this->name = name;
    this->power = power;
}
Device::~Device() {

}
std::string Device::getName() {
    return this->name;
}
int Device::getPower() {
    return this->power;
}
DeviceType Device::getDeviceType() {
    return this->deviceType;
}
