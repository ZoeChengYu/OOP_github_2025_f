#ifndef SALAD_HPP
#define SALAD_HPP

#include <set>
#include <memory>
#include <stdexcept>

#include "Ingredient.hpp"

#include "IFood.hpp"
#include "IPreparable.hpp"
#include "ICustomizable.hpp"

class Salad : public IFood, public IPreparable, public ICustomizable {
private:
    const std::set<Ingredient> availableIngredient = {Ingredient::Bread, Ingredient::Lettuce, Ingredient::Cheese};
    std::vector<Ingredient> ingredient;

    const FoodType foodtype = FoodType::Salad;

    bool done = false;

    const std::set<Option> availableOption = {Option::None, Option::Large, Option::AddOnions, Option::LessSalt, Option::NoSalt};
    Option option = Option::None;

public:
    Salad(std::vector<Ingredient> ingredient);

    std::vector<Ingredient> GetIngredient() override;
    FoodType GetFoodType() override;
    bool IsDone() override;

    void Prepare() override;

    void AddOption(Option option) override;
    Option GetOption() override;
};

#endif
