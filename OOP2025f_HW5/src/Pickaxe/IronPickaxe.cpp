#include "Pickaxe/IronPickaxe.hpp"
#include <stdexcept>
 IronPickaxe::IronPickaxe() :Pickaxe(PickaxeType::Iron,Durability::IronDurability){

}
Product IronPickaxe::Mining(std::shared_ptr<Ore> &ore) {
     if (ore.get() == nullptr) {
         throw std::invalid_argument("ore is null");
     }
     if (this->GetDurability() < ore->GetDurabilityCost()) {
         throw std::invalid_argument("durability < ore->GetDurabilityCost()");
     }
     Product type=ore->GetProduct();
     this->SetDurability(ore->GetDurabilityCost());

     Product result= type;
     if (type==Product::Obsidian) {
         result=Product::None;
     }
     ore=nullptr;
     return result;
 }
