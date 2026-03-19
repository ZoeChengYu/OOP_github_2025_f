#include "CraftingTable.hpp"

#include <stdexcept>
#include <utility>
CraftingTable::CraftingTable() {

}
CraftingTable::~CraftingTable() {

}
void CraftingTable::SetCraftInput(std::shared_ptr<IConsumable> craftableItem) {
    if (craftableItem->GetMaterial()==Material::Copper||craftableItem->GetMaterial()==Material::LapisLazuli||craftableItem->GetMaterial()==Material::Stick) {
        throw std::invalid_argument("CraftingTable::SetCraftInput()");
    }
    craftable_=craftableItem;
}
void CraftingTable::SetMaterialInput(
    std::shared_ptr<IConsumable> materialItem) {
    if (materialItem->GetMaterial()!=Material::Stick) {
        throw std::invalid_argument("CraftingTable::SetMaterialInput()");
    }
    material_=materialItem;
}
void CraftingTable::Craft() {
    if (craftable_==nullptr||output_!=nullptr) {
        throw std::invalid_argument("CraftingTable::SetCraft()");
    }
    Material m=craftable_->GetMaterial();
    std::shared_ptr<IEnchantable> NewItem;
    if (material_==nullptr) {
        if (m==Material::Iron){NewItem=std::make_shared<Armor>(ArmorType::Iron);}
        else if (m==Material::Gold){NewItem=std::make_shared<Armor>(ArmorType::Gold);}
        else if (m==Material::Diamond){NewItem=std::make_shared<Armor>(ArmorType::Diamond);}
    }else {
        if (m==Material::Diamond){NewItem=std::make_shared<Pickaxe>(PickaxeType::Diamond);}
        else if (m==Material::Gold){NewItem=std::make_shared<Pickaxe>(PickaxeType::Gold);}
        else if (m==Material::Iron){NewItem=std::make_shared<Pickaxe>(PickaxeType::Iron);}
    }
    output_=NewItem;
}
std::shared_ptr<IEnchantable> CraftingTable::GetOutput() {
    if (output_==nullptr) {
        throw std::invalid_argument("CraftingTable::GetOutput()");
    }
    return output_;
}