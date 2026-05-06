#ifndef DRINK_HPP
#define DRINK_HPP

#include <set>
#include <memory>
#include <stdexcept>

#include "Ingredient.hpp"

#include "IFood.hpp"
#include "IPreparable.hpp"
#include "ICustomizable.hpp"

class Drink : public IFood, public IPreparable, public ICustomizable {
private:
    const std::set<Ingredient> availableIngredient = {Ingredient::Cola, Ingredient::CaramelMilkTea, Ingredient::BlackTea};
    std::vector<Ingredient> ingredient;

    const FoodType foodtype = FoodType::Drink;

    bool done = false;

    const std::set<Option> availableOption = {Option::None, Option::Large, Option::LessIce, Option::NoIce};
    Option option = Option::None;

public:
    Drink(std::vector<Ingredient> ingredient);

    std::vector<Ingredient> GetIngredient() override;
    FoodType GetFoodType() override;
    bool IsDone() override;

    void Prepare() override;

    void AddOption(Option option) override;
    Option GetOption() override;
};

#endif
