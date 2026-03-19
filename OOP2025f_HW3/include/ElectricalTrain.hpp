#ifndef ELECTRICAL_TRAIN_HPP
#define ELECTRICAL_TRAIN_HPP

#include "Train.hpp"

class ElectricalTrain : public Train{
private:
    int powerLimit=0;
    int power=0;
    int seatLimit=0;
    int seat=0;
public:
    ElectricalTrain(int powerLimit,int seatLimit,TrainType type,int trainNumber,int speedLimit);
    int GetPowerLimit();
    int GetSeatLimit();
    void SetPowerLimit(int powerLimit);
    int GetPower();
    int GetSeat();
    void SetSeat();
    void Charge(int hour);

    void PowerUp();
    void SpeedUp();
    void SpeedDown();
};

#endif