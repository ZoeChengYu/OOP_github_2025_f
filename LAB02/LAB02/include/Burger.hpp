#ifndef BURGER_HPP
#define BURGER_HPP

#include <set>
#include <memory>
#include <stdexcept>

#include "Ingredient.hpp"

#include "IFood.hpp"
#include "ICookable.hpp"
#include "ICustomizable.hpp"

class Burger : public IFood, public ICookable, public ICustomizable {
private:
    const std::set<Ingredient> availableIngredient = {Ingredient::Bread, Ingredient::Meat, Ingredient::Lettuce, Ingredient::Cheese};
    std::vector<Ingredient> ingredient;

    const FoodType foodtype = FoodType::Burger;

    bool done = false;

    const std::set<Option> availableOption = {Option::None, Option::Large, Option::AddOnions, Option::AddPickles};
    Option option = Option::None;

public:
    Burger(std::vector<Ingredient> ingredient);

    std::vector<Ingredient> GetIngredient() override;
    FoodType GetFoodType() override;
    bool IsDone() override;

    void Cook() override;

    void AddOption(Option option) override;
    Option GetOption() override;
};

#endif
