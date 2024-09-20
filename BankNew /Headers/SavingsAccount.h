#pragma once
#include "Account.h"

class SavingsAccount : public Account{
private:
    double m_interestRate;
public:
    SavingsAccount() = default;
    SavingsAccount(int accountNumber, double balance, std::string accountType, double interestRate);
    ~SavingsAccount() = default;
    SavingsAccount(const SavingsAccount &other) = default;
    SavingsAccount& operator=(const SavingsAccount &other) = default;
    SavingsAccount(SavingsAccount &&other) = default;
    SavingsAccount& operator=(SavingsAccount &&other) = default;
    //Account overriding
    void deposit(double amount) override;
    void withdraw(double amount) override;
    void transfer(Account& destination, double amount) override;
    void showBalance() const override;
    std::string getAccountType() const override;
    //TransactionManager overriding
    void logTransaction(const std::string& type, double amount) override;
    void showTransactionHistory() const override;
    //Getters/Setters
    void setInterestRate(double InterestRate);
    double getInterestRate() const;

};