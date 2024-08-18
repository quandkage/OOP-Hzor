#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;
    double mileage;

public:
    Car(): make(""), model(""), year(0), mileage(0){}

    Car(const std::string &make, const std::string &model, int year, int mileage){
        this->make = make;
        this->model = model;
        this->year = year;
        this->mileage = mileage;
    }
    Car(const Car& other){
        make = other.make;
        model = other.model;
        year = other.year;
        mileage = other.mileage;
    }
    ~Car(){}
    void displayInfo(){
        std::cout << "Make - " << make << std::endl;
        std::cout << "Model - " << model << std::endl;
        std::cout << "Year - " << year << std::endl;
        std::cout << "Mileage - " << mileage << std::endl;
    }
    void drive(double distance){
        mileage += distance;
    }
    void service(){
        mileage = 0;
    }

};

int main(){
    double km = 0.0;
    std::cout << "How many Km do you want to drive ? - ";
    std::cin >> km;
    std::cout << std::endl;
    Car ob2("Porche", "911 GT3RS", 2023, 4345); // parametrized constructor work demostration
    std::cout << "Car mileage before driving" << std::endl;
    ob2.displayInfo();
    ob2.drive(km);
    std::cout << std::endl;
    std::cout << "Car mileage after driving" << std::endl;
    ob2.displayInfo();
    std::cout << std::endl;
    std::cout << "Do you want to go Service [Y/N]" << std::endl;
    char a = 0;
    std::cin >> a;
    if(a == 'Y' || a == 'y'){
        ob2.service();
        std::cout << "The car was successfully repaired" << std::endl;
        ob2.displayInfo();
        std::cout << std::endl;
    }
    else {
        std::cout << "You have rejected the offer" << std::endl;
        ob2.displayInfo();
        std::cout << std::endl;
    }
    std::cout << "Delault constructor demostration" << std::endl;
    Car ob1;
    ob1.displayInfo(); //default constructor work demostration
    std::cout << std::endl;
    std::cout << "Copy constructor demostration" << std::endl;
    Car ob3(ob2); // copy constructor work demostration
    ob3.displayInfo();
    return 0;
}
