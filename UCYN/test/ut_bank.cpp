#include <gtest/gtest.h>
#include "PersonalAccount.hpp"
#include "BusinessAccount.hpp"
#include "TrustAccount.hpp"
#include "CreditCardProduct.hpp"
#include "FixedDepositProduct.hpp"
#include "InsuranceProduct.hpp"
#include "MutualFundProduct.hpp"
#include "Bank.hpp"

// Test fixture for Building tests to avoid repeating setup code
class BankTest : public ::testing::Test {
protected:
    std::unique_ptr<Bank> bank;
    std::shared_ptr<PersonalAccount> pa,pa2;
    std::shared_ptr<BusinessAccount> ba,ba2;
    std::shared_ptr<TrustAccount> ta;
    std::shared_ptr<InsuranceProduct> ip;
    std::shared_ptr<MutualFundProduct> mfp;
    std::shared_ptr<CreditCardProduct> ccp;
    std::shared_ptr<FixedDepositProduct> fdp;

    void SetUp() override {
        bank = std::make_unique<Bank>(10000, 0.05);
        pa = std::make_unique<PersonalAccount>(1000, "Wang-Shih-Fu");
        ba = std::make_unique<BusinessAccount>(10000, "NTUT");
        pa2 = std::make_unique<PersonalAccount>(1000, "Lai Yin Jo");
        ba2 = std::make_unique<BusinessAccount>(10000, "IS1AB");
        ta = std::make_unique<TrustAccount>(10000, "NTUT-CSIE", "IS1AB");
        ip = std::make_unique<InsuranceProduct>("Yee-Wai", 0.05, 1000, 3);
        mfp = std::make_unique<MutualFundProduct>("Chang Yi-Chang", 0.05, 10000, 5);
        ccp = std::make_unique<CreditCardProduct>("Caveira", 0.05, 1000);
        fdp = std::make_unique<FixedDepositProduct>("2026 Happy New Year", 0.05, 300000);
    }
};

TEST_F(BankTest, BankException) {
    EXPECT_THROW(Bank bk(-10000, 0.05), std::invalid_argument);
}
TEST_F(BankTest, BankExceptionTwo) {
    EXPECT_THROW(Bank bk(10000, -0.05), std::invalid_argument);
}

TEST_F(BankTest, GetBasicBankInfo) {
    EXPECT_EQ(bank->GetRate(), 0.05);
    EXPECT_EQ(bank->GetCapital(), 10000);
}

TEST_F(BankTest, BankSetterException) {
    EXPECT_THROW(bank->SetRate(-0.05), std::invalid_argument);
}
TEST_F(BankTest, BankSetterExceptionTwo) {
    EXPECT_THROW(bank->AddCapital(-1555), std::invalid_argument);
}

TEST_F(BankTest, BankAddAccount) {
    bank->AddAccount(pa);
    bank->AddAccount(pa2);

    auto tmp = bank->FindAccountByName("Wang-Shih-Fu");

    EXPECT_EQ(tmp->GetType(), AccountType::PersonalAccount);
    EXPECT_EQ(tmp->GetOwner(), "Wang-Shih-Fu");
}

TEST_F(BankTest, BankAddAccountTwo) {
    bank->AddAccount(ba);
    bank->AddAccount(ba2);

    auto tmp = bank->FindAccountByName("IS1AB");

    EXPECT_EQ(tmp->GetType(), AccountType::BusinessAccount);
    EXPECT_EQ(tmp->GetOwner(), "IS1AB");
}

TEST_F(BankTest, BankSearchAccount) {
    bank->AddAccount(pa);
    bank->AddAccount(pa2);
    bank->AddAccount(ba);
    bank->AddAccount(ba2);
    auto tmp = bank->FindAccountByType(AccountType::BusinessAccount);

    EXPECT_EQ(tmp.size(), 2);
    EXPECT_EQ(tmp[0]->GetType(), AccountType::BusinessAccount);
    EXPECT_EQ(tmp[0]->GetOwner(), "NTUT");
    EXPECT_EQ(tmp[1]->GetType(), AccountType::BusinessAccount);
    EXPECT_EQ(tmp[1]->GetOwner(), "IS1AB");
}

TEST_F(BankTest, BankSearchSpecficAccount) {
    bank->AddAccount(pa);
    bank->AddAccount(pa2);
    bank->AddAccount(ba);
    bank->AddAccount(ba2);
    auto tmp = bank->FindAccountByName("IS1AB");

    EXPECT_THROW(bank->FindAccountByName("GAY"), std::invalid_argument);
    EXPECT_EQ(tmp->GetType(), AccountType::BusinessAccount);
    EXPECT_EQ(tmp->GetOwner(), "IS1AB");
}

TEST_F(BankTest, BankTransferSomeFee) {
    bank->AddAccount(pa);
    bank->AddAccount(pa2);
    bank->AddAccount(ba);
    bank->AddAccount(ba2);

    bank->TransferByName("IS1AB", "Wang-Shih-Fu", 100);

    EXPECT_EQ(pa->GetBalance(), 1100);
    EXPECT_EQ(ba2->GetBalance(),9900);
}

TEST_F(BankTest, BankTransferSomeFeeException) {
    bank->AddAccount(pa);
    bank->AddAccount(pa2);
    bank->AddAccount(ba);
    bank->AddAccount(ba2);

    EXPECT_THROW(bank->TransferByName("IS1AB", "Wang-Shih-Fu", -100), std::invalid_argument);
    EXPECT_THROW(bank->TransferByName("Wang-Shih-Fu", "IS1AB", 100), std::invalid_argument);
}

