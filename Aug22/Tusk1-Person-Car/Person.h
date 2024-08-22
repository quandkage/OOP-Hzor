#ifndef PERSON_H
#define PERSON_H

#include <string>

class Car {
    private:
        int c_year;
        std::string c_color;
        std::string c_model;
        
    public:
        Car();    
        Car(const std::string &model, const std::string &color, const int &year);
        ~Car();
        Car(const Car&) = default;
        Car& operator = (const Car&) = default;        
        Car(Car&&) = delete;
        Car& operator = (Car&&) = delete;
        void setYear(const int& year);
        void setColor(const std::string& color);
        void setModel(const std::string& model);
        int getYear() const;
        std::string getColor() const;
        std::string getModel() const;
        void describeCar() const;
};


class Person {
    private:
        int m_age;
        std::string m_name;
        Car *c;

    public:
        Person();
        Person(const int& age, const std::string& name, const Car& car);
        ~Person();
        Person(const Person&) = delete;
        Person(Person&&) = delete;
        Person& operator = (Person&&) = delete;
        Person& operator = (Person&) = delete;
        void setAge(const int& age);
        void setName(const std::string& name);
        void assignCar(const Car& car);
        int getAge() const;
        std::string getName() const;
        void getCar() const; 
        void infoPerson() const;
};


#endif
