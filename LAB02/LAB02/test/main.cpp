#include "Manager.hpp"
#include "Burger.hpp"
#include "Drink.hpp"
#include "SideDish.hpp"
#include "Salad.hpp"
#include "ToString.hpp"
#include "Validator.hpp"

void TaskOne(){
    std::vector<Ingredient> ingredientBurger = {Ingredient::Bread, Ingredient::Cheese, Ingredient::Lettuce};
    std::vector<Ingredient> ingredientSideDish = {Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientDrink = {Ingredient::CaramelMilkTea};
    std::vector<Ingredient> ingredientSalad = {Ingredient::Bread, Ingredient::Lettuce, Ingredient::Cheese};

    std::shared_ptr<Burger> burger = std::make_shared<Burger>(ingredientBurger);
    std::shared_ptr<SideDish> sideDish = std::make_shared<SideDish>(ingredientSideDish);
    std::shared_ptr<Drink> drink = std::make_shared<Drink>(ingredientDrink);
    std::shared_ptr<Salad> salad = std::make_shared<Salad>(ingredientSalad);

    Manager manager;
    manager.SetFood({burger, sideDish, drink, salad});
    manager.MakeFood();

    Validator valid;
    valid.Validate(manager.GetFood());
}

void TaskTwo(){
    std::vector<Ingredient> ingredientBurger = {Ingredient::Bread, Ingredient::CaramelMilkTea, Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientSideDish = {Ingredient::Bread, Ingredient::Cheese, Ingredient::Lettuce, Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientDrink = {Ingredient::Cheese};
    std::vector<Ingredient> ingredientSalad = {Ingredient::Lettuce, Ingredient::Cola};

    try {
        std::shared_ptr<Burger> burger = std::make_shared<Burger>(ingredientBurger);
    } catch (const std::exception& e){
        std::cerr << "Wrong Ingredient for hurger" << std::endl;
    }

    try {
        std::shared_ptr<SideDish> sideDish = std::make_shared<SideDish>(ingredientSideDish);
    } catch (const std::exception& e){
        std::cerr << "Wrong Ingredient for Side Dish" << std::endl;
    }

    try {
        std::shared_ptr<Drink> drink = std::make_shared<Drink>(ingredientDrink);
    } catch (const std::exception& e){
        std::cerr << "Wrong Ingredient for Drink" << std::endl;
    }

    try {
        std::shared_ptr<Salad> salad = std::make_shared<Salad>(ingredientSalad);
    } catch (const std::exception& e){
        std::cerr << "Wrong Ingredient for Salad" << std::endl;
    }
}

void TaskThree(){
    std::vector<Ingredient> ingredientBurger = {Ingredient::Bread, Ingredient::Cheese, Ingredient::Lettuce};
    std::vector<Ingredient> ingredientSideDish = {Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientDrink = {Ingredient::CaramelMilkTea};
    std::vector<Ingredient> ingredientSalad = {Ingredient::Lettuce, Ingredient::Cheese};

    std::shared_ptr<Burger> burger = std::make_shared<Burger>(ingredientBurger);
    std::shared_ptr<SideDish> sideDish = std::make_shared<SideDish>(ingredientSideDish);
    std::shared_ptr<Drink> drink = std::make_shared<Drink>(ingredientDrink);
    std::shared_ptr<Salad> salad = std::make_shared<Salad>(ingredientSalad);

    Manager manager;
    manager.SetFood({burger, sideDish, drink, salad});
    manager.MakeFood();

    try {
        manager.MakeFood();
    } catch (const std::exception& e){
        std::cerr << "Wrong for double cook/prepared!" << std::endl;
    }
}

void TaskFour(){
    std::vector<Ingredient> ingredientBurger = {Ingredient::Bread, Ingredient::Cheese, Ingredient::Lettuce};
    std::vector<Ingredient> ingredientSideDish = {Ingredient::FrenchFries};
    std::vector<Ingredient> ingredientDrink = {Ingredient::BlackTea};
    std::vector<Ingredient> ingredientSalad = {Ingredient::Lettuce, Ingredient::Cheese};

    Option optionBurger = Option::LessSalt;
    Option optionSideDish = Option::NoIce;
    Option optionDrink = Option::AddOnions;
    Option optionSalad = Option::NoIce;

    std::shared_ptr<Burger> burger = std::make_shared<Burger>(ingredientBurger);
    std::shared_ptr<SideDish> sideDish = std::make_shared<SideDish>(ingredientSideDish);
    std::shared_ptr<Drink> drink = std::make_shared<Drink>(ingredientDrink);
    std::shared_ptr<Salad> salad = std::make_shared<Salad>(ingredientSalad);

    try {
        burger->AddOption(optionBurger);
    } catch (const std::exception& e){
        std::cerr << "Wrong option for burger!" << std::endl;
    }

    try {
        sideDish->AddOption(optionSideDish);
    } catch (const std::exception& e){
        std::cerr << "Wrong option for side dish!" << std::endl;
    }

    try {
        drink->AddOption(optionDrink);
    } catch (const std::exception& e){
        std::cerr << "Wrong option for drink!" << std::endl;
    }

    try {
        salad->AddOption(optionSalad);
    } catch (const std::exception& e){
        std::cerr << "Wrong option for salad!" << std::endl;
    }
}

int main() {
    std::cout << "Task One:" << std::endl;
    TaskOne();
    std::cout << "Task Two:" << std::endl;
    TaskTwo();
    std::cout << "Task Three:" << std::endl;
    TaskThree();
    std::cout << "Task Four:" << std::endl;
    TaskFour();
    return 0;
}