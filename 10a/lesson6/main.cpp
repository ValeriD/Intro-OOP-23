#include <iostream>
#include <vector>

using namespace std;

class A
{
public:
    virtual void printHello()
    {
        cout << "Hello world!" << endl;
    }
    virtual void printGoodbye() = 0;
};

class B : public A
{
    void printGoodbye()
    {
        cout << "Goodbye from B" << endl;
    }
};

class C : public A
{
    void printGoodbye()
    {
        cout << "Goodbye from C" << endl;
    }
};

int main()
{
    B b;
    b.printHello();
    vector<A *> arr;
    cout << typeid(b).name() << endl;
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
        {
            arr.push_back(new B());
        }
        else
        {
            arr.push_back(new C());
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << typeid(*arr[i]).name() << endl;
        arr[i]->printGoodbye();
    }

    return 0;
}