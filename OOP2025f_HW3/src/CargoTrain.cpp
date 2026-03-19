#include "CargoTrain.hpp"
#include <cmath>
 CargoTrain::CargoTrain(int fuelLimit, int cargoLimit, TrainType type,
                       int trainNumber, int speedLimit) :Train(type,trainNumber, speedLimit){
     this->fuelLimit = fuelLimit;
     this->cargoLimit = cargoLimit;
}

int CargoTrain::GetCargoLimit() {
    return cargoLimit;
}
int CargoTrain::GetFuelLimit() {
     return fuelLimit;
 }
void CargoTrain::SetFuelLimit(int fuelLimit) {
     if (fuelLimit <= 0|| fuelLimit > 1000) {
         throw std::invalid_argument("flelLimit must between 0 and 1000");
     }
     this->fuelLimit = fuelLimit;
 }
int CargoTrain::GetCargo() {
     return cargo;
 }
int CargoTrain::GetFuel() {
     return fuel;
 }
void CargoTrain::AddCargo(int cargo) {
     if (cargo+this->cargo>cargoLimit) {
         throw std::invalid_argument("");
     }
     this->cargo += cargo;
 }
void CargoTrain::AddFuel(int fuel) {
     if (fuel+this->fuel>fuelLimit) {
         fuel=fuelLimit;
     }
     this->fuel += fuel;
 }

void CargoTrain::PowerUp() {
     open=true;
     fuel-=5;
 }
void CargoTrain::SpeedUp() {
     if (fuel>=10) {
         double rate=std::floor(cargo*10.0/cargoLimit)/10.0;
         fuel -= 10;
         if (rate < 0.3) {
             speed=15+std::floor(speed/20)+speed;
         }else if (rate > 0.7) {
             speed=15+std::floor(speed/30)+speed;
         }else {
             speed=15+std::floor(speed/25)+speed;
         }
         if (speed>this->GetSpeedLimit()) {
             speed=this->GetSpeedLimit();
         }
     }else if (fuel<=0) {
         throw std::invalid_argument("you don't have enough fuel to do it");
     }
 }

void CargoTrain::SpeedDown() {
     if (fuel>0 && speed > 0) {
         speed -=15;
         if (speed < 0) {
             speed = 0;
         }
     }
 }
