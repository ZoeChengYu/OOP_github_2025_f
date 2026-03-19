#ifndef FOOD_HPP
#define FOOD_HPP

#include "Ingredient.hpp"
#include "FoodType.hpp"
#include <vector>
#include <iostream>
#include <memory>
#include <stdexcept>
#include "ToString.hpp"

class Food{

    Ingredient ingredient;
    FoodType foodType;
    int price;
public:
    Food(Ingredient ingredient);
    virtual ~Food() = default;
    Ingredient GetIngredient();
    virtual void Cook() = 0;
    FoodType GetFoodType();
    int GetPrice();
    void CountFoodPrice();
};

#endif