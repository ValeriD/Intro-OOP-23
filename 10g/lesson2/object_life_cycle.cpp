#include <iostream>
// 16 nomer
using namespace std;
//============================================================================
// Some of the types in C++:
// -----------------------------------------------------
// size_t === unsigned int
// unsigend int n>=0 (=0,1,2,3,4,5... )
// signed int n <= 0 && n >=0
// short int
// long int
// float vs double (64-bit) double is more precise
// char - the same as in C
// struct - same as in C
// string
// arr[-1] === last element of the array
//============================================================================

//============================================================================
// Types of writing names:
// -----------------------------------------------------
// Camel case sizeOld
// Kebab case size-old
// Snake case size_old
// Pascal cas SizeOld
//============================================================================

//============================================================================
// Something interesting to checkout:
// -----------------------------------------------------
// RAII (https://medium.com/swlh/what-is-raii-e016d00269f9)
//============================================================================
class Person
{
    string name;
    unsigned int age;
    unsigned int height; // height in cm

public: // Modificator
    Person()
    {
        cout << "Default constructor called" << endl;
        this->age = 20;
    }
    Person(string name, unsigned int age, unsigned int height)
        : name(name),
          age(age),
          height(height)
    {
        cout << this->name << endl;
    }
    ~Person()
    {
        cout << "Destructor called" << endl;
    }

    unsigned int getAge() const { return age; }
    string getName() const { return this->name; }

    void setHeight(unsigned int height)
    {
        if (height > 0)
            this->height = height;
    }

private:
protected:
};

int main()
{
    Person p1; // Default constructor
    cout << p1.getAge() << endl;

    Person *p2 = new Person(); // Default constructor
    delete p2;                 // Destructor

    Person *p3 = new Person[2]; // Default constructors
    delete[] p3;                // Destructors

    Person p4("Gosho", 22, 189); // Constructor with parameters
    p4.getName() = "Pesho";
    cout << p4.getName() << endl;
    return 0;
} // Destructors