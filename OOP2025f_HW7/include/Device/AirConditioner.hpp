#ifndef AIRCONDITIONER_HPP
#define AIRCONDITIONER_HPP

#include "Device.hpp"

class AirConditioner : public Device {
    int temperature;
public:
    AirConditioner(std::string name, int power);
    AirConditioner(std::string name, int power, int temperature);
    ~AirConditioner();

    void setTemperature(int temperature);
    int getTemperature();
};

#endif
