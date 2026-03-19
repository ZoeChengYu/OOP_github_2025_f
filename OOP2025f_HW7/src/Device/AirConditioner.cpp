#include "Device/AirConditioner.hpp"
#include <stdexcept>
AirConditioner::AirConditioner(std::string name, int power):Device(DeviceType::AirConditioner,name,power) {
    if (power<500||power>2000) {
        throw std::invalid_argument("power must be between 500 and 2000");
    }
    temperature=25;

}
AirConditioner::AirConditioner(std::string name, int power, int temperature):Device(DeviceType::AirConditioner,name,power) {
    if (power<500||power>2000) {
        throw std::invalid_argument("power must be between 50 and 2000");
    }
    if (temperature<10||temperature>35) {
        throw std::invalid_argument("Temperature out of range");
    }
    this->temperature=temperature;
}
AirConditioner::~AirConditioner() {

}
void AirConditioner::setTemperature(int temperature) {
    if (temperature<10||temperature>35) {
        throw std::invalid_argument("Temperature out of range");
    }
    this->temperature=temperature;
}
int AirConditioner::getTemperature() {
    return temperature;
}
