#pragma once
#include "Account.h"

class CheckingAccount : public Account{
private:
    double m_overdraftLimit;
public:
    CheckingAccount() = default;
    CheckingAccount(int accountNumber, double balance, const std::string& accountType, double overdraft);
    ~CheckingAccount() = default;
    CheckingAccount(const CheckingAccount &other) = default;
    CheckingAccount& operator=(const CheckingAccount &other) = default;
    CheckingAccount(CheckingAccount &&other) = default;
    CheckingAccount& operator=(CheckingAccount &&other) = default;
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
    void setOverdraftLimit(double overdraftLimit);
    double getOverdraftLimit() const;

};
