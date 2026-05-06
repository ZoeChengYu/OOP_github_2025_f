#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <memory>
#include <vector>
#include <stdexcept>

#include "IFood.hpp"
#include "ICookable.hpp"
#include "IPreparable.hpp"

class Manager{
private:
    std::vector<std::shared_ptr<IFood>> food;

public:
    Manager() = default;
    void SetFood(std::vector<std::shared_ptr<IFood>> food);
    void MakeFood();
    std::vector<std::shared_ptr<IFood>> GetFood();
};

#endif