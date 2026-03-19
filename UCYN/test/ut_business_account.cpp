#include <gtest/gtest.h>
#include "PersonalAccount.hpp"
#include "BusinessAccount.hpp"

TEST(BusinessAccountTest, GetAccountBasicInfo) {
    BusinessAccount ba(1000000, "TSMC");

    EXPECT_EQ(ba.GetType(), AccountType::BusinessAccount);
    EXPECT_EQ(ba.GetOwner(), "TSMC");
    EXPECT_EQ(ba.GetBalance(), 1000000);
}

TEST(BusinessAccountTest, AccountCanWithDeposit) {
    BusinessAccount pa(10000, "MTK");

    pa.Deposit(100);

    EXPECT_EQ(pa.GetBalance(), 10100);
}

TEST(BusinessAccountTest, AccountCanWithDraw) {
    BusinessAccount pa(1000, "Guo-Ti-Min");

    auto money = pa.Withdraw(100);

    EXPECT_EQ(money, 100);
    EXPECT_EQ(pa.GetBalance(), 900);
}

TEST(BusinessAccountTest, AccountCanTransfer) {
    std::shared_ptr<BusinessAccount> pa = std::make_shared<BusinessAccount>(1000, "Wang-Shih-Fu");
    std::shared_ptr<PersonalAccount> pa2 = std::make_shared<PersonalAccount>(1000, "Yang-Shih-Shuan");

    pa->Transfer(pa2, 100);

    EXPECT_EQ(pa->GetBalance(), 900);
    EXPECT_EQ(pa2->GetBalance(), 1100);
}

TEST(BusinessAccountTest, AccountCanTransferTwo) {
    std::shared_ptr<BusinessAccount> pa = std::make_shared<BusinessAccount>(1000, "Wang-Shih-Fu");
    std::shared_ptr<BusinessAccount> pa2 = std::make_shared<BusinessAccount>(1000, "Yang-Shih-Shuan");

    pa->Transfer(pa2, 100);

    EXPECT_EQ(pa->GetBalance(), 900);
    EXPECT_EQ(pa2->GetBalance(), 1100);
}

TEST(BusinessAccountTest, ConstructorThrowException) {
    EXPECT_THROW(BusinessAccount(-1000, "Wang-Shih-Fu"), std::invalid_argument);
}

TEST(BusinessAccountTest, WithDrawThrowException) {
    BusinessAccount pa(1000, "Guo-Ti-Min");

    EXPECT_THROW(pa.Withdraw(-100), std::invalid_argument);
}

TEST(BusinessAccountTest, WithDrawThrowExceptionTwo) {
    BusinessAccount pa(1000, "Guo-Ti-Min");

    EXPECT_THROW(pa.Withdraw(1100), std::invalid_argument);
}


TEST(BusinessAccountTest, TransferThrowExceptionTwo) {
    std::shared_ptr<PersonalAccount> pa = std::make_shared<PersonalAccount>(1000, "Wang-Shih-Fu");
    std::shared_ptr<BusinessAccount> pa2 = std::make_shared<BusinessAccount>(1000, "Yang-Shih-Shuan");

    EXPECT_THROW(pa2->Transfer(pa, -100), std::invalid_argument);
    EXPECT_THROW(pa2->Transfer(pa, 1100), std::invalid_argument);
}

TEST(BusinessAccountTest, DepositThrowException) {
    BusinessAccount pa(1000, "Guo-Ti-Min");

    EXPECT_THROW(pa.Deposit(-100), std::invalid_argument);
}