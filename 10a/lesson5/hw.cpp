#include <iostream>

using namespace std;

class Device
{
    // The device should have memory in GB, screen size, price, brand and constant serial number.
    // There should be a counter for the number of active devices(instances)
public:
    Device(double memorySize, double screenSize, double price, const string &brand, const string &constantSerial);
    Device(const Device &other);
    Device &operator=(const Device &other);

    /*
         (memory*size) / price greater than 0.1 is worth buying
    */
    bool isWorthBuying() const;

    // Getters and setters
};

class Phone : public Device
{
    // The phone should have camera parameters field
public:
    Phone(double memorySize, double screenSize, double price, const string &brand, const string &constantSerial, int cameraParameters);
    Phone(const Phone &other);
    Phone &operator=(const Phone &other);

    /*
         (memory*size) + (memory*cameraParameters) / price greater than 0.1 is worth buying
    */
    bool isWorthBuying() const;

    // Getters and setters
};

int main()
{
}