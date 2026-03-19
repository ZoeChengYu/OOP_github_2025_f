#include "EnchantingTable.hpp"

#include <stdexcept>
EnchantingTable::EnchantingTable() {

}
EnchantingTable::~EnchantingTable() {

}
void EnchantingTable::SetConsumeItem(std::shared_ptr<IConsumable> comsumable) {
    comsum_ = comsumable;
}
void EnchantingTable::SetEnchantItem(
    std::shared_ptr<IEnchantable> emchantable) {
    emchant_ = emchantable;
}
void EnchantingTable::Enchant(Enchantment e) {
    if (emchant_ == nullptr||comsum_ == nullptr||output_ != nullptr) {
        throw std::invalid_argument("EnchantingTable::Enchant()");
    }
    emchant_->ApplyEnchantment(e);
    output_=emchant_;
    emchant_=nullptr;
    comsum_=nullptr;
}
std::shared_ptr<IEnchantable> EnchantingTable::GetOutput() {
    if (output_ == nullptr) {
        throw std::invalid_argument("EnchantingTable::GetOutput()");
    }
    return output_;
}