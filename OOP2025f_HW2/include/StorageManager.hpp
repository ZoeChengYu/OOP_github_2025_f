#ifndef STORAGEMANAGER_HPP
#define STORAGEMANAGER_HPP

#include "Storage.hpp"
#include <vector>     // <-- 修正：需要包含 <vector> 才能使用 std::vector
#include <stdexcept>  // <-- 建議：雖然非必要，但有助於了解此類別可能拋出例外

class StorageManager {
public:
    StorageManager();

    void AddAllStorageCapacity(int capacity);
    void moveCapacity(StorageType fromType, StorageType toType, int moveCapacity);

    // [[nodiscard]] 是一個很好的屬性，保留它
    [[nodiscard]] std::vector<Storage>& getStorages();

private:
    std::vector<Storage> storages;
};

#endif // STORAGEMANAGER_HPP