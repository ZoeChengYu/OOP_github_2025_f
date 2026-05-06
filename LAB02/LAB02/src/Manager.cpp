#include "Manager.hpp"

void Manager::SetFood(std::vector<std::shared_ptr<IFood>> food) {
    this->food = food;
}

void Manager::MakeFood() {
    for (std::shared_ptr<IFood> f : this->food) {
        if (auto cookable = std::dynamic_pointer_cast<ICookable>(f)) {
            cookable->Cook();
            continue;
        }

        if (auto preparable = std::dynamic_pointer_cast<IPreparable>(f)) {
            preparable->Prepare();
            continue;
        }

        throw std::invalid_argument("Unknow operate");
    }
}

std::vector<std::shared_ptr<IFood>> Manager::GetFood() {
    return this->food;
}
