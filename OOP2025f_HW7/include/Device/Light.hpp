#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Device.hpp"

class Light : public Device {
    int intensity;
public:
    Light(std::string name, int power);
    Light(std::string name, int power, int intensity);
    ~Light();

    void setIntensity(int intensity);
    int getIntensity();
};

#endif
