#ifndef CARGO_TRAIN_HPP
#define CARGO_TRAIN_HPP

#include "Train.hpp"

class CargoTrain : public Train{
private:
    int fuelLimit=0;
    int fuel=0;
    int cargoLimit=0;
    int cargo=0;
public:
    CargoTrain(int fuelLimit,int cargoLimit,TrainType type,int trainNumber,int speedLimit);
    int GetFuelLimit();
    int GetCargoLimit();
    void SetFuelLimit(int fuelLimit);
    int GetFuel();
    int GetCargo();
    void AddCargo(int cargo);
    void AddFuel(int fuel);

    virtual void PowerUp() override;
    virtual void SpeedUp() override;
    virtual void SpeedDown() override;
};

#endif