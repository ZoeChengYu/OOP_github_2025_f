#ifndef WOODENPACKAXE_HPP
#define WOODENPACKAXE_HPP
#include "Pickaxe.hpp"

class WoodenPickaxe final: public Pickaxe{
public:
    explicit WoodenPickaxe();
    ~WoodenPickaxe() override=default;
    Product Mining(std::shared_ptr<Ore> &ore) override;
};

#endif
