#include <gtest/gtest.h>
#include "InsuranceProduct.hpp"

TEST(InsuranceProductTest, GetProductBasicInfo) {
    InsuranceProduct ip("Yee-Wai", 0.05, 1000, 3);

    EXPECT_EQ(ip.GetProductType(), ProductType::Insurance);
    EXPECT_EQ(ip.GetName(), "Yee-Wai");
    EXPECT_EQ(ip.GetMonthlyFee(), 1000);
    EXPECT_EQ(ip.EstimateRevenue(1), 1050);
    EXPECT_EQ(ip.EstimateRevenue(2), 2100);
    EXPECT_EQ(ip.GetRiskLevel(), 3);
    EXPECT_EQ(ip.GetRate(), 0.05);
}
TEST(InsuranceProductTest, GetProductBasicInfoThrowException) {
    EXPECT_THROW(InsuranceProduct ip("Yee-Wai", 0.05, -1000, 3), std::invalid_argument);
}
TEST(InsuranceProductTest, GetProductBasicInfoThrowExceptionTwo) {
    EXPECT_THROW(InsuranceProduct ip("Yee-Wai", 0.05, 1000, -3), std::invalid_argument);
}
TEST(InsuranceProductTest, GetProductBasicInfoThrowExceptionThree) {
    EXPECT_THROW(InsuranceProduct ip("Yee-Wai", -0.05, 1000, 3), std::invalid_argument);
}

TEST(InsuranceProductTest, GetProductBasicInfoThrowExceptionFour) {
    InsuranceProduct ip("Yee-Wai", 0.05, 1000, 3);

    EXPECT_THROW(ip.EstimateRevenue(-1), std::invalid_argument);
}
