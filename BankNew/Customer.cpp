#include <iostream>
#include "../Headers/Customer.h"

int accountNum = 1;
Customer::Customer(std::string name, std::string contactInfo, std::string accountType)
    : m_name(name), m_contactInfo(contactInfo), m_accountType(accountType) {

    std::cout << "Creating Account ..." << std::endl;
    size_t num = 0;
    do {
        std::cout << "Enter Account Type: " << std::endl;
        std::cout << "1 -> Checking account:" << std::endl;
        std::cout << "2 -> Saving Account:" << std::endl;
        std::cout << "3 -> Joint Account:" << std::endl;
        std::cout << "0 -> Exit" << std::endl;
        std::cin >> num;
    } while (num > 3);
    switch (num) {
        case 1: {
            std::cout << "Creating Checking account ..." << std::endl;
            size_t overdraft = 0;
            std::cout << "Enter Overdraft Limit:" << std::endl;
            std::cin >> overdraft;
            Account *ptr = new CheckingAccount(accountNum, 0, "Checking Account", overdraft);
            m_accounts.push_back(ptr);
            accountNum++;
            std::cout << "Account Created Successfully!" << std::endl;
            break;
        }
        case 2: {
            std::cout << "Creating Saving account ..." << std::endl;
            size_t interest = 0;
            std::cout << "Enter Interest Rate:" << std::endl;
            std::cin >> interest;
            Account* ptr = new SavingsAccount(accountNum, 0.0, "Savings Account", interest);
            m_accounts.push_back(ptr);
            accountNum++;
            std::cout << "Account Created Successfully!" << std::endl;
            break;
        }
        case 3: {
            std::cout << "Creating Joint account ... " << std::endl;
            Account* ptr = new JointAccount(accountNum, 0.0, "Joint Account");
            accountNum++;
            m_accounts.push_back(ptr);
            std::cout << "Account Created Successfully!" << std::endl;
            break;
        }
        case 0: {
            std::cout << "Exiting ... " << std::endl;
            return;
        }
        default: {
            std::cerr << "Invalid Input!" << std::endl;
            return;
        }
        if(m_accounts.empty()) {
            throw std::invalid_argument("Account is empty!");
        } else {
            m_customers.push_back(this);
        }
    }
}

std::vector<Customer*> Customer::m_customers = {};


void Customer::addAccount() const{
    std::cout << "Adding Account ... " << std::endl;
    size_t num = 0;
    do {
        std::cout << "Enter Account Type: " << std::endl;
        std::cout << "1 -> Checking account:" << std::endl;
        std::cout << "2 -> Saving Account:" << std::endl;
        std::cout << "3 -> Joint Account:" << std::endl;
        std::cout << "0 -> Exit" << std::endl;
        std::cin >> num;
    } while (num > 3);
    switch (num) {
        case 1: {
            std::cout << "Creating Checking account ..." << std::endl;
            size_t overdraft = 0;
            std::cout << "Enter Overdraft Limit:" << std::endl;
            std::cin >> overdraft;
            Account *ptr = new CheckingAccount(accountNum, 0, "Checking Account", overdraft);
            m_accounts.push_back(ptr);
            accountNum++;
            std::cout << "Account Created Successfully!" << std::endl;
            break;
        }
        case 2: {
            std::cout << "Creating Saving account ..." << std::endl;
            size_t interest = 0;
            std::cout << "Enter Interest Rate:" << std::endl;
            std::cin >> interest;
            Account* ptr = new SavingsAccount(accountNum, 0.0, "Savings Account", interest);
            m_accounts.push_back(ptr);
            accountNum++;
            std::cout << "Account Created Successfully!" << std::endl;
            break;
        }
        case 3: {
            std::cout << "Creating Joint account ... " << std::endl;
            Account* ptr = new JointAccount(accountNum, 0.0, "Joint Account");
            m_accounts.push_back(ptr);
            accountNum++;
            std::cout << "Account Created Successfully!" << std::endl;
            break;
        }
        case 0: {
            std::cout << "Exiting ... " << std::endl;
            return;
        }
        default: {
            std::cerr << "Invalid Input!" << std::endl;
            return;
        }
    }
}

void Customer::viewAccounts() const {
    if(!m_accounts.empty()) {
        std::cout << "Your Accounts: " <<std::endl;
        for(size_t i = 0; i < m_accounts.size(); i++) {
            std::cout << "Account Type: " << m_accounts[i]->getAccountType() << std::endl;
            std::cout << "Account Balance: " << std::endl;
            m_accounts[i]->showBalance();
        }
    } else {
        throw(std::cerr<<"Customer doesn't have accounts!"<< std::endl);
    }
}

void Customer::viewTransactionHistory() const {
    if(!m_accounts.empty()) {
        std::cout << "Your Transaction History: " <<std::endl;
        for(size_t i = 0; i < m_accounts.size(); i++) {
            std::cout << "Account Type: " << m_accounts[i]->getAccountType() << std::endl;
            m_accounts[i]->showTransactionHistory();
            std::cout << "_________________" << std::endl;
        }
    } else {
        throw(std::cerr << "Transaction History is empty" << std::endl);
    }
}

void Customer::customerinfo() const {
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Contact info: " << m_contactInfo << std::endl;
}

void Customer::customerInterace() const {
    size_t choice = 0;
    do {
        std::cout << "Customer Interface Menu:" << std::endl;
        std::cout << "1 -> View Account(s) Info" << std::endl;
        std::cout << "2 -> View Transaction History" << std::endl;
        std::cout << "3 -> Add Account" << std::endl;
        std::cout << "0 -> Exit" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                viewAccounts();
            break;
            case 2:
                viewTransactionHistory();
            break;
            case 3:
                addAccount();
            break;
            case 0:
                std::cout << "Exiting ..." << std::endl;
            break;
            default:
                std::cerr << "Invalid choice!" << std::endl;
            break;
        }
    }while(choice > 3);
    choice = 0;

}





