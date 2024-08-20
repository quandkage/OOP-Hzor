#include "User.h"
#include <exception>
#include <iostream>
#include <typeinfo>

void identifyType(const void* obj) {
    const std::type_info& type = typeid(*static_cast<const User*>(obj));

    if (type == typeid(User)) {
        std::cout << "The object is of type User." << std::endl;
    } else {
        std::cout << "The object is of a different type: " << type.name() << std::endl;
    }
}

int main(){
    try {
        User user("example@gmail.com", "Pa$$w0rd", "Quand Kage");
        std::cout << "Initial Email: " << user.getEmail() << std::endl;
        std::cout << "Initial Full Name: " << user.getName() << std::endl;
        
        identifyType(&user);

        if(user.changePassword("Pa$$w0rd", "NewPa$$2")) {
            std::cout << "Password changed successfully." << std::endl;
        }
        else {
            std::cout << "Password change failed." << std::endl;
        }
        if(user.changeEmail("NewPa$$2", "newemail@gmail.com")){
            std::cout << "Email updated successfully." << std::endl;
        } else {
            std::cout << "Email update failed." << std::endl;
        }
        std::cout << "Updated Email: " << user.getEmail() << std::endl;
        std::cout << "Full Name: " << user.getName() << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;

}
