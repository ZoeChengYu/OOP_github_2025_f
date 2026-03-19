#include "Pickaxe.hpp"
Pickaxe::Pickaxe(PickaxeType pickaxeType) :type_(pickaxeType),Enchant_((Enchantment::NaN)){

}
PickaxeType Pickaxe::GetPickaxeType() {
    return type_;
}
void Pickaxe::ApplyEnchantment(const Enchantment e) {
    Enchant_=e;
}
Enchantment Pickaxe::GetEnchantment() {
    return Enchant_;
}