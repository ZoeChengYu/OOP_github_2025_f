#include "Device/Light.hpp"
#include <stdexcept>

Light::Light(std::string name, int power) :Device(DeviceType::Light,name,power){
    if (power<5||power>20) {
        throw std::invalid_argument("power must be between 5 and 20");
    }
    this->intensity=0;

}
Light::Light(std::string name, int power, int intensity):Device(DeviceType::Light,name,power) {
    if (power<5||power>20) {
        throw std::invalid_argument("power must be between 5 and 20");
    }
    if (intensity<0||intensity>100) {
        throw std::invalid_argument("intensity must be between 0 and 100");
    }
    this->intensity = intensity;
}
Light::~Light() {

}
void Light::setIntensity(int intensity) {
    if (intensity<0||intensity>100) {
        throw std::invalid_argument("intensity must be between 0 and 100");
    }
    this->intensity = intensity;
}
int Light::getIntensity() {
    return this->intensity;
}