TEST_F(BankTest, BankTransferSomeFeeForTrustAccount) {
    bank->AddAccount(pa);
    bank->AddAccount(pa2);
    bank->AddAccount(ba);
    bank->AddAccount(ba2);
    bank->AddAccount(ta);

    bank->TransferByName("NTUT-CSIE", "IS1AB", 100);

    EXPECT_EQ(ba2->GetBalance(), 10100);
    EXPECT_EQ(ta->GetBalance(),9900);
}

TEST_F(BankTest, BankTransferSomeFeeForTrustAccountException) {
    bank->AddAccount(pa);
    bank->AddAccount(pa2);
    bank->AddAccount(ta);

    EXPECT_THROW(bank->TransferByName("NTUT-CSIE", "IS1AB", 100), std::invalid_argument);
}

TEST_F(BankTest, BankGetProduct) {
    bank->AddProduct(ip);
    bank->AddProduct(mfp);
    bank->AddProduct(ccp);
    bank->AddProduct(fdp);

    auto tmp = bank->FindProductsByType(ProductType::FixedDeposit);

    EXPECT_EQ(tmp[0]->GetName(), "2026 Happy New Year");
}

TEST_F(BankTest, BankFindProductByName) {
    bank->AddProduct(ip);
    bank->AddProduct(mfp);
    bank->AddProduct(ccp);
    bank->AddProduct(fdp);

    auto tmp = bank->FindProductByName("Caveira");

    EXPECT_EQ(tmp->GetProductType(), ProductType::CreditCard);
}

TEST_F(BankTest, BankFindProductByNameException) {
    bank->AddProduct(ip);
    bank->AddProduct(mfp);
    bank->AddProduct(ccp);
    bank->AddProduct(fdp);

    EXPECT_THROW(bank->FindProductByName(""), std::invalid_argument);
}

TEST_F(BankTest, BankCountRevenue) {
    bank->AddProduct(ip);
    bank->AddProduct(mfp);
    bank->AddProduct(ccp);
    bank->AddProduct(fdp);

    auto tmp = bank->EstimateTotalRevenue(1);

    EXPECT_EQ(tmp, 11600);
}

TEST_F(BankTest, BankCountRisk) {
    bank->AddProduct(ip);
    bank->AddProduct(mfp);
    bank->AddProduct(ccp);
    bank->AddProduct(fdp);

    auto tmp = bank->EstimateRiskCount();

    EXPECT_EQ(tmp, 2);
}

TEST_F(BankTest, MakeCreditCardProduct) {
    bank->MakeCreditCardProduct("Huang Kuo Cheng", 1000);

    auto tmp = bank->MakeCreditCardProduct("Huang Kuo Cheng", 1000);

    EXPECT_EQ(tmp->GetProductType(), ProductType::CreditCard);
}

TEST_F(BankTest, MakeCreditCardProductException) {
    EXPECT_THROW(bank->MakeCreditCardProduct("Huang Kuo Cheng", -1000), std::invalid_argument);
}

TEST_F(BankTest, MakeFixedDepositProduct) {
    bank->AddAccount(pa);
    bank->FindAccountByName("Wang-Shih-Fu")->Deposit(19000);
    bank->MakeFixedDepositProduct("Wang-Shih-Fu", 10000);

    auto tmp = bank->MakeFixedDepositProduct("Wang-Shih-Fu", 10000);

    EXPECT_EQ(tmp->GetProductType(), ProductType::FixedDeposit);
    EXPECT_EQ(tmp->GetName(), "Wang-Shih-Fu");
}

TEST_F(BankTest, MakeFixedDepositProductException) {
    EXPECT_THROW(bank->MakeFixedDepositProduct("Wang-Shih-Fu", 10000), std::invalid_argument);
}

TEST_F(BankTest, MakeInsuranceProduct) {
    auto tmp = bank->MakeInsuranceProduct("Liu Chien Hung", 10000, 0);

    EXPECT_EQ(tmp->GetProductType(), ProductType::Insurance);
    EXPECT_EQ(tmp->GetName(), "Liu Chien Hung");
}

TEST_F(BankTest, MakeInsuranceProductException) {
    EXPECT_THROW(bank->MakeInsuranceProduct("Liu Chien Hung", -10000, 0), std::invalid_argument);
    EXPECT_THROW(bank->MakeInsuranceProduct("Liu Chien Hung", 10000, -1), std::invalid_argument);
}

TEST_F(BankTest, MakeMutualFundProduct) {
    auto tmp = bank->MakeMutualFundProduct("0050", 10000, 5);

    EXPECT_EQ(tmp->GetProductType(), ProductType::MutualFund);
    EXPECT_EQ(tmp->GetName(), "0050");
}

TEST_F(BankTest, MakeMutualFundProductException) {
    EXPECT_THROW(bank->MakeMutualFundProduct("Liu Chien Hung", -10000, 0), std::invalid_argument);
    EXPECT_THROW(bank->MakeMutualFundProduct("Liu Chien Hung", 10000, -1), std::invalid_argument);
}

TEST_F(BankTest, MakeProductBeforAndAfterRate) {
    auto tmp = std::dynamic_pointer_cast<MutualFundProduct>(bank->MakeMutualFundProduct("0056", 10000, 5));
    bank->SetRate(0.1);
    auto tmp2 = std::dynamic_pointer_cast<MutualFundProduct>(bank->MakeMutualFundProduct("0056", 10000, 5));

    EXPECT_EQ(tmp->EstimateRevenue(1), 10500);
    EXPECT_EQ(tmp2->EstimateRevenue(1), 11000);
}