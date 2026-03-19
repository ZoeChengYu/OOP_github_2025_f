#include "Device/Loudspeaker.hpp"
#include <stdexcept>
Loudspeaker::Loudspeaker(std::string name, int power) :Device(DeviceType::Loudspeaker,name,power){
    if (power<5||power>200) {
        throw std::invalid_argument("power must be between 5 and 200");
    }
    volume=0;
}
Loudspeaker::Loudspeaker(std::string name, int power, int volume):Device(DeviceType::Loudspeaker,name,power) {
    if (power<5||power>200) {
        throw std::invalid_argument("power must be between 5 and 200");
    }
    if (volume<0||volume>100) {
        throw std::invalid_argument("Volume must be between 0 and 100");
    }
    this->volume=volume;
}
Loudspeaker::~Loudspeaker() {

}
void Loudspeaker::setVolume(int volume) {
    if (volume<0||volume>100) {
        throw std::invalid_argument("Volume must be between 0 and 100");
    }
    this->volume=volume;
}
int Loudspeaker::getVolume() {
    return this->volume;
}
