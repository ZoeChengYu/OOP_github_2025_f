#include "Ticket.hpp"

 Ticket::Ticket(std::string dest, std::string src, int range, int trainNumber,
               TrainType type) {
     this->dest = dest;
     this->src = src;
     this->range = range;
     this->trainNumber = trainNumber;
     this->type = type;
}

std::string Ticket::GetDest() {
    return dest;
}

std::string Ticket::GetSrc() {
     return src;
 }
int Ticket::GetRange() {
     return range;
 }
int Ticket::GetPrice() {
     return price;
 }

int Ticket::GetTrainNumber() {
     return trainNumber;
 }

TrainType Ticket::GetTrainType() {
     return type;
 }
void Ticket::CalculateTicketPrice() {
     float RateOfType=1;
     int addtion=0;
     if (type==TrainType::Express) {
         RateOfType = 1.4;
         addtion = 25*std::floor(range/100);
     }else if (type==TrainType::Limited){
        RateOfType = 1.2;
     }

     price=2*range*RateOfType+addtion;
 }