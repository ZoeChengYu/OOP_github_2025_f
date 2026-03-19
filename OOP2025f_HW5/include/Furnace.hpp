#ifndef FURNACE_HPP
#define FURNACE_HPP

#include <memory>
#include <vector>

#include "Ore/Ore.hpp"
#include "Ore/SmeltableOre.hpp"
#include "Ore/GoldOre.hpp"
#include "Ore/IronOre.hpp"

class Furnace final {
    std::vector<std::shared_ptr<Ore>> FurnaceOre;
    Product FurnaceProduct;
public:
    Furnace();
    ~Furnace();

    std::vector<std::shared_ptr<Ore>> PickupProduct();

    void AddOre(std::shared_ptr<SmeltableOre> ore);

    void AddAnyOre(std::shared_ptr<Ore> ore);
};

#endif
