#include "Ore/DiamondOre.hpp"

DiamondOre::DiamondOre()
    : Ore(Product::Diamond, DurabilityCost::DiamondDurabilityCost) {
}

float DiamondOre::GetBreakExp() {
    return BreakExp::DiamondBreakExp;
}