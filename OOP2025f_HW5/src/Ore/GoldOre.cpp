#include "Ore/GoldOre.hpp"

GoldOre::GoldOre()
    : SmeltableOre(Product::Gold, DurabilityCost::GoldDurabilityCost) {
}

float GoldOre::GetBreakExp() {
    return BreakExp::GoldBreakExp;
}

float GoldOre::GetSmeltExp() {
    return SmeltExp::GoldSmeltExp;
}