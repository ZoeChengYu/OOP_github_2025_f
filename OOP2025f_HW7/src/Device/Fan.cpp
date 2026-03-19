#include "Device/Fan.hpp"

#include <stdexcept>
Fan::Fan(std::string name, int power):Device(DeviceType::Fan,name,power) {
    if (power<15||power>40) {
        throw std::invalid_argument("power must be between 15 and 40");
    }
    this->speed=FanSpeed::Low;

}
Fan::Fan(std::string name, int power, FanSpeed speed):Device(DeviceType::Fan,name,power) {
    if (power<15||power>40) {
        throw std::invalid_argument("power must be between 15 and 40");
    }
    this->speed=speed;
}
Fan::~Fan() {

}
void Fan::setSpeed(FanSpeed speed) {
    this->speed=speed;
}

FanSpeed Fan::getSpeed() {
    return speed;
}
