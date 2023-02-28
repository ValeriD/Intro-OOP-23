#include <iostream>
#include <cstring>

using namespace std;

//----------------------------------------------------------------
// const char* vs char const *
// https://stackoverflow.com/a/890560
//----------------------------------------------------------------

//----------------------------------------------------------------
// References in C++
// https://www.geeksforgeeks.org/references-in-c/
//----------------------------------------------------------------

/**
 * @brief Enum for the breed of the dog
 *
 */
enum Breed
{
    LABRADOR,
    DACHSHUND,
    MOPS
};

class Dog
{
    char *name;
    size_t legs;
    Breed breed;

public:
    /**
     * @brief Construct a new Dog object
     *
     * @param name
     * @param legs
     * @param breed
     */
    Dog(const char *name, const size_t legs, const Breed breed)
    {
        if (name) // name === nullptr
        {
            this->name = strdup(name);
        }
        else
        {
            this->name = strdup("");
        }

        if (legs > 0 && legs <= 4)
        {
            this->legs = legs;
        }
        else
        {
            this->legs = 4;
        }
        this->breed = breed;
    }

    ~Dog()
    {
        delete[] this->name;
    }

    /**
     * @brief Copy constructor
     *
     * @param other
     */
    Dog(const Dog &other)
    {
        cout << "Hello from copy constructor. " << endl;

        this->name = strdup(other.name);
        this->breed = other.breed;
        this->legs = other.legs;
    }

    /**
     * @brief Move constructor
     *
     * @param other
     */
    Dog(const Dog &&other)
    {
        this->name = strdup(other.name);
        delete[] other.name;

        this->breed = other.breed;
        this->legs = other.legs;
    }

    Dog &operator=(const Dog &other)
    {
        if (this != &other) // Validates if the copied object is not the same as the original
        {
            delete[] this->name;
            this->name = strdup(other.name);
            this->breed = other.breed;
            this->legs = other.legs;
        }
        return *this;
    }
};

int main()
{

    Dog dog1("Max", 4, Breed::MOPS); // Constructor with parameters

    Dog dog2(dog1); // Copy constructor

    Dog dog3 = dog2; // Copy constructor

    dog3 = dog1; // Assign operator

    Dog dog4 = test(dog2);

    return 0;
}

// Example for move constructor
Dog &test(Dog &dog)
{
    Dog dog1 = dog;

    // DO smth

    return dog1;
}