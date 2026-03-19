#ifndef STICK_HPP
#define STICK_HPP

#include "IConsumable.hpp"

class Stick final:public IConsumable{
private:
public:
    Stick();
    ~Stick();
    Material GetMaterial() const override;
};








#endif