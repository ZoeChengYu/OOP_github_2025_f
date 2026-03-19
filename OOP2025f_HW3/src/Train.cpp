#include "Train.hpp"

Train::Train(TrainType type,int trainNumber,int speedLimit) {
    this->type = type;
    this->speedLimit = speedLimit;
    this->trainNumber = trainNumber;
}
Train::~Train() {}
TrainType Train::GetType() {
    return type;
}
int Train::GetTrainNumber() {
    return trainNumber;
}
int Train::GetSpeedLimit() {
    return speedLimit;
}

int Train::GetSpeed() {
    return speed;
}
bool Train::IsOpen() {
    return open;
}
void Train::PowerUp() {
    open = true;
}
void Train::PowerDown() {
    open = false;
}