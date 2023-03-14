#include <iostream>

using namespace std;

enum CarType
{
    COUPE,
    COMBI,
    SEDAN,
    SUV
};

class Car
{

    const string VIN;
    int numberOfSeats;
    CarType type;

protected:
    string brand;
    int power;
    string regNumber;

public:
    Car(const string &VIN, int numberOfSeats, CarType type)
        : VIN(VIN), numberOfSeats(numberOfSeats), type(type)
    {
        if (VIN.size() != 18)
        {
            throw invalid_argument("VIN is invalid");
        }
        if (numberOfSeats < 1)
        {
            throw invalid_argument("number of seats should be positive number");
        }
    }
    void registerCar(const string &regNumber)
    {
        // Validate
        if (regNumber.size() == 0)
        {
            throw invalid_argument("Invalid registration number");
        }
        this->regNumber = regNumber;
    }
    Car &operator=(const Car &other)
    {
    }

    const string &getVIN() const
    {
        return this->VIN;
    }
    void setNumberOfSeats(int number)
    {
        // Validate

        this->numberOfSeats = number;
    }
};

class SportCar : public Car
{
    const string driver;

public:
    SportCar(const string &brand, const string &VIN, const string &driver, int power, int numberOfSeats, CarType type)
        : Car(VIN, numberOfSeats, type), driver(driver)
    {
        this->brand = brand;
        Car::setNumberOfSeats(5);
    }

    SportCar(const SportCar &other)
        : Car(other)
    {
    }
    SportCar &operator=(const SportCar &other)
    {
        if (this != &other)
        {
            Car::operator=(other);
        }
    }
    const string getVIN() const
    {
        return "VIN is " + Car::getVIN();
    }
};

int main()
{
    SportCar sc("Ferrari", "123456789012345678", "Charles", 712, 4, CarType::SUV);
    cout << sc.getVIN() << endl;
}