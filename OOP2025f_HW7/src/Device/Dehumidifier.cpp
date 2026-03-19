#include "Device/Dehumidifier.hpp"
#include <stdexcept>
Dehumidifier::Dehumidifier(std::string name, int power) :Device(DeviceType::Dehumidifier,name,power){
    if (power<150||power>350) {
        throw std::invalid_argument("power must be between 150 and 350");
    }
    humidity=0;
}
Dehumidifier::Dehumidifier(std::string name, int power, int humidity) :Device(DeviceType::Dehumidifier,name,power){
    if (power<150||power>350) {
        throw std::invalid_argument("power must be between 150 and 350");
    }
    if (humidity<0||humidity>100) {
        throw std::invalid_argument("please enter a value between 0 and 100");
    }
    this->humidity=humidity;
}
Dehumidifier::~Dehumidifier() {

}
int Dehumidifier::getHumidity() {
    return humidity;
}
void Dehumidifier::setHumidity(int humidity) {
    if (humidity<0||humidity>100) {
        throw std::invalid_argument("please enter a value between 0 and 100");
    }
    this->humidity=humidity;
}
