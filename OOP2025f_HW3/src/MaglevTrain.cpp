#include "MaglevTrain.hpp"
#include<stdexcept>

 MaglevTrain::MaglevTrain(int powerLimit, int seatLimit, TrainType type,
                         int trainNumber, int speedLimit):Train(type,trainNumber,speedLimit) {
     this->powerLimit = powerLimit;
     this->seatLimit = seatLimit;
}

int MaglevTrain::GetPowerLimit() {
     return powerLimit;
 }
int MaglevTrain::GetSeatLimit() {
     return seatLimit;
 }
void MaglevTrain::SetPowerLimit(int powerLimit) {
     if (powerLimit <= 0 || powerLimit > 100) {
         throw std::invalid_argument("Invalid power limit");
     }
     this->powerLimit = powerLimit;
 }
int MaglevTrain::GetPower() {
     return power;
 }
int MaglevTrain::GetSeat() {
     return seat;
 }
void MaglevTrain::SetSeat(){
     if (seat >= seatLimit) {
         throw std::invalid_argument("Invalid seat");
     }else {
         seat++;
     }
 }
void MaglevTrain::Charge(int hour) {
     if (power+14*hour >= powerLimit) {
         power=powerLimit;
     }else {
         power += 14*hour;
     }
 }
void MaglevTrain::PowerUp() {
     open=true;
     power-=1;
 }
void MaglevTrain::SpeedUp() {
     if (power>=3) {
         power-=3;
         speed=30+std::floor(speed/15)+speed;
         if (speed >= this->GetSpeedLimit()) {
             speed=this->GetSpeedLimit();
         }
     }else if (power<=0) {
         throw std::invalid_argument("Power is empty");
     }
 }
void MaglevTrain::SpeedDown() {
     if (power>0&&speed>0) {
        speed-=30;
         if (speed < 0) {
             speed=0;
         }
     }
 }