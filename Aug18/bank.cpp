#include "bank.h"
#include <string>
#include <iostream>
//Bank part

Bank::Bank() : m_cap(30), m_count(0), m_acc(new Account[m_cap]){}

Bank::~Bank()
{
    delete[] m_acc;
    m_acc = nullptr;
}

int Bank::creatAccout()
    {
    if(m_count == m_cap)
    {
        m_cap *= 2;
        Account* new_acc = new Account[m_cap];
        for(size_t i = 0; i < m_count; ++i)
        {
            new_acc[i] = m_acc[i]; 
        }
        delete[] m_acc;
        m_acc = new_acc;
        new_acc = nullptr;
    }

    std::string name;
    std::cout << "Enter Your Real Name: ";
    std::getline(std::cin, name);
    
    m_acc[m_count].setName(name);
    m_acc[m_count].setID(m_count);
    m_acc[m_count].setBalance(0.0);
    m_count ++;
   
    return m_count - 1; 
    }

void Bank::Dep(int i, double value)
{
    m_acc[i].deposit(value);
}

void Bank::Wit(int i, double value){
    m_acc[i].withdraw(value);
}

void Bank::printinfo(int i)
{
    std::cout << "Account info for " << "ID"  << i + 1 << std::endl;
    std::cout << "Name: " << m_acc[i].getName() << std::endl;
    std::cout << "Balance: " << m_acc[i].getBalance() << std::endl;
}




//Account part

Account::Account(): m_id(0), m_balance(0.0), m_name(""){}

Account::~Account()
{
    m_id = 0;
    m_balance = 0.0;
    m_name = "";
}

void Account::setID(int id)
{
    m_id = id;
}
void Account::setBalance(double balance)
{
    m_balance = balance;
}
void Account::setName(std::string name)
{
    m_name = name;
}
int Account::getID()const
{
    return m_id;
}
double Account::getBalance()const
{
    return m_balance;
}
std::string Account::getName()const
{
    return m_name;
}
void Account::deposit(double value)
{
    m_balance += value;
}
void Account::withdraw(double value)
{
    if(m_balance >= value){
        m_balance -= value;
    }
    else {
        std::cerr << "You don't have enough funds" << std::endl;
    }
}

