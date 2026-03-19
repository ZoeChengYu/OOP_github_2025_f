#ifndef TICKET_HPP
#define TICKET_HPP

#include "Train.hpp"
#include <string>

class Ticket{
private:
    std::string dest;
    std::string src;
    int trainNumber=0;
protected:
    int price=0;
    int range=0;
    TrainType type;
public:
    Ticket(std::string dest,std::string src,int range,int trainNumber,TrainType type);
    std::string GetDest();
    std::string GetSrc();
    int GetRange();
    int GetPrice();
    int GetTrainNumber();
    TrainType GetTrainType();

    virtual void CalculateTicketPrice();
};

#endif