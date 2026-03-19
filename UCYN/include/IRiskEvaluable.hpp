#ifndef IRISK_EVALUABLE_HPP
#define IRISK_EVALUABLE_HPP

class IRiskEvaluable{
    int Lv;
public:
    virtual int GetRiskLevel() = 0;
};

#endif