#include "Armor.hpp"
Armor::Armor(ArmorType armorType):type_(armorType),Enchant_(Enchantment::NaN) {

}
ArmorType Armor::GetArmorType() {
    return type_;
}
void Armor::ApplyEnchantment(const Enchantment e) {
    Enchant_=e;
}
Enchantment Armor::GetEnchantment() {
    return Enchant_;
}