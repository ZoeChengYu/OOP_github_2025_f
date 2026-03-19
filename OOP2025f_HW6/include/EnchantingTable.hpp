#ifndef ENCHANTING_TABLE_HPP
#define ENCHANTING_TABLE_HPP

#include <memory>
#include "IEnchantable.hpp"
#include "IConsumable.hpp"
#include "Enchantment.hpp"

class EnchantingTable{
    std::shared_ptr<IEnchantable> emchant_=nullptr;
    std::shared_ptr<IConsumable> comsum_=nullptr;
    std::shared_ptr<IEnchantable> output_=nullptr;
public:
    EnchantingTable();
    ~EnchantingTable();

    void SetEnchantItem(std::shared_ptr<IEnchantable> emchantable);
    void SetConsumeItem(std::shared_ptr<IConsumable> comsumable);
    void Enchant(Enchantment e);
    std::shared_ptr<IEnchantable> GetOutput();
};

#endif