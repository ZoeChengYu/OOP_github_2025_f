#ifndef PICKAXE_HPP
#define PICKAXE_HPP

#include <memory>

#include "Ore/Ore.hpp"
#include "PickaxeType.hpp"
#include "Durability.hpp"

class Pickaxe{
protected:
    PickaxeType pickaxeType;
    int durability;
public:
    Pickaxe(PickaxeType pickaxeType, int durability);
    virtual ~Pickaxe();

    virtual PickaxeType GetPickaxeType() const;
    virtual int GetDurability() const;
    virtual void SetDurability(int cost);

    virtual Product Mining(std::shared_ptr<Ore> &ore)=0;
};

#endif
