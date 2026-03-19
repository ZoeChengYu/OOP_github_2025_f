#ifndef IRONORE_HPP
#define IRONORE_HPP

#include "SmeltableOre.hpp"

class IronOre : public SmeltableOre {
public:
    IronOre();
    ~IronOre() override = default;
    float GetBreakExp() override;
    float GetSmeltExp() override;
};

#endif