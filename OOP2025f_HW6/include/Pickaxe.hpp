#ifndef PICKAXE_HPP
#define PICKAXE_HPP

#include "IEnchantable.hpp"

enum class PickaxeType {
    Wood,
    Stone,
    Gold,
    Iron,
    Diamond,
};

class Pickaxe final :public IEnchantable{
    PickaxeType type_;
    Enchantment Enchant_;
public:
    Pickaxe(PickaxeType pickaxeType);
    PickaxeType GetPickaxeType();
    Enchantment GetEnchantment();
    void ApplyEnchantment(const Enchantment e) override;
};

#endif
