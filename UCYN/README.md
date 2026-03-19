# OOP2025[F] Final Exam

## 檔案架構

你的檔案架構必須至少符合以下的規格，才可以讓系統編譯你的專案。

```
.
├── CMakeLists.txt
├── files.cmake
├── include
│   ├── Account.hpp
│   ├── AccountType.hpp
│   ├── Bank.hpp
│   ├── BusinessAccount.hpp
│   ├── CreditCardProduct.hpp
│   ├── FixedDepositProduct.hpp
│   ├── IBankProduct.hpp
│   ├── InsuranceProduct.hpp
│   ├── IRevenueGeneratable.hpp
│   ├── IRiskEvaluable.hpp
│   ├── MutualFundProduct.hpp
│   ├── PersonalAccount.hpp
│   └── TrustAccount.hpp
├── src
│   ├── Account.cpp
│   ├── Bank.cpp
│   ├── BusinessAccount.cpp
│   ├── CreditCardProduct.cpp
│   ├── FixedDepositProduct.cpp
│   ├── InsuranceProduct.cpp
│   ├── MutualFundProduct.cpp
│   ├── PersonalAccount.cpp
│   └── TrustAccount.cpp
└── test
    ├── ut_bank.cpp
    ├── ut_business_account.cpp
    ├── ut_creditcard_product.cpp
    ├── ut_fixed_deposit_product.cpp
    ├── ut_insurance_product.cpp
    ├── ut_mutualfund_product.cpp
    ├── ut_personal_account.cpp
    └── ut_trust_account.cpp
```

## Description

> [!NOTE]  
> 您好，我叫 `Kesshoban3310`  
> 我並沒有建立銀行系統的經驗，現在還差一個工程師就可以滿足我的需求  
> 你現在幫過我，我承諾你會破台這份期末，並且成為銀行大股東，謝謝！  

> [!NOTE]  
> `Unified Composition & Yields Network (UCYN)` 是一間銀行   
> 由於最近想要拓展網路業務，希望你能夠設計一套銀行系統，請你根據需求完成題目。    
> 在詳細了解 `UCYN` 的需求後，你稍微歸類出以下物件：  

### 帳戶類別

| 帳戶分類 | 可否轉帳 | 可否提款 | 可否存款 |     備註      |
|:----:|:----:|:----:|:----:|:-----------:|
| 個人帳戶 |  V   |  V   |  V   |             |
| 商業帳戶 |  V   |  V   |  V   | 允許負數，但要小於限制 |
| 信託帳戶 |  V   |  X   |  X   |  只可轉入受益人帳戶  |

- 其中，可以帳戶可以轉帳的關係如下：

| 帳戶分類 | 個人帳戶 | 商業帳戶 | 商業帳戶 |
|:----:|:----:|:----:|:----:|
| 個人帳戶 |  V   |  X   |  X   |
| 商業帳戶 |  V   |  V   |  X   |
| 信託帳戶 |  V   |  V   |  X   |

- 左邊代表 `轉出` ， 上方代表 `轉入` 

### 商品類別

此外， `UCYN` 也提供許多商品提供服務給顧客，以下是商品的類別

| 商品分類  | 是否有額外收益 | 是否有風險 | 
|:-----:|:-------:|:-----:|
| 保險商品  |    V    |   V   |
| 基金商品  |    V    |   V   |
| 信用卡商品 |    V    |   X   |
| 定儲商品  |    X    |   X   |

所有商品須繼承 `IBankProduct` 介面

### 管理系統

- 管理系統在 `Bank.hpp` 中，會在目標三中告訴你 `Bank.hpp` 中要如何設計。

### 總欄

- 根據所有的物件僅列出該物件的 `public function` ，你可以自行新增 `member/function` 或對任意函數使用 `virtual` 。

## 目標一、設計所有的帳戶類別 (ut_test_1)

### 帳戶

