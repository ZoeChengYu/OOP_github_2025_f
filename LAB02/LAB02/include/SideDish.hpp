#ifndef SIDE_DISH_HPP
#define SIDE_DISH_HPP

#include <set>
#include <memory>
#include <stdexcept>

#include "Ingredient.hpp"

#include "IFood.hpp"
#include "ICookable.hpp"
#include "ICustomizable.hpp"

class SideDish : public IFood, public ICookable, public ICustomizable {
private:
    const std::set<Ingredient> availableIngredient = {Ingredient::FrenchFries, Ingredient::Nuggets, Ingredient::HashBrowns};
    std::vector<Ingredient> ingredient;

    const FoodType foodtype = FoodType::SideDish;

    bool done = false;

    const std::set<Option> availableOption = {Option::None, Option::Large, Option::LessSalt, Option::NoSalt};
    Option option = Option::None;

public:
    SideDish(std::vector<Ingredient> ingredient);

    std::vector<Ingredient> GetIngredient() override;
    FoodType GetFoodType() override;
    bool IsDone() override;

    void Cook() override;

    void AddOption(Option option) override;
    Option GetOption() override;
};


#endif
