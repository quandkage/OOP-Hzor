#include "Headers/JointAccount.h"
#include <iostream>

JointAccount::JointAccount(int accountNumber, double balance, std::string accountType)
    : Account(accountNumber, balance, accountType){}

void JointAccount::deposit(double amount) {
    if(amount <= m_balance) {
        m_balance += amount;
        Transaction* trs = new Transaction(nullptr, this, amount, "Joint Account Deposit");
        m_accountTransactions.push_back(trs);
        std::cout << "Deposited " << amount << ". New balance: " << m_balance << std::endl;

    }
    else {
        std::cerr << "Deposit Error ! " << amount << std::endl;
    }
}

void JointAccount::withdraw(double amount) {
    if(amount <= m_balance && amount > 0) {
        m_balance -= amount;
        Transaction* trs = new Transaction(this, nullptr, amount, "Joint Account Withdraw");
        m_accountTransactions.push_back(trs);
        std::cout << "Withdrawn " << amount << ". New balance: " << m_balance << std::endl;
    }
    else {
        std::cerr << "Not enough money to withdraw !" << amount << std::endl;
    }
}

void JointAccount::transfer(Account& destination, double amount) {
    if(amount <= m_balance && amount > 0) {
        m_balance -= amount;
        Transaction* trs =  new Transaction(this, &destination, amount, "Joint Account Transfer");
        m_accountTransactions.push_back(trs);
        std::cout << "Transfer Successfully!" << std::endl;
        std::cout << "New Balance : " << m_balance << std::endl;
    } else {
        std::cerr << "Transfer Error ! " << amount << std::endl;
    }
}

void JointAccount::showBalance() const {
    std::cout << "Balance : " << m_balance << std::endl;
}

std::string JointAccount::getAccountType() const {
    return "JointAccount";
}

void JointAccount::addCustomer(std::string customerName) {
    m_Jointaccounts.push_back(customerName);
}

void JointAccount::getAccounts() const {
    for(int i = 0; i < m_Jointaccounts.size(); ++i) {
        std::cout << "Account : " << m_Jointaccounts[i] << std::endl;
    }
}


void JointAccount::showTransactionHistory() const {
    for(int i = 0; i < m_accountTransactions.size(); ++i) {
        if(m_accountTransactions[i] != nullptr) {
            m_accountTransactions[i]->getTransaction();
        } else {
            std::cout << "Transaction doesn't exist!" << std::endl;
        }
    }
}

void JointAccount::logTransaction(const std::string &type, double amount) {
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

JointAccount::~JointAccount() {
    m_Jointaccounts.clear();
}
