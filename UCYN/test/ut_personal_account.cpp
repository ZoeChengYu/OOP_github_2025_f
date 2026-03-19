#include <gtest/gtest.h>
#include "PersonalAccount.hpp"
#include "BusinessAccount.hpp"

TEST(PersonalAccountTest, GetAccountBasicInfo) {
    PersonalAccount pa(1000, "Guo-Ti-Min");

    EXPECT_EQ(pa.GetType(), AccountType::PersonalAccount);
    EXPECT_EQ(pa.GetOwner(), "Guo-Ti-Min");
    EXPECT_EQ(pa.GetBalance(), 1000);
}

TEST(PersonalAccountTest, AccountCanWithDeposit) {
    PersonalAccount pa( 1000, "Guo-Ti-Min");

    pa.Deposit(100);

    EXPECT_EQ(pa.GetBalance(), 1100);
}

TEST(PersonalAccountTest, AccountCanWithDraw) {
    PersonalAccount pa(1000, "Guo-Ti-Min");

    auto money = pa.Withdraw(100);

    EXPECT_EQ(money, 100);
    EXPECT_EQ(pa.GetBalance(), 900);
}

TEST(PersonalAccountTest, AccountCanTransfer) {
    std::shared_ptr<PersonalAccount> pa = std::make_shared<PersonalAccount>(1000, "Wang-Shih-Fu");
    std::shared_ptr<PersonalAccount> pa2 = std::make_shared<PersonalAccount>(1000, "Yang-Shih-Shuan");

    pa->Transfer(pa2, 100);

    EXPECT_EQ(pa->GetBalance(), 900);
    EXPECT_EQ(pa2->GetBalance(), 1100);
}

TEST(PersonalAccountTest, ConstructorThrowException) {
    EXPECT_THROW(PersonalAccount(-1000, "Wang-Shih-Fu"), std::invalid_argument);
}

TEST(PersonalAccountTest, WithDrawThrowException) {
    PersonalAccount pa(1000, "Guo-Ti-Min");

    EXPECT_THROW(pa.Withdraw(-100), std::invalid_argument);
}

TEST(PersonalAccountTest, WithDrawThrowExceptionTwo) {
    PersonalAccount pa(1000, "Guo-Ti-Min");

    EXPECT_THROW(pa.Withdraw(1100), std::invalid_argument);
}

TEST(PersonalAccountTest, TransferThrowException) {
    std::shared_ptr<PersonalAccount> pa = std::make_shared<PersonalAccount>(1000, "Wang-Shih-Fu");
    std::shared_ptr<BusinessAccount> ba2 = std::make_shared<BusinessAccount>(1000, "NTUT");

    EXPECT_THROW(pa->Transfer(ba2, 100), std::invalid_argument);
}
TEST(PersonalAccountTest, TransferThrowExceptionTwo) {
    std::shared_ptr<PersonalAccount> pa = std::make_shared<PersonalAccount>(1000, "Wang-Shih-Fu");
    std::shared_ptr<PersonalAccount> pa2 = std::make_shared<PersonalAccount>(1000, "Yang-Shih-Shuan");

    EXPECT_THROW(pa->Transfer(pa2, -100), std::invalid_argument);
    EXPECT_THROW(pa->Transfer(pa2, 1100), std::invalid_argument);
}

TEST(PersonalAccountTest, DepositThrowException) {
    PersonalAccount pa(1000, "Guo-Ti-Min");

    EXPECT_THROW(pa.Deposit(-100), std::invalid_argument);
}