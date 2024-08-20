#include <iostream>
#include "User.h"
#include <cctype>
#include <stdexcept>
#include <string>

bool User::PassValid(const std::string& pwd)
{
    if(pwd.length() < 8)
    {
        return false;
    }
    bool Digit = false;
    bool SpecialChar = false;

    for(char ch : pwd)
    {
        if(std::isdigit(ch))
        {
            Digit = true;
        }
        if(!std::isalnum(ch))
        {
            SpecialChar = true;
        }
    }
    return Digit && SpecialChar;
}

User::User(const std::string& email, const std::string& password, const std::string& fullname): m_password(password), m_email(email), m_fullname(fullname)
{
    if(PassValid(m_password))
    {
        m_password = password;
    } else {
        throw std::invalid_argument("Invalid Password");
    }
} 

User::~User(){}

void User::setEmail(const std::string& email)
{
    m_email = email;
}
void User::setName(const std::string &fullname)
{
    m_fullname = fullname;
}
void User::setPass(const std::string &Pass)
{
    m_password = Pass;
}
std::string User::getPass() const {
    return m_password;
}
std::string User::getEmail() const {
    return m_email;
}
std::string User::getName() const {
    return m_fullname;
}
bool User::changePassword(const std::string &oldPass, const std::string &newPass){
    if(oldPass == m_password)
    {
        if(PassValid(newPass))
        {
            m_password = newPass;
            return true;
        }
        else {
            std::cerr << "New Password does not meet criteria." << std::endl;
        }
    } else {
        std::cerr << "Old password is incorrect." << std::endl;
    }
        return false; 
}

bool User::changeEmail(const std::string &currentPassword, const std::string &newEmail)
{
    if(currentPassword == m_password)
    {
        m_email = newEmail;
        return true;
    }
    else {
        std::cerr << "Password is incorrect." << std::endl;
        return false;
    }
}
void identifyType(const std::type_info& type) {
    if (type == typeid(User)) {
        std::cout << "The object is of type User." << std::endl;
    } else {
        std::cout << "The object is of a different type: " << type.name() << std::endl;
    }
}
