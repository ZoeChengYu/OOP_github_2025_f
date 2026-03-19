#ifndef IRONPICKAXE_HPP
#define IRONPICKAXE_HPP
#include "Pickaxe.hpp"

class IronPickaxe final:public Pickaxe{
public:
    explicit IronPickaxe();
    ~IronPickaxe() override=default;
    Product Mining(std::shared_ptr<Ore> &ore) override;
};

#endif
