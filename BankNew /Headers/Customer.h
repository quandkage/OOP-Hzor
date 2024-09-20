#pragma once
#include "Account.h"
#include "CheckingAccount.h"
#include "JointAccount.h"
#include "SavingsAccount.h"
#include <vector>
#include <string>

class Customer {
private:
    std::string m_name;
    std::string m_contactInfo;
    std::string m_accountType;
    mutable std::vector<Account*> m_accounts;
    static std::vector<Customer*> m_customers;
public:
    static int accountNumber;
    Customer() = default;
    Customer(std::string name, std::string contactInfo, std::string accountType);
    ~Customer();
    Customer(const Customer& other) = delete;
    Customer& operator=(const Customer& other) = delete;
    Customer(Customer&& other) = delete;
    Customer& operator=(Customer&& other) = delete;
    void addAccount() const;
    void viewAccounts() const;
    void viewTransactionHistory() const;
    void customerinfo() const;
    void customerInterace() const;
    void showBalance() const;
};

int Customer::accountNumber = 1;