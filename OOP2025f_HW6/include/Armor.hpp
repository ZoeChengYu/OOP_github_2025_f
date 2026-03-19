#ifndef ARMOR_HPP
#define ARMOR_HPP

#include "IEnchantable.hpp"

enum class ArmorType {
    Iron,
    Gold,
    Diamond,
};

class Armor final:public IEnchantable{
    ArmorType type_;
    Enchantment Enchant_;
public:
    Armor(ArmorType armorType);
    ArmorType GetArmorType();
    Enchantment GetEnchantment();
    void ApplyEnchantment(const Enchantment e) override;
};

#endif
