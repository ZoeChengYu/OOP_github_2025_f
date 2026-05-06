#include "Burger.hpp"

Burger::Burger(std::vector<Ingredient> ingredient) {
    for (const Ingredient& ingre : ingredient) {
        if (this->availableIngredient.find(ingre) == this->availableIngredient.end()) {
            throw std::invalid_argument("Invalid ingredient");
        }
    }
    this->ingredient = std::move(ingredient);
}

std::vector<Ingredient> Burger::GetIngredient() {
    return this->ingredient;
}

FoodType Burger::GetFoodType() {
    return this->foodtype;
}

bool Burger::IsDone() {
    return this->done;
}

void Burger::Cook() {
    if (this->ingredient.empty())
        throw std::invalid_argument("Can not cook without ingredient");
    if (this->IsDone())
        throw std::invalid_argument("Cook already done");
    this->ingredient = {};
    this->option = Option::None;
    this->done = true;
}

void Burger::AddOption(Option option) {
    if (this->availableOption.find(option) == this->availableOption.end())
        throw std::invalid_argument("Invalid option");
    if (this->IsDone())
        throw std::invalid_argument("Cook already done");
    this->option = option;
}

Option Burger::GetOption() {
    return this->option;
}
