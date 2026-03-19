#include <gtest/gtest.h>
#include "CreditCardProduct.hpp"

TEST(CreditCardProductTest, GetProductBasicInfo) {
    CreditCardProduct ccp("Chang Yi-Chang", 0.05, 1000);

    EXPECT_EQ(ccp.GetProductType(), ProductType::CreditCard);
    EXPECT_EQ(ccp.GetName(), "Chang Yi-Chang");
    EXPECT_EQ(ccp.GetMonthlyFee(), 1000);
    EXPECT_EQ(ccp.EstimateRevenue(1), 50);
    EXPECT_EQ(ccp.EstimateRevenue(2), 100);
}
TEST(CreditCardProductTest, GetProductBasicInfoThrowException) {
    EXPECT_THROW(CreditCardProduct ccp("Chang Yi-Chang", -0.05, 1000), std::invalid_argument);
}
TEST(CreditCardProductTest, GetProductBasicInfoThrowExceptionTwo) {
    EXPECT_THROW(CreditCardProduct ccp("Chang Yi-Chang", 0.05, -1000), std::invalid_argument);
}
TEST(CreditCardProductTest, GetProductBasicInfoThrowExceptionThree) {
    CreditCardProduct ccp("Chang Yi-Chang", 0.05, 1000);

    EXPECT_THROW(ccp.EstimateRevenue(-1), std::invalid_argument);
}
