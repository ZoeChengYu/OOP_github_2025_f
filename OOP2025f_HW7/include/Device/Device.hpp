#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "DeviceType.hpp"
#include <string>

class Device{
    DeviceType deviceType;
    std::string name;
    int power;
public:
    Device(DeviceType deviceType, std::string name, int power);
    ~Device();

    DeviceType getDeviceType();
    std::string getName();
    int getPower();
};

#endif
