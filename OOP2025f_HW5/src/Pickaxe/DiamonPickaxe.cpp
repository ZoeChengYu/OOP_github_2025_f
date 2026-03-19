#include "Pickaxe/DiamondPickaxe.hpp"
#include <stdexcept>
 DiamondPickaxe::DiamondPickaxe():Pickaxe(PickaxeType::Diamond,Durability::DiamondDurability) {

}
Product DiamondPickaxe::Mining(std::shared_ptr<Ore> &ore) {
     if (ore.get() == nullptr) {
         throw std::invalid_argument("ore is null");
     }
     if (this->GetDurability() < ore->GetDurabilityCost()) {
         throw std::invalid_argument("durability < ore->GetDurabilityCost()");
     }
     Product type=ore->GetProduct();
     this->SetDurability(ore->GetDurabilityCost());

     Product result= type;
     ore=nullptr;
     return result;
 }
