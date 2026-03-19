#ifndef FURNACE_HPP
#define FURNACE_HPP

#include <memory>

#include "ISmeltable.hpp"
#include "Ingot.hpp"

class Furnace final {
    std::shared_ptr<ISmeltable> input_ =nullptr;
    std::shared_ptr<Ingot> output_ = nullptr;
public:
    Furnace();
    ~Furnace();
    void Smelt();

    void SetInput(std::shared_ptr<ISmeltable> input);
    std::shared_ptr<Ingot> GetOutput();
};

#endif
