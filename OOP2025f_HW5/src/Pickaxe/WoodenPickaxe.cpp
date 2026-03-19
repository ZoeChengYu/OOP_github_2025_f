#include "Pickaxe/WoodenPickaxe.hpp"
#include <stdexcept>
 WoodenPickaxe::WoodenPickaxe() : Pickaxe(PickaxeType::Wooden,Durability::WoodenDurability){

}
Product WoodenPickaxe::Mining(std::shared_ptr<Ore> &ore) {
     if (ore.get() == nullptr) {
         throw std::invalid_argument("ore is null");
     }
     if (this->GetDurability() < ore->GetDurabilityCost()) {
         throw std::invalid_argument("durability < ore->GetDurabilityCost()");
     }
     Product type=ore->GetProduct();
     if (type==Product::Obsidian) {
         throw std::invalid_argument("ore->GetProduct() == Product::Obsidian()");
     }
         this->SetDurability(ore->GetDurabilityCost());

         Product result= Product::None;
         if (type==Product::Coal) {
              result=type;
         }
         ore=nullptr;
         return result;

 }

