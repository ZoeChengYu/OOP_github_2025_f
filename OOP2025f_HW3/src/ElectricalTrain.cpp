#include "ElectricalTrain.hpp"
#include<stdexcept>

 ElectricalTrain::ElectricalTrain(int powerLimit, int seatLimit, TrainType type,
                                 int trainNumber, int speedLimit): Train(type, trainNumber, speedLimit){
     this->powerLimit = powerLimit;
     this->seatLimit = seatLimit;
}
int ElectricalTrain::GetPowerLimit() {
    return this->powerLimit;
}

int ElectricalTrain::GetSeatLimit() {
     return this->seatLimit;
 }

int ElectricalTrain::GetPower() {
     return this->power;
 }

int ElectricalTrain::GetSeat() {
     return this->seat;
 }

void ElectricalTrain::SetPowerLimit(int powerLimit) {
     if (powerLimit <= 0 || powerLimit > 100) {
         throw std::invalid_argument("powerLimit must be between 1 and 100");
     }
     this->powerLimit = powerLimit;
 }

void ElectricalTrain::SetSeat() {
     if (seat >= seatLimit) {
         throw std::invalid_argument("we don't have enough seat");
     }else{
          seat++;
     }
 }

void ElectricalTrain::Charge(int hour) {
     if (power+18*hour >= powerLimit) {
         power=powerLimit;
     }else {
         power += 18*hour;
     }
 }

void ElectricalTrain::PowerUp() {
     open=true;
     power-=1;
 }

void ElectricalTrain::SpeedUp() {
     if (power>=3) {
         power-=3;
         speed=15+std::floor(speed/20.0)+speed;
         if (speed >= this -> GetSpeedLimit()) {
             speed=this -> GetSpeedLimit();
         }
     }else if (power<=0) {
         throw std::invalid_argument("power is empty");
     }
 }
void ElectricalTrain::SpeedDown() {
     if (power>0 && speed>0) {
         speed-=15;
         if (speed < 0) {
             speed=0;
         }
     }
 }

