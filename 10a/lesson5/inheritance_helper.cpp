#include <iostream>

using namespace std;

class Base
{

protected:
public:
    Base()
    {
        cout << "Base class default constructor called." << endl;
    }

    ~Base()
    {
        cout << "Base class destructor called." << endl;
    }

    Base(const Base &other)
    {
        cout << "Base class copy constructor called." << endl;
    }

    Base &operator=(const Base &other)
    {
        cout << "Base class assign operator= called." << endl;
        return *this;
    }
    void print()
    {
        cout << "Base class print method called." << endl;
    }

    void printOnlyBase()
    {
        cout << "Base class print only base method called." << endl;
    }
};

class Child : public Base
{
protected:
public:
    Child()
        : Base()
    {
        cout << "Child class default constructor called." << endl;
    }

    ~Child()
    {
        cout << "Child class default destructor called." << endl;
    }

    Child(const Child &other)
        : Base(other)
    {
        cout << "Child class copy constructor called." << endl;
    }

    Child &operator=(const Child &other)
    {
        if (this != &other)
        {
            Base::operator=(other);
            cout << "Child class copy assignment operator= called." << endl;
        }
        return *this;
    }
    void print()
    {
        cout << "Child class print method called." << endl;
    }
};

int main()
{
    /*
    Child *c = new Child();
    delete c;
    */

    /*
     Child c2;
     Child *c3 = new Child(c2);
     delete c3;
     */

    /*
    Child c4, c5;
    c4 = c5;
    */

    /*
     Child c6;
     c6.print();
     c6.printOnlyBase();
     */
}