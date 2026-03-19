#ifndef LOUDSPEAKER_HPP
#define LOUDSPEAKER_HPP

#include "Device.hpp"

class Loudspeaker : public Device{
    int volume;
public:
    Loudspeaker(std::string name, int power);
    Loudspeaker(std::string name, int power, int volume);
    ~Loudspeaker();

    void setVolume(int volume);
    int getVolume();
};

#endif