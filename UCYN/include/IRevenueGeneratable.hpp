#ifndef IREVENUE_GENERATABLE_HPP
#define IREVENUE_GENERATABLE_HPP

class IRevenueGeneratable{
public:
    virtual int EstimateRevenue(int months) = 0;
};

#endif
