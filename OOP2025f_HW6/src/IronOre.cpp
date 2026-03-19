#include "IronOre.hpp"

IronOre::IronOre() {
}
IronOre::~IronOre() {

}
bool IronOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type=pickaxe.GetPickaxeType();
    return type==PickaxeType::Diamond||type==PickaxeType::Iron||type==PickaxeType::Stone;
}

std::shared_ptr<Ingot> IronOre::Smelt() {
    return std::make_shared<Ingot>(Material::Iron);
}