#ifndef GOLDENPICKAXE_HPP
#define GOLDENPICKAXE_HPP
#include "Pickaxe.hpp"

class GoldPickaxe final:public Pickaxe{
public:
    explicit GoldPickaxe();
    ~GoldPickaxe() override=default;
    Product Mining(std::shared_ptr<Ore> &ore) override;
};

#endif
