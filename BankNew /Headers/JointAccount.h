#pragma once
#include "Account.h"
#include <vector>

class JointAccount : public Account{
private:
    std::vector<std::string> m_Jointaccounts;
public:
    JointAccount() = default;
    JointAccount(int accountNumber, double balance, std::string accountType);
    ~JointAccount();
    JointAccount(const JointAccount &other) = default;
    JointAccount& operator=(const JointAccount &other) = default;
    JointAccount(JointAccount &&other) = default;
    JointAccount& operator=(JointAccount &&other) = default;
    //Account overriding
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void transfer(Account& destination, double amount) override;
    void showBalance() const override;
    std::string getAccountType() const override;
    //TransactionManager overriding
    void logTransaction(const std::string& type, double amount) override;
    void showTransactionHistory() const override;
    //New method
    void getAccounts() const;
    void addCustomer(std::string customerName);
};