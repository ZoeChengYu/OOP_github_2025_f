#include <gtest/gtest.h>
#include "FixedDepositProduct.hpp"

TEST(FixedDepositProductTest, GetProductBasicInfo) {
    FixedDepositProduct fdp("Chang Yi-Chang", 0.05, 300000);

    EXPECT_EQ(fdp.GetProductType(), ProductType::FixedDeposit);
    EXPECT_EQ(fdp.GetName(), "Chang Yi-Chang");
    EXPECT_EQ(fdp.GetMonthlyFee(), 26250);
}
TEST(FixedDepositProductTest, GetProductBasicInfoThrowException) {
    EXPECT_THROW(FixedDepositProduct fdp("Chang Yi-Chang", -0.05, 1000), std::invalid_argument);
}
TEST(FixedDepositProductTest, GetProductBasicInfoThrowExceptionTwo) {
    EXPECT_THROW(FixedDepositProduct fdp("Chang Yi-Chang", 0.05, -1000), std::invalid_argument);
}
