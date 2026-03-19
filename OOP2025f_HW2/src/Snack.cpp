#include "Snack.hpp"

Snack::Snack(std::string snackName):name(snackName),amount(1) {}
    

Snack::Snack(std::string snackName, int snackAmount):name(snackName),amount(snackAmount){}

std::string Snack::getName() const{
    return this->name;
}

int Snack::getAmount() const{
    return this->amount;
};

void Snack::setAmount(int snackAmount){
    if(snackAmount >= 0){
        this->amount = snackAmount;
    }
}