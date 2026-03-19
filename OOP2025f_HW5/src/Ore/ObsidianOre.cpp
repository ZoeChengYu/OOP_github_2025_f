#include "Ore/ObsidianOre.hpp"

ObsidianOre::ObsidianOre()
    : Ore(Product::Obsidian, DurabilityCost::ObsidianDurabilityCost) {
}

float ObsidianOre::GetBreakExp() {
    return BreakExp::ObsidianBreakExp;
}