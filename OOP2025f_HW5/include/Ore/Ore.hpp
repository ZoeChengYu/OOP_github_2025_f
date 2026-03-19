#ifndef ORE_HPP
#define ORE_HPP

#include "Product.hpp"
#include "BreakExp.hpp"
#include "DurabilityCost.hpp"


class Ore {
private:
    Product product;
     int durabilityCost;
public:
    explicit Ore(Product product, int durabilityCost);
    virtual  ~Ore();

    virtual  Product GetProduct() const;
    virtual  int GetDurabilityCost() const;

    virtual float GetBreakExp()=0;
};

#endif
