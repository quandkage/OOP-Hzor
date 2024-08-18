#include <string>
class Account
{
    private:
        int m_id;
        double m_balance;
        std::string m_name;
    public:
        Account();
        ~Account();
        Account& operator = (Account&) = default;

        Account(const Account&) = delete;
        Account(Account&&) = delete;
        Account& operator = (Account&&) = delete;
        void deposit(double);
        void withdraw(double);
        void setID(int id);
        void setBalance(double balance);
        void setName(std::string name);
        int getID() const;
        double getBalance() const;
        std::string getName() const;

};

class Bank
{
    private:
        int m_cap;
        int m_count;
        Account* m_acc;
    public:
        Bank();
        ~Bank();
        Bank(const Bank&) = delete;
        Bank& operator=(const Bank&) = delete;
        Bank(Bank&&) = delete;
        Bank& operator=(Bank&&) = delete;
        int creatAccout();
        void Dep(int, double);
        void Wit(int, double);
        void printinfo(int);
};



