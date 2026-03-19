#include <gtest/gtest.h>
#include "PersonalAccount.hpp"
#include "BusinessAccount.hpp"
#include "TrustAccount.hpp"

TEST(TrustAccountTest, GetAccountBasicInfo) {
    TrustAccount ta(1000000, "TSMC", "MTK");

    EXPECT_EQ(ta.GetType(), AccountType::TrustAccount);
    EXPECT_EQ(ta.GetOwner(), "TSMC");
    EXPECT_EQ(ta.GetBeneficiary(), "MTK");
    EXPECT_EQ(ta.GetBalance(), 1000000);
}

TEST(TrustAccountTest, WithDrawThrowException) {
    TrustAccount ta(1000000, "TSMC", "MTK");

    EXPECT_THROW(ta.Withdraw(-100), std::invalid_argument);
    EXPECT_THROW(ta.Withdraw(0), std::invalid_argument);
    EXPECT_THROW(ta.Withdraw(100), std::invalid_argument);
}
TEST(TrustAccountTest, DepositThrowException) {
    TrustAccount ta(1000000, "TSMC", "MTK");

    EXPECT_THROW(ta.Deposit(-100), std::invalid_argument);
    EXPECT_THROW(ta.Deposit(0), std::invalid_argument);
    EXPECT_THROW(ta.Deposit(100), std::invalid_argument);
}

TEST(TrustAccountTest, AccountCanTransfer) {
    std::shared_ptr<BusinessAccount> pa = std::make_shared<BusinessAccount>(100000, "MTK");
    TrustAccount ta(100000, "TSMC", "MTK");

    ta.Transfer(pa, 10000);

    EXPECT_EQ(pa->GetBalance(), 110000);
    EXPECT_EQ(ta.GetBalance(), 90000);
}

TEST(TrustAccountTest, TransferThrowExceptionTwo) {
    std::shared_ptr<BusinessAccount> pa = std::make_shared<BusinessAccount>(100000, "MTK");
    std::shared_ptr<BusinessAccount> pa2 = std::make_shared<BusinessAccount>(100000, "1223");
    TrustAccount ta(100000, "TSMC", "MTK");

    EXPECT_THROW(ta.Transfer(pa2, 10000), std::invalid_argument);
    EXPECT_THROW(ta.Transfer(pa, -10000), std::invalid_argument);
}