- `class Account`
    - `Account(AccountType type, int balance, std::string owner)`
        - 函數類別：建構子
        - 第一個參數 `type` ： 帳戶類型
        - 第二個參數 `balance` ： 初始餘額
        - 第三個參數 `owner` ：擁有者
        - 當傳入的 `balance` 為負時，需拋出 `std::invalid_arguments` 例外
    - `AccountType GetType()`
        - 函數類別：Getter
        - 回傳：帳戶類型
    - `int GetBalance()`
        - 函數類別：Getter
        - 回傳：餘額
    - `std::string GetOwner()`
        - 函數類別：Getter
        - 回傳：擁有者
    - `void Deposit(int amount)`
        - 敘述：用於存入 `amount` 數量的資金
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
        - 可根據需求設定成虛擬函數
    - `int  Withdraw(int amount)`
        - 敘述：為純虛擬函數，會於各類型帳號描述行為
        - 注意：如果提領成功，需要回傳 `amount`
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
    - `void Transfer(std::shared_ptr<Account> dest, int amount)`
        - 敘述：為純虛擬函數，會於各類型帳號描述行為
        - `dest` 為目標帳戶，代表從我們這裡收到轉入金額的帳戶
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
- `class PersonalAccount` ( 繼承 `Account` )
    - `PersonalAccount(int balance, std::string owner)`
        - 函數類別：建構子
        - 第一個參數 `balance` ： 初始餘額
        - 第二個參數 `owner` ：擁有者
        - 當傳入的 `balance` 為負時，需拋出 `std::invalid_arguments` 例外
    - `int  Withdraw(int amount)`
        - 敘述：覆寫 `Account` 中的 `int Withdraw(int amount)`
        - 注意：如果提領成功，需要回傳 `amount`，並同時扣除 `amount` 數量的 `balance`
        - 提領時若 `amount` 超過帳戶內的 `balance` ， 拋出 `std::invalid_arguments` 例外
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
    - `void Transfer(std::shared_ptr<Account> dest, int amount)`
        - 敘述：覆寫 `Account` 中的 `void Transfer(std::shared_ptr<Account> dest, int amount)`
        - 行為：我們將 `amount` 轉入到 `dest` 這個帳戶，同時帳戶內要減少 `amount` 數量的錢
        - 只能轉給 `PersonalAccount`
        - 若 `amount` 超過帳戶內的 `balance` ， 拋出 `std::invalid_arguments` 例外
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
- `class BusinessAccount`
    - `BusinessAccount(int balance, std::string owner)`
        - 函數類別：建構子
        - 第一個參數 `balance` ： 初始餘額
        - 第二個參數 `owner` ：擁有者
        - 當傳入的 `balance` 為負時，需拋出 `std::invalid_arguments` 例外
    - `int Withdraw(int amount)`
        - 敘述：覆寫 `Account` 中的 `int Withdraw(int amount)`
        - 注意：如果提領成功，需要回傳 `amount`，並同時扣除 `amount` 數量的 `balance`
        - 提領時若 `amount` 超過帳戶內的 `balance` ， 拋出 `std::invalid_arguments` 例外
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
    - `void Transfer(std::shared_ptr<Account> dest, int amount)`
        - 敘述：覆寫 `Account` 中的 `void Transfer(std::shared_ptr<Account> dest, int amount)`
        - 行為：我們將 `amount` 轉入到 `dest` 這個帳戶，同時帳戶內要減少 `amount` 數量的錢
        - 可轉給任何帳戶
        - 若 `amount` 超過帳戶內的 `balance` ， 拋出 `std::invalid_arguments` 例外
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
- `class TrustAccount`
    - `TrustAccount(int balance, std::string owner, std::string beneficiary)`
        - 函數類別：建構子
        - 第一個參數 `balance` ： 初始餘額
        - 第二個參數 `owner` ：擁有者 (管理者)
        - 第三個參數 `beneficiary` ：受益人
        - 當傳入的 `balance` 為負時，需拋出 `std::invalid_arguments` 例外
    - `std::string GetBeneficiary()`
        - 函數類別：Getter/Setter
        - 行為：取得受益人
    - `void Deposit(int amount)`
        - 敘述：`TrustAccount` 不可進行存入，需拋出 `std::invalid_arguments` 例外
    - `int Withdraw(int amount)`
        - 敘述：`TrustAccount` 不可進行提領，需拋出 `std::invalid_arguments` 例外
    - `void Transfer(std::shared_ptr<Account> dest, int amount)`
        - 敘述：覆寫 `Account` 中的 `void Transfer(std::shared_ptr<Account> dest, int amount)`
        - 行為：我們將 `amount` 轉入到 `dest` 這個帳戶，同時帳戶內要減少 `amount` 數量的錢
        - 只能轉給名稱是 `beneficiary` 的帳戶
        - 若 `amount` 超過帳戶內的 `balance` ， 拋出 `std::invalid_arguments` 例外
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
        - 若名稱是 `beneficiary` 的帳戶不存在，需拋出 `std::invalid_arguments` 例外

## 目標二、設計所有的商品類別 (ut_test_2)

### 商品介面

- `class IBankProduct`
    - 敘述：為銀行商品的介面，所有商品須繼承此介面
    - `ProductType GetProductType()`
        - 函數類別：Getter
        - 回傳：商品類型
    - `int GetMonthlyFee()`
        - 函數類別：Getter
        - 回傳：商品費用
    - `std::string GetName()`
        - 函數類別：Getter
        - 回傳：商品名稱
    - 以上皆為純虛擬函數，需在子類別覆寫
