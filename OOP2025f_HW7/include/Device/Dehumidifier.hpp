#ifndef DEHUMIDIFIER_HPP
#define DEHUMIDIFIER_HPP

#include "Device.hpp"

class Dehumidifier : public Device {
    int humidity;
public:
    Dehumidifier(std::string name, int power);
    Dehumidifier(std::string name, int power, int humidity);
    ~Dehumidifier();

    void setHumidity(int humidity);
    int getHumidity();
};

#endif
