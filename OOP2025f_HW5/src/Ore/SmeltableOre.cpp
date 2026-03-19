#include "Ore/SmeltableOre.hpp"

SmeltableOre::SmeltableOre(Product product, int durabilityCost)
    : Ore(product, durabilityCost) {
}

SmeltableOre::~SmeltableOre() {}

float SmeltableOre::GetSmeltExp() {
    return 0.0f;
}