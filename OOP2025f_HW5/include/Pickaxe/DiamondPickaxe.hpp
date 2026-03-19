#ifndef DIAMONDPICKAXE_HPP
#define DIAMONDPICKAXE_HPP
#include "Pickaxe.hpp"

class DiamondPickaxe final:public Pickaxe{
public:
    explicit DiamondPickaxe();
    ~DiamondPickaxe() override=default;
    Product Mining(std::shared_ptr<Ore> &ore) override;
};

#endif
