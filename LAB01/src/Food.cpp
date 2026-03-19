#include "Food.hpp"
 Food::Food(Ingredient ingredient) {
     this->ingredient=ingredient;
}

FoodType Food::GetFoodType() {
    return foodType;
}

Ingredient Food::GetIngredient() {
    return ingredient;
}

int Food::GetPrice() {
    return price;
}
void Food::CountFoodPrice() {
    int price = 0;
     for (Base base :this->ingredient.base) {
         price+=20;
     }
     for(Meat meat :this->ingredient.meat) {
         price+=15;
     }
     for(Veggie veggie :this->ingredient.veggie) {
         price+=10;
     }
     for (Seasoning seasoning:this->ingredient.seasoning) {
         price+=0;
     }
     for ()
}

