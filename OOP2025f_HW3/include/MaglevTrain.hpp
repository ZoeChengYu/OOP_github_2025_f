#ifndef MAGLEV_TRAIN_HPP
#define MAGLEV_TRAIN_HPP

#include "Train.hpp"

class MaglevTrain: public Train{
private:
    int powerLimit=0;
    int power=0;
    int seatLimit=0;
    int seat=0;
public:
    MaglevTrain(int powerLimit,int seatLimit,TrainType type,int trainNumber,int speedLimit);
    int GetPowerLimit();
    int GetSeatLimit();
    void SetPowerLimit(int powerLimit);
    int GetPower();
    int GetSeat();
    void SetSeat();
    void Charge(int hour);

    virtual void PowerUp() override;
    virtual void SpeedUp() override;
    virtual void SpeedDown() override;
};

#endif