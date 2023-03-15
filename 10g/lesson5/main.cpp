#include <iostream>

using namespace std;

class Person
{
private:
    double age;
    int height;

protected:
    string name;

    string address;

public:
    Person(double age, int height)
        : age(age), height(height)
    {
        if (age < 1)
        {
            throw invalid_argument("Invalid age provided");
        }
        if (height < 50 || height > 165)
        {
            throw invalid_argument("Invalid height provided");
        }
    }

    Person(const Person &other)
        : age(other.age), height(other.height)
    {
    }

    Person &operator=(const Person &other)
    {
        if (this != &other)
        {
            this->age = other.age;
            this->height = other.height;
        }
        return *this;
    }

    double getAge() const
    {
        return this->age;
    }

    int getHeight() const
    {
        return this->height;
    }

    double ratioAgeHeight() const
    {
        return age / height;
    }
};

class Student : public Person
{
    int numberInClass;

public:
    Student(int age, int height, const string &name, const string &address, int numberInClass)
        : Person(age, height)
    {
        this->address = address;
        this->name = name;
        this->numberInClass = numberInClass;
    }

    Student(const Student &other)
        : Person(other)
    {
        this->name = other.name;
        this->address = other.address;
        this->numberInClass = other.numberInClass;
    }

    Student &operator=(const Student &other)
    {
        if (this != &other)
        {
            Person::operator=(other);
            this->name = other.name;
            this->address = other.address;
            this->numberInClass = other.numberInClass;
        }
        return *this;
    }
    double ratioAgeHeight() const
    {
        return Person::ratioAgeHeight() * numberInClass;
    }
};

int main()
{
    Student s(16, 160, "Ivan", "Gorno nanadolnishte", 10);
    cout << s.ratioAgeHeight() << endl;
    return 0;
    s = s;
}