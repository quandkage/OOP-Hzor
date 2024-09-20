#include "Headers/SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int accountNumber, double balance, std::string accountType, double interestRate)
    :Account(accountNumber, balance, accountType), m_interestRate(interestRate) {
}

void SavingsAccount::deposit(double amount) {
    if(amount >= 0.0) {
        double interest = amount * m_interestRate;
        m_balance += interest;
        Transaction* trs = new Transaction(nullptr, this, amount, "Deposit with Interest");
        m_accountTransactions.push_back(trs);
        std::cout << "Deposited " << amount << " with interest " << interest << ". New balance: " << m_balance << std::endl;
    } else {
        std::cerr << "Deposit amount must be positive !" << std::endl;
    }
}

void SavingsAccount::withdraw(double amount) {
    if(amount > 0.0) {
        double availableBalance = m_balance;
        double interest = availableBalance * m_interestRate;
        if(amount <= availableBalance + interest) {
            m_balance -= amount;
            Transaction* trs = new Transaction(this, nullptr, amount, "Withdraw with interest");
            m_accountTransactions.push_back(trs);
            std::cout << "Withdrawn " << amount << " with interest " << ". New balance: " << m_balance << std::endl;
        } else {
            std::cerr << "Insufficient funds for withdraw!" << std::endl;
        }
    } else {
        std::cerr << "Withdraw amount must be positive!" << std::endl;
    }
}

void SavingsAccount::transfer(Account& destination,double amount) {
    if(amount > 0.0) {
        double availableBalance = m_balance;
        double interest = availableBalance * m_interestRate;
        if(amount <= availableBalance + interest) {
            m_balance -= amount;
            Transaction* trs = new Transaction(this, &destination, amount, "Transfer with interest");
            m_accountTransactions.push_back(trs);
            std::cout << "Transfer " << amount << ". New balance: " << m_balance << std::endl;
        } else {
            std::cerr << "Insufficient funds for transfer!" << std::endl;
        }
    } else {
        std::cerr << "Transfer amount must be positive!" << std::endl;
    }
}

void SavingsAccount::showBalance() const {
    std::cout << "Balance: " << m_balance << std::endl;
}

std::string SavingsAccount::getAccountType() const {
    return "SavingsAccount";
}

double SavingsAccount::getInterestRate() const {
    return m_interestRate;
}

void SavingsAccount::showTransactionHistory() const {
    for(int i = 0; i < m_accountTransactions.size(); ++i) {
        if(m_accountTransactions[i] != nullptr) {
            m_accountTransactions[i]->getTransaction();
        } else {
            std::cout << "Transaction doesn't exist!" << std::endl;
        }
    }
}

void SavingsAccount::logTransaction(const std::string &type, double amount) {
    for(int i = 0; i < m_accountTransactions.size(); ++i) {
        if(m_accountTransactions[i]->getTransactionType() == type &&  amount == m_accountTransactions[i]->getAmount()) {
            m_accountTransactions[i]->getTransaction();
        }
        else {
            std::cerr << "Transaction type mismatch" << std::endl;
            return;
        }
    }
}