#ifndef INGOT_HPP
#define INGOT_HPP

#include "Material.hpp"
#include "IConsumable.hpp"

class Ingot : public IConsumable{
    Material type_;
public:
    Ingot(Material material);
    ~Ingot();
    Material GetMaterial() const override;
};

#endif
