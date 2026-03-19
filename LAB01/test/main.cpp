#include "Manager.hpp"
#include "Burger.hpp"
#include "Drink.hpp"
#include "Noodle.hpp"
#include "Salad.hpp"
#include "Soup.hpp"
#include "ToString.hpp"
#include "RandomFood.hpp"
#include "Validator.hpp"

int main() {
    RandomFood randomFood = RandomFood();
    Ingredient i1 = randomFood.Generate();
    i1.sweet.clear();
    i1.drinkBase.clear();
    std::shared_ptr<Burger> burger = std::make_shared<Burger>(i1);
    std::shared_ptr<Food> food = std::static_pointer_cast<Food>(burger);

    Manager manager = Manager({food});
    manager.CookAllFood();
    manager.CookAllFood();
    std::cout << std::flush;
    Validate(manager.GetFood());
}