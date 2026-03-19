#include "LapisLazuliOre.hpp"

bool LapisLazuliOre::BreakableBy(Pickaxe pickaxe) {
    PickaxeType type=pickaxe.GetPickaxeType();
    return type==PickaxeType::Diamond||type==PickaxeType::Iron||type==PickaxeType::Stone;
}

Material LapisLazuliOre::GetMaterial()const {
    return Material::LapisLazuli;
}
LapisLazuliOre::LapisLazuliOre() {

}
LapisLazuliOre::~LapisLazuliOre() {

}