- `class IRevenueGeneratable`
    - 敘述：可以幫銀行產生額外收益的商品
    - `int EstimateRevenue(int months)`
        - 敘述：為純虛擬函數，於需要繼承的物件中進行說明
        - 若 `months` 為負，需拋出 `std::invalid_arguments` 例外
- `class IRiskEvaluable`
    - 敘述：代表具有風險性質的商品
    - `int GetRiskLevel()`
        - 敘述：為純虛擬函數
        - 函數類別：Getter
        - 回傳：商品名稱

### 商品類別
- `class InsuranceProduct`
    - `InsuranceProduct(std::string name, double rate, int fee, int risk)`
        - 函數類別：建構子
        - 第一個參數 `name` ： 商品名稱
        - 第二個參數 `rate` ： 商品利率 (%)
        - 第三個參數 `fee` ： 商品費用 (月)
        - 第四個參數 `risk` ：商品風險
        - 當傳入的 `rate` 、 `fee` 以及 `risk` 為負時，需拋出 `std::invalid_arguments` 例外
    - `int EstimateRevenue(int months)`
        - 敘述：根據傳入的 `months` ，回傳商品可獲得的收益
        - 公式為： 月費用 * (1 + 利率) * 月份
        - 當傳入的 `months` 為負時，需拋出 `std::invalid_arguments` 例外
    - `double GetRate()`
        - 函數類別：Getter
        - 回傳：商品利率
- `class MutualFundProduct`
    - `MutualFundProduct(std::string name, double rate, int fee, int risk)`
        - 函數類別：建構子
        - 第一個參數 `name` ： 商品名稱
        - 第二個參數 `rate` ： 商品利率 (%)
        - 第三個參數 `fee` ： 商品費用 (月)
        - 第四個參數 `risk` ：商品風險
        - 當傳入的 `rate` 、 `fee` 以及 `risk` 為負時，需拋出 `std::invalid_arguments` 例外
    - `int EstimateRevenue(int months)`
        - 敘述：根據傳入的 `months` ，回傳商品可獲得的收益
        - 公式為： 月費用 * (1 + 利率) * 月份
        - 當傳入的 `months` 為負時，需拋出 `std::invalid_arguments` 例外
    - `double GetRate()`
        - 函數類別：Getter
        - 回傳：商品利率
- `class CreditCardProduct`
    - `CreditCardProduct(std::string name, double rate, int payment)`
        - 函數類別：建構子
        - 第一個參數 `name` ： 商品名稱
        - 第二個參數 `rate` ： 商品利率 (%)
        - 第三個參數 `payment` ： 每月費用
        - 當傳入的 `rate` 、 `payment` 為負時，需拋出 `std::invalid_arguments` 例外
    - `int EstimateRevenue(int months)`
        - 敘述：根據傳入的 `months` ，回傳商品可獲得的收益
        - 公式為： 每月費用 * 利率 * 月份
        - 當傳入的 `months` 為負時，需拋出 `std::invalid_arguments` 例外
    - `double GetRate()`
        - 函數類別：Getter
        - 回傳：商品利率
    - 這裡可將 `payment` 當作當期帳單看待即可
- `class FixedDepositProduct`
    - `FixedDepositProduct(std::string name, double rate, int fee)`
        - 函數類別：建構子
        - 第一個參數 `name` ： 商品名稱
        - 第二個參數 `rate` ： 商品利率 (%)
        - 第三個參數 `fee` ： 商品費用
        - 當傳入的 `rate` 、 `fee` 為負時，需拋出 `std::invalid_arguments` 例外
    - `int GetMonthlyFee()`
        - 函數類別：Getter
        - 回傳：商品費用
        - 行為：由於這裡的 `fee` 傳入是一整筆費用，在這裡請回傳 `fee * (1 + 利率) / 12`。以 `fee = 300000` 、 `rate = 5%` 為例，帶入公式後，須得到 `26250`
    - 同學們這裡可以將定存商品當作單利看待，簡化過程即可

## 目標三、設計銀行管理系統 (ut_all)

