#pragma once
#include <string>
#include <vector>
#include "TransactionManager.h"
#include "Transaction.h"

class Account : public TransactionManager {
protected:
    int m_accountNumber;
    double m_balance;
    std::string m_accountType;
    std::vector<Transaction*> m_accountTransactions;
public:
    Account(int accountNumber, double balance, std::string accountType);
    virtual ~Account();
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void transfer(Account& destination, double amount) = 0;
    virtual void showBalance() const = 0;
    virtual std::string getAccountType() const = 0;
    virtual void logTransaction(const std::string& type, double amount) = 0;
    virtual void showTransactionHistory() const = 0;
};
