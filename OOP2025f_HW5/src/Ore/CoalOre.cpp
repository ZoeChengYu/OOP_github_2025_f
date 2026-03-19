#include "Ore/CoalOre.hpp"

CoalOre::CoalOre()
    : Ore(Product::Coal, DurabilityCost::CoalDurabilityCost) {
}

float CoalOre::GetBreakExp() {
    return BreakExp::CoalBreakExp;
}