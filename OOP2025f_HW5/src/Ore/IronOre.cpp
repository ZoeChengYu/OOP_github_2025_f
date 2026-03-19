#include "Ore/IronOre.hpp"

IronOre::IronOre()
    : SmeltableOre(Product::Iron, DurabilityCost::IronDurabilityCost) {
}

float IronOre::GetBreakExp() {
    return BreakExp::IronBreakExp;
}

float IronOre::GetSmeltExp() {
    return SmeltExp::IronSmeltExp;
}