#ifndef STONEPICKAXE_HPP
#define STONEPICKAXE_HPP
#include "Pickaxe.hpp"

class StonePickaxe final:public Pickaxe{
public:
    explicit StonePickaxe();
    ~StonePickaxe() override = default;
    Product Mining(std::shared_ptr<Ore> &ore) override;
};

#endif
