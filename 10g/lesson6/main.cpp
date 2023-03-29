#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    virtual void printHelloWorld() = 0;
    void print()
    {
        printHelloWorld();
        cout << "Hello from A" << endl;
    }
};

class B : public A
{
public:
    void printHelloWorld()
    {
        cout << "Hello world from B" << endl;
    }
};

class C : public A
{
public:
    void printHelloWorld()
    {
        cout << "Hello world from C" << endl;
    }
};

int main()
{
    B inst;
    // inst.printHelloWorld();
    inst.print();

    vector<A *> a;
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            a.push_back(new B());
        }
        else
        {
            a.push_back(new C());
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << typeid(*a[i]).name() << endl;
        a[i]->printHelloWorld();
    }
}