#include "Ore/Ore.hpp"
#include <stdexcept>

Ore::Ore(Product product, int durabilityCost) {
    if (product == Product::None) {
        throw std::invalid_argument("Product::None must be provided");
    }
    this->product = product;
    this->durabilityCost = durabilityCost;
}

Ore::~Ore() {}

Product Ore::GetProduct() const {
    return this->product;
}

int Ore::GetDurabilityCost() const {
    return this->durabilityCost;
}