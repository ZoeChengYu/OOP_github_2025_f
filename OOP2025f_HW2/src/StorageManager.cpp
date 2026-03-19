#include "StorageManager.hpp"
#include <stdexcept>
#include <vector>

StorageManager::StorageManager() {
    storages.emplace_back(StorageType::CANDY);
    storages.emplace_back(StorageType::COOKIES);
    storages.emplace_back(StorageType::CAKE);
    storages.emplace_back(StorageType::OTHER);
}

void StorageManager::AddAllStorageCapacity(int capacity) {
    if (capacity < 0) {
        for (const auto& storage : storages) {
            int newCapacity = storage.getCapacity() + capacity;
            if (newCapacity < storage.getAmount()) {
                // 這是 "all-or-nothing" 檢查。如果任一個儲存庫不符規定，
                // 則所有儲存庫的容量都不會被更改。
                throw std::invalid_argument("Cannot reduce capacity below current amount for one or more storages.");
            }
        }
    }

    // 通過檢查後（或 capacity 為正數），才實際更新容量
    for (auto& storage : storages) {
        storage.setCapacity(storage.getCapacity() + capacity);
    }
}

void StorageManager::moveCapacity(StorageType fromType, StorageType toType, int moveCapacity) {
    
    // 檢查 1：不能移動負數容量
    if (moveCapacity < 0) {
        throw std::invalid_argument("Cannot move a negative capacity.");
    }

    // 檢查 2：移動 0 或移動到自身，直接返回
    if (moveCapacity == 0 || fromType == toType) {
        return; 
    }

    Storage* fromStorage = nullptr;
    Storage* toStorage = nullptr;

    for (auto& storage : storages) {
        if (storage.getType() == fromType) {
            fromStorage = &storage;
        } else if (storage.getType() == toType) {
            toStorage = &storage;
        }
        
        if (fromStorage && toStorage) {
            break; 
        }
    }

    if (fromStorage && toStorage) {
        // --- 核心修正 ---
        // 根據 test_move_capacity_throws 測試，
        // 我們必須檢查 "新容量" 是否會低於 "現有物品數量 (amount)"。
        
        int newCapacity = fromStorage->getCapacity() - moveCapacity;

        if (newCapacity < fromStorage->getAmount()) {
            // 這個檢查同時也涵蓋了 "fromStorage->getCapacity() < moveCapacity" 的情況
            // (因為 newCapacity 會是負數，而 getAmount() 必定 >= 0)。
            throw std::invalid_argument("Cannot move capacity, new capacity would be less than current amount.");
        }
        
        // 執行移動
        fromStorage->setCapacity(newCapacity); // 使用已計算好的 newCapacity
        toStorage->setCapacity(toStorage->getCapacity() + moveCapacity);

    } else {
        // fromStorage 或 toStorage 之一 (或兩者) 未找到
        throw std::invalid_argument("Invalid storage type specified.");
    }
}

std::vector<Storage>& StorageManager::getStorages() {
    return storages;
}