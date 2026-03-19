#include "Pickaxe/Pickaxe.hpp"

 Pickaxe::Pickaxe(PickaxeType pickaxeType, int durability) {
    this->durability = durability;
     this->pickaxeType = pickaxeType;
}

 Pickaxe::~Pickaxe() {

}
PickaxeType Pickaxe::GetPickaxeType() const {
     return this->pickaxeType;
 }

int Pickaxe::GetDurability() const {
     return this->durability;
 }
void Pickaxe::SetDurability(int cost) {
     this->durability -= cost;
 }