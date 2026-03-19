#include "CargoPaper.hpp"

 CargoPaper::CargoPaper(std::string dest, std::string src, int range, int volume,
                       CargoType cargoType):Ticket(dest,src,range,0,TrainType::Cargo) ,volume(volume),cargoType(cargoType){
 }

int CargoPaper::GetVolume() {
    return this->volume;
}

CargoType CargoPaper::GetCargoType() {
    return this->cargoType;
}

void CargoPaper::CalculateTicketPrice() {
     if (cargoType==CargoType::Food || cargoType==CargoType::Drink) {
         price=((4*GetRange()+75*std::floor(GetVolume()/100))*1.1);
     }else if (cargoType==CargoType::Electronics || cargoType==CargoType::Furniture) {
         price=(4*GetRange()+75*std::floor(GetVolume()/100))*1.15;
     }else if (cargoType==CargoType::Vehicle) {
         price=(4*GetRange()+75*std::floor(GetVolume()))*1.2;
     }
}

