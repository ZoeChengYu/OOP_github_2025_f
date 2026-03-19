#include "DiamondOre.hpp"

bool DiamondOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type=pickaxe.GetPickaxeType();
    return type==PickaxeType::Diamond || type==PickaxeType::Iron;
}

Material DiamondOre::GetMaterial() const {
    return Material::Diamond;
}
DiamondOre::DiamondOre() {

}
DiamondOre::~DiamondOre() {

}