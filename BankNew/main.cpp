#include <iostream>
#include <string>
#include "Headers/Customer.h"
int main()
{
    std::string name;
    std::string Email;
    std::string accType;
    std::cout << "Welcome to the Bank ! " << std::endl;
    std::cout << "What is Your name ?: " << std::endl;
    std::cin >> name;
    std::cout << "What is Your email address ?: " << std::endl;
    std::cin >> Email;
    std::cout << "What is Your account type ?: " << std::endl;
    std::cin >> accType;
    Customer cus(name, Email, accType);
    std::string choice = "Y";
    std::cout << "Do you want to make another Account ? [Y/N]" << std::endl;
    do {
        std::cout << "Yes -> Making account." << std::endl;
        std::cout << "No -> Exit." << std::endl;
        std::cin >> choice;
    } while(choice != "Y" || choice == "N");
    if (choice == "Y") {
        cus.addAccount();
    }
    else {
        std::cout << "Exiting..." << std::endl;
    }
    choice = "Y";


    return 0;
}
