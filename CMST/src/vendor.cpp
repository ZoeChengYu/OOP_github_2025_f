#include "vendor.hpp"
#include "service_score.hpp"

Vendor::Vendor(std::string name, Title title, std::string phone, int ext):Person(name,title,phone,ext){
}

void Vendor::SetServiceScore(ServiceScore score){
    this->score = score;
}

ServiceScore Vendor::GetServiceScore(){
    return score;
}

int Vendor::GetBonus() {
    if (GetTitle()==Title::EXTERN_SALES) {
        if (Getcount()<=10&&Getcount()>0) {
            return GettotalSales()*0.1;
        }else if (Getcount()<=20) {
            return GettotalSales()*0.15;
        }else if (Getcount()>20) {
            return GettotalSales()*0.2;
        }else {
            return 0;
        }
    }else if (GetTitle()==Title::IT_SUPPORT_ENGINEER) {
        return 0;
    }else if (GetServiceScore()==ServiceScore::A) {
        return 26300;
    }else if (GetServiceScore()==ServiceScore::B) {
        return 14900;
    }else if (GetServiceScore()==ServiceScore::C) {
        return 7900;
    }else if (GetServiceScore()==ServiceScore::D) {
        return 3000;
    }else {
        return 0;
    }
}

int Vendor::vb() {
    return 0;
}