- `class Bank`
    - `Bank(long long initialCapital, double interestRate)`
        - 函數類別：建構子
        - 第一個參數 `initialCapital` ： 銀行初始資金
        - 第二個參數 `interestRate` ： 銀行初始利率
        - 當傳入的 `initialCapital` 為負時，需拋出 `std::invalid_arguments` 例外
        - 當傳入的 `interestRate` 為負時，需拋出 `std::invalid_arguments` 例外
    - `void SetRate(double rate)`
        - 函數類別：Setter
        - 設定銀行利率
        - 當傳入的 `rate` 為負時，需拋出 `std::invalid_arguments` 例外
    - `double GetRate()`
        - 函數類別：Getter
        - 回傳：銀行利率
    - `void AddCapital(long long capital)`
        - 增加銀行資金
        - 當傳入的 `capital` 為負時，需拋出 `std::invalid_arguments` 例外
    - `long long GetCapital()`
        - 函數類別：Getter
        - 回傳：銀行資金
    - `void AddAccount(std::shared_ptr<Account> acc)`
        - 新增一個帳戶資料到銀行中
    - `std::shared_ptr<Account> FindAccountByName(std::string name)`
        - 根據 `name` 找尋特定的銀行帳戶
        - 若帳戶名稱不存在在銀行裏面，需拋出 `std::invalid_arguments` 例外
    - `std::vector<std::shared_ptr<Account>> FindAccountByType(AccountType type)`
        - 根據 `type` 找尋在銀行中所有同類別的帳戶
        - 若沒有任何同類別的帳戶存在在銀行裏面，需拋出 `std::invalid_arguments` 例外
    - `void TransferByName(std::string src, std::string dest, int amount)`
        - 敘述：轉帳功能，將帳戶名稱為 `src` 的錢轉移到名稱為 `dest` 帳戶內
        - 若 `amount` 為負，需拋出 `std::invalid_arguments` 例外
        - 轉帳時需遵守各類型帳戶的規則
    - `void AddProduct(std::shared_ptr<IBankProduct> product)`
        - 行為：新增一個產品到銀行裡面
    - `std::shared_ptr<IBankProduct> FindProductByName(const std::string& name)`
        - 行為：根據名稱找到相對應的銀行產品
        - 注意：測資保證只有一個同名的商品，不用考慮多個同名產品的問題
        - 若沒有對應的銀行產品，需拋出 `std::invalid_arguments` 例外
    - `std::vector<std::shared_ptr<IBankProduct>> FindProductsByType(ProductType type)`
        - 行為：根據 `type` 找到相對應的銀行產品
        - 若沒有想對應的銀行產品，需拋出 `std::invalid_arguments` 例外
    - `int EstimateTotalRevenue(int months)`
        - 行為：計算所有可以對銀行產生額外收益的產品收益總額
    - `int EstimateRiskCount()`
        - 行為：計算所有具有風險之商品數量
    - `std::shared_ptr<IBankProduct> MakeCreditCardProduct(std::string name, int payment)`
        - 行為：生成具有信用卡商品，並將其儲存到 `Bank` 內
        - 行為：產品的 `rate` 依照 `bank` 當下的利率為主
        - 限制：給定參數需符合信用卡商品限制，若不符則需要拋出 `std::invalid_arguments` 例外
    - `std::shared_ptr<IBankProduct> MakeFixedDepositProduct(std::string name, int fee)`
        - 行為：生成具有定儲商品，並將其儲存到 `Bank` 內
        - 行為：在製作時需要根據 `name` 的帳戶扣除相對應的 `fee`
        - 行為：產品的 `rate` 依照 `bank` 當下的利率為主
        - 限制：若帳戶的金額不夠扣除 `fee` ，則需要拋出 `std::invalid_arguments` 例外
        - 限制：傳入的 `name` 需要尋找是否有帳戶在 `Bank` 內，否則拋出 `std::invalid_arguments` 例外
        - 限制：給定參數需符合定儲商品限制，若不符則需要拋出 `std::invalid_arguments` 例外
    - `std::shared_ptr<IBankProduct> MakeInsuranceProduct(std::string name, int fee, int risk)`
        - 行為：生成具有保險商品，並將其儲存到 `Bank` 內
        - 行為：產品的 `rate` 依照 `bank` 當下的利率為主
        - 限制：給定參數需符合保險商品限制，若不符則需要拋出 `std::invalid_arguments` 例外
    - `std::shared_ptr<IBankProduct> MakeMutualFundProduct(std::string name, int fee, int risk)`
        - 行為：生成具有基金商品，並將其儲存到 `Bank` 內
        - 行為：產品的 `rate` 依照 `bank` 當下的利率為主
        - 限制：給定參數需符合基金商品限制，若不符則需要拋出 `std::invalid_arguments` 例外
## Score

- [30%] Task1 完成目標一
    - ut_test_1
- [30%] Task2 完成目標二
    - ut_test_2
- [40%] Task3 完成目標三
    - ut_all

- 以上，若完成 `ut_all` 則包含以上三筆任務。

## 表單連結

[OJ 期末調查回饋](https://docs.google.com/forms/d/e/1FAIpQLSc9lkwG-Zp3a1LI5maSqnp4q5d8Sk2viOHLapuAY9nFzXMSwA/viewform)

## Meme

![finalmeme](./docs/meme.png)
