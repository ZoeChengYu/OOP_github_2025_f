#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "IConsumable.hpp"

class Diamond final :public IConsumable{
public:
    Diamond();
    ~Diamond();
    Material GetMaterial() const override;
};

#endif
