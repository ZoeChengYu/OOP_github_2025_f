#ifndef CRAFTING_TABLE_HPP
#define CRAFTING_TABLE_HPP

#include <memory>

#include "Armor.hpp"
#include "IConsumable.hpp"
#include "Pickaxe.hpp"

class CraftingTable final {
    std::shared_ptr<IConsumable> craftable_ = nullptr;
    std::shared_ptr<IEnchantable> output_ = nullptr;
    std::shared_ptr<IConsumable> material_ = nullptr;
public:
    CraftingTable();
    ~CraftingTable();
    void Craft();

    void SetCraftInput(std::shared_ptr<IConsumable> craftableItem);
    void SetMaterialInput(std::shared_ptr<IConsumable> materialItem);
    std::shared_ptr<IEnchantable> GetOutput();
};

#endif
