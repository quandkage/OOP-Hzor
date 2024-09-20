#pragma once
#include <string>
#include "Account.h"

class Transaction {
private:
    Account* m_fromAccount;
    Account* m_toAccount;
    double m_amount;
    std::string m_transactionType;
public:
    Transaction() = default;
    ~Transaction() = default;
    Transaction(Account* fromAccount, Account* toAccount, double amount, const std::string& transactionType);
    double getAmount() const;
    std::string getTransactionType() const;
    void getTransaction() const;
};
