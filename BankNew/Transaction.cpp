#include "Headers/Transaction.h"
#include <iostream>

Transaction::Transaction(Account *fromAccount, Account *toAccount, double amount, const std::string& transactionType)
    : m_fromAccount(fromAccount), m_toAccount(toAccount), m_amount(amount), m_transactionType(transactionType){}

double Transaction::getAmount() const {
    return m_amount;
}

std::string Transaction::getTransactionType() const {
    return m_transactionType;
}

void Transaction::getTransaction() const {
    if(m_fromAccount == nullptr) {
        std::cout << "Deposited " << m_amount << " to " << m_toAccount << std::endl;
    } else if(m_toAccount == nullptr) {
        std::cout << "Withdrawn " << m_amount << " from " << m_fromAccount << std::endl;
    }
    if(m_fromAccount != nullptr && m_toAccount != nullptr) {
        std::cout << "Transferred " << m_amount << " from " << m_fromAccount << " to " << m_toAccount << std::endl;
    }

}
