#ifndef USER_H
#define USER_H
#include <typeinfo>
#include <string>

class User 
{
    private:
        std::string m_email;
        std::string m_password;
        std::string m_fullname;
        bool PassValid(const std::string& pwd);
 
        public:
        User(const std::string& email, const std::string& password, const std::string & fullname);
        ~User();
        User& operator = (User&) = default;

        User(const User&) = delete;
        User(User&&) = delete;
        User& operator = (User&&) = delete;
        void setEmail(const std::string& email);
        void setPass(const std::string& Pass);
        void setName(const std::string& fullname);
        std::string getEmail() const;
        std::string getPass() const;
        std::string getName() const;
        bool changePassword(const std::string& oldPass, const std::string& newPass);
        bool changeEmail(const std::string& currentPassword, const std::string& newEmail);

};
void identifyType(const std::type_info& type);

#endif
