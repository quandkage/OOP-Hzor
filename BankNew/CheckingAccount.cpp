#include "Headers/CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(int accountNumber, double balance, const std::string& accountType, double overdraft): Account(accountNumber,balance,accountType), m_overdraftLimit(overdraft){
}

void CheckingAccount::deposit(double amount) {
    if(amount >= 0.0) {
        Transaction* trs = new Transaction(nullptr,this,amount, "Deposit");
        m_balance += amount;
        m_accountTransactions.push_back(trs);
        std::cout << "Deposited " << amount << " without interest " << ". New balance: " << m_balance << std::endl;
    } else {
        std::cerr << "Depositing failed. Deposit amount must be positive !" << std::endl;
    }
}

void CheckingAccount::withdraw(double amount) {
    if(amount <= m_balance + m_overdraftLimit) {
        Transaction* trs = new Transaction(this,nullptr, amount, "Withdraw");
        m_accountTransactions.push_back(trs);
        if(m_balance < 0) {
            m_overdraftLimit += m_balance;
        }
        std::cout << "Withdrawn " << amount << " Overdraft limit " << m_overdraftLimit <<". New balance: " << m_balance << std::endl;
    }
    else {
        std::cerr << "Not enough money to withdraw !" << std::endl;
    }
}

void CheckingAccount::transfer(Account &destination, double amount) {
    if(amount <= m_balance + m_overdraftLimit) {
        Transaction* trs = new Transaction(this,&destination, amount, "Transfer");
        m_accountTransactions.push_back(trs);
        m_balance -= amount;
        if(m_balance < 0) {
            m_overdraftLimit += m_balance;
            m_balance = 0;
        }
        std::cout << "Transfer " << amount << "Overdraft limit" << m_overdraftLimit << ". New balance: " << m_balance << std::endl;
    }
    else {
        std::cerr << "Not enough money to Transfer !" << std::endl;
    }
}
void CheckingAccount::showBalance() const {
    std::cout << "Balance : " << m_balance << std::endl;
}

std::string CheckingAccount::getAccountType() const {
    return "CheckingAccount";
}

void CheckingAccount::setOverdraftLimit(double overdraftLimit) {
    m_overdraftLimit = overdraftLimit;
}

double CheckingAccount::getOverdraftLimit() const {
    return m_overdraftLimit;
}

void CheckingAccount::showTransactionHistory() const {
    for(int i = 0; i < m_accountTransactions.size(); ++i) {
        if(m_accountTransactions[i] != nullptr) {
            m_accountTransactions[i]->getTransaction();
        } else {
            std::cout << "Transaction doesn't exist!" << std::endl;
        }
    }
}

void CheckingAccount::logTransaction(const std::string &type, double amount) {
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








