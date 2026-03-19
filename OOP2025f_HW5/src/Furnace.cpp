#include "Furnace.hpp"

#include <stdexcept>
 Furnace::Furnace() {
     this->FurnaceProduct=Product::None;
     this->FurnaceOre.clear();
}
 Furnace::~Furnace() {

}
std::vector<std::shared_ptr<Ore>> Furnace::PickupProduct() {
     std::vector<std::shared_ptr<Ore>> result=this->FurnaceOre;
     this->FurnaceOre.clear();
     this->FurnaceProduct=Product::None;
     return result;
 }
void Furnace::AddOre(std::shared_ptr<SmeltableOre> ore) {
     if (ore==nullptr) {
         throw std::invalid_argument("nullptr");
     }
     if (this->FurnaceOre.size()>=64) {
         throw std::invalid_argument("Can't add another ore");
     }
     if (this->FurnaceProduct!=Product::None&&this->FurnaceProduct!=ore->GetProduct()) {
         throw std::invalid_argument("Can't add another ore");
     }
     this->FurnaceProduct=ore->GetProduct();
     this->FurnaceOre.push_back(ore);
 }
void Furnace::AddAnyOre(std::shared_ptr<Ore> ore) {
     if (ore==nullptr) {
         throw std::invalid_argument("nullptr");
     }
     std::shared_ptr<SmeltableOre> smeltable = std::dynamic_pointer_cast<SmeltableOre>(ore);
     if (smeltable==nullptr) {
         throw std::invalid_argument("Can't add another ore");
     }
     AddOre(smeltable);
 }
