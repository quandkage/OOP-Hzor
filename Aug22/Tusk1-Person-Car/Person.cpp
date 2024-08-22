#include <string>
#include "Person.h"
#include <iostream>

Person::Person(const int& age, const std::string& name, const Car& car): m_age(age), m_name(name), c(nullptr){
}
Person::Person(): m_age(0), m_name(""), c(nullptr){}

void Person::setAge(const int &age){
    m_age = age;
}

void Person::setName(const std::string &name){
    m_name = name;
}

void Person::assignCar(const Car &car){
    if(c) {
        delete c;
    }
    c = new Car(car);
}
void Person::getCar() const {
    if(c){
        c->describeCar();
    }
    else {
        std::cout << "No car Assigned" << std::endl;
    }
}
int Person::getAge() const{
    return m_age;
}
std::string Person::getName() const{
    return m_name;
}
void Person::infoPerson() const{
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Age: " << m_age << std::endl;
}

Car::Car(const std::string &model, const std::string &color, const int &year): c_year(year), c_color(color), c_model(model){}

Car::Car(): c_year(0), c_color(""), c_model(""){}

void Car::setYear(const int &year){
    c_year = year;
}
void Car::setColor(const std::string &color)
{
    c_color = color;
}
void Car::setModel(const std::string &model){
    c_model = model;
}
int Car::getYear() const {
    return c_year;
}
std::string Car::getColor() const {
    return c_color;
}
std::string Car::getModel() const {
    return c_model;
}
void Car::describeCar() const {
    std::cout << "Model: " << c_model << std::endl; 
    std::cout << "Color: " << c_color << std::endl;
    std::cout << "Year: " << c_year << std::endl;
}

Car::~Car(){
    c_year = 0;
    c_color = "";
    c_model = "";
}

Person::~Person(){
    delete c;
    m_age = 0;
    m_name = "";
    c = nullptr;
}


