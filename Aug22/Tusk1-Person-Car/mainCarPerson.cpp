#include <iostream>
#include "Person.h"
#include <string>

int main(){
    Person Ent;
    char a;
    std::string name;
    int age = 0;
    std::cout << "What is your name ?: ";
    std::getline(std::cin, name);
    Ent.setName(name);
    std::cin.clear();
    std::cout << std::endl;
    std::cout << "How old are you ?: ";
    std::cin >> age;
    Ent.setAge(age);
    std::cout << std::endl;
    std::cout << "Do you have a car? [Y/N] or [y/n]: " << std::endl;
    std::cin >> a;
    if(a == 'Y' || a == 'y'){
        std::string model;
        std::string color;
        int year = 0;
        
        std::cout << "What is the model of your car ?: ";
        std::cin.ignore();
        std::getline(std::cin, model);
        
        std::cout << "What is the color of your car ?: ";
        std::getline(std::cin, color);
        
        std::cout << "When your car had been made ?: ";
        std::cin >> year;
        
        Car car(model, color, year);
        Ent.assignCar(car);
        std::cout << "About Person: " << std::endl;
        Ent.infoPerson();
        std::cout << "What he driving: " << std::endl;
        Ent.getCar();
    }
    else {
        std::cout << "About Person: " << std::endl;
        Ent.infoPerson();
        std::cout << "No car assigned." << std::endl;
    }
    return 0;
}
