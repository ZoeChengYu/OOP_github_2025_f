#include "Storage.hpp"
#include <stdexcept>
#include <vector>
#include<algorithm>

Storage::Storage(StorageType storageType) {
    type = storageType;
    capacity = 10;
    amount = 0;
}

Storage::Storage(StorageType storageType, int storageCapacity) {
    type = storageType;
    capacity = storageCapacity;
    amount = 0;
}

void Storage::add(std::string snackName){
    if (amount + 1 > capacity) {
        throw std::invalid_argument("capacity exceeded");
    }
    // 找尋是否已有相同名稱的點心
    for (auto& snack : snacks) {
        if (snack.getName() == snackName) {
            snack.setAmount(snack.getAmount() + 1);
            amount += 1;
            return;
        }
    }
    // 不存在則建立新點心（初始數量 1）
    snacks.push_back(Snack(snackName, 1));
    amount += 1;
}

void Storage::add(std::string snackName, int snackAmount){
    if (snackAmount <= 0) return;
    if (amount + snackAmount > capacity) {
        throw std::invalid_argument("capacity exceeded");
    }
    // 找尋是否已有相同名稱的點心
    for (auto& snack : snacks) {
        if (snack.getName() == snackName) {
            snack.setAmount(snack.getAmount() + snackAmount);
            amount += snackAmount;
            return;
        }
    }
    // 不存在則建立新點心（初始數量 snackAmount）
    snacks.push_back(Snack(snackName, snackAmount));
    amount += snackAmount;
}

void Storage::eat(std::string snackName, int snackAmount){
    for(auto it=snacks.begin(); it!=snacks.end(); ++it){
        if(it->getName() == snackName){
            if(it->getAmount() < snackAmount){
                throw std::invalid_argument("not enough snack");
            }
            it->setAmount(it->getAmount() - snackAmount);
            amount -= snackAmount;
            if (it->getAmount() == 0) {
                snacks.erase(it);
            }
            return;
        }
    }
    throw std::invalid_argument("snack not found");
}

void Storage::eatFirst(int snackAmount){
    if (snacks.empty()) {
        throw std::invalid_argument("no snacks");
    }
    auto it = snacks.begin();
    if (it->getAmount() < snackAmount) {
        throw std::invalid_argument("not enough snack");
    }
    it->setAmount(it->getAmount() - snackAmount);
    amount -= snackAmount;
    if (it->getAmount() == 0) {
        snacks.erase(it);
    }
}

void Storage::eatLast(int snackAmount){
    if (snacks.empty()) {
        throw std::invalid_argument("no snacks");
    }
    auto it = snacks.end() - 1;
    if (it->getAmount() < snackAmount) {
        throw std::invalid_argument("not enough snack");
    }   
    it->setAmount(it->getAmount() - snackAmount);
    amount -= snackAmount;
    if (it->getAmount() == 0) {
        snacks.erase(it);
    }
}

void Storage::sortByAmount(){
    std::sort(snacks.begin(), snacks.end(), [](const Snack& a, const Snack& b) {
        return a.getAmount() < b.getAmount();
    });
}

void Storage::sortBySnackName(){
    std::sort(snacks.begin(), snacks.end(), [](const Snack& a, const Snack& b) {
        return a.getName() < b.getName();
    });
}

void Storage::clear(){
    snacks.clear();
    amount = 0;
}

int Storage::getAmount() const{
    return this->amount;
}

int Storage::getCapacity() const{
    return this->capacity;

}

StorageType Storage::getType() const{
    return this->type;
}

const std::vector<Snack>& Storage::getSnacks() const {
    return this->snacks;
}

void Storage::setCapacity(int storageCapacity) {
    this->capacity = storageCapacity;
}