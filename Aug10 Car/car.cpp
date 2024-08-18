#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;
    double mileage;

public:

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getMileage() const {
        return mileage;
    }

    void setMake(const std::string make) {
        this->make = make;
    }

    void setModel(const std::string model) {
        this->model = model;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setMileage(double mileage) {
        this->mileage = mileage;
    }

   
    void displayInfo() const {
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Mileage: " << mileage << " km" << std::endl;
    }
};


int main(){
    Car car1;
    car1.setMake("Porche");
    car1.setModel("911 GT3RS");
    car1.setYear(2023);
    car1.setMileage(3445);
    
    Car car2;
    car2.setMake("Koenigsegg");
    car2.setModel("Jesko");
    car2.setYear(2022);
    car2.setMileage(32210);
    
    std::cout << "1st car information" << std::endl;
    car1.displayInfo();
    std::cout << std::endl;
    
    std::cout << "2nd car information" << std::endl;
    car2.displayInfo();
    
    return 0;
}
