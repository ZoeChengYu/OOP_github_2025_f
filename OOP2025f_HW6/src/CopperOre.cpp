#include "CopperOre.hpp"

#include "Ingot.hpp"

bool CopperOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type=pickaxe.GetPickaxeType();
    return type==PickaxeType::Stone || type==PickaxeType::Iron || type==PickaxeType::Diamond;
}

std::shared_ptr<Ingot> CopperOre::Smelt() {
    return std::make_shared<Ingot>(Material::Copper);
}
Material CopperOre::GetMaterial()const {
    return Material::Copper;
}
CopperOre::CopperOre() {

}
CopperOre::~CopperOre() {

}