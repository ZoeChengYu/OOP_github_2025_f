#include <gtest/gtest.h>
#include "MutualFundProduct.hpp"

TEST(MutualFundProductTest, GetProductBasicInfo) {
    MutualFundProduct mfp("Chang Yi-Chang", 0.05, 10000, 5);

    EXPECT_EQ(mfp.GetProductType(), ProductType::MutualFund);
    EXPECT_EQ(mfp.GetName(), "Chang Yi-Chang");
    EXPECT_EQ(mfp.GetMonthlyFee(), 10000);
    EXPECT_EQ(mfp.GetRiskLevel(), 5);
    EXPECT_EQ(mfp.EstimateRevenue(1), 10500);
    EXPECT_EQ(mfp.EstimateRevenue(2), 21000);
}
TEST(MutualFundProductTest, GetProductBasicInfoThrowException) {
    EXPECT_THROW(MutualFundProduct mfp("Chang Yi-Chang", -0.05, 10000, 5), std::invalid_argument);
}
TEST(MutualFundProductTest, GetProductBasicInfoThrowExceptionTwo) {
    EXPECT_THROW(MutualFundProduct mfp("Chang Yi-Chang", 0.05, -10000, 5), std::invalid_argument);
}
TEST(MutualFundProductTest, GetProductBasicInfoThrowExceptionThree) {
    EXPECT_THROW(MutualFundProduct mfp("Chang Yi-Chang", 0.05, 10000, -5), std::invalid_argument);
}

TEST(MutualFundProductTest, GetProductBasicInfoThrowExceptionFour) {
    MutualFundProduct mfp("Chang Yi-Chang", 0.05, 10000, 5);

    EXPECT_THROW(mfp.EstimateRevenue(-1), std::invalid_argument);
